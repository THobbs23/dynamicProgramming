//						Tyler Hobbs
//						Dynamic Programming: Rod Cutting
//						5 April 2018

#include<cstdlib>
#include<iostream>
#include<algorithm>		

using namespace std;

int memoizedRodCut(int *, int);
int memoizedRodCutter(int *, int, int *);
int bottomUpRodCut(int *, int);
//int extendedBottomUpRodCut(int prices, int length){
////	page 369
//
//	int rod[length];
//	int size[length];
//	int optimalSoln = -999;
//	
//	rod[0] = 0;
//	
//	for(int i = 1; i <= length; i++){
//		for(int j = 1; j <= i; j++){
//			if(optimalSoln < (prices[j] + rod[i-j])){
//				optimalSoln = (prices[j] + rod[i-j])
//				size[i] = j;
//			}
//		}
//		rod[i] = optimalSoln;
//	}	
////	return arrays rod and size
//}

//int greedyIterativeAlgorithm(){
//		page 419
//
//		
//}

int main(){
	
	int price[] = {0,1,5,8,9,10,17,17,20,24,30};
	int length = 0;
	int input = 1;
	
	while(input==1){
//		system("CLS");
		cout << "Input a rod length to find the highest price for: " ;
		cin >> length;
		
		cout << endl << endl << "Memoized Rod Cut: " << memoizedRodCut(price,length); 
		cout << endl << "Bottom-Up Rod Cut: " << bottomUpRodCut(price,length);
		
		cout << endl << endl << "Would you like to repeat for another length?";
		cout << endl << "1 for yes, anything else for no: ";
		cin >> input;
	}
	
	system("PAUSE");
	return 0;
}

int memoizedRodCut(int *prices, int length){

	int rod[11];
	
	for(int i=0; i < 11; i++){
		rod[i] = -999;
	}
	
	return memoizedRodCutter(prices, length, rod);	
}

int memoizedRodCutter(int *prices, int length, int *rod){
	
	int optimalSoln = -999;
	
	if(rod[length] >= 0)
		return rod[length];
		
	if(length == 0){
		optimalSoln = 0;
	}
	else{
		for(int i=1; i <= length; i++){
			optimalSoln = max(optimalSoln,(prices[i] + memoizedRodCutter(prices,length-i,rod)));
		}
	}
	
	rod[length] = optimalSoln;
	return optimalSoln;
}

int bottomUpRodCut(int *prices, int length){	
	
	int optimalSoln = -999;
	int rod[11];
	
	rod[0] = 0;
	
	for(int i = 1; i<= length; i++){
		for(int j = 1; j <= i; j++){
			optimalSoln = max(optimalSoln, (prices[j] + rod[i-j]));
		}
		rod[i] = optimalSoln;
	}
	return rod[length];
}
