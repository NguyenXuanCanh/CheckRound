#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int checkRound(int *arr[],int m,int n,int i,int j){
	int min=99999999;
        // Compare with previous element in row
            if (i - 1 >= 0)
            {
                if (abs(arr[i][j] - arr[i - 1][j])<min)
                    min=abs(arr[i][j] - arr[i - 1][j]);
            }
            // Compare with next element in row
            if (i + 1 < n)
            {
                if (abs(arr[i][j] - arr[i + 1][j])<min)
                    min=abs(arr[i][j] - arr[i + 1][j]);
            }
            // Compare with previous element in column
            if (j - 1 >= 0)
            {
                if (abs(arr[i][j] - arr[i][j - 1])<min)
                    min=abs(arr[i][j] - arr[i][j - 1]);
            }
            // Compare with next element in column
            if (j + 1 < m)
            {
                if (abs(arr[i][j] - arr[i][j + 1])<min)
                    min=abs(arr[i][j] - arr[i][j + 1]);
            }
            
            if(i-1>=0&& j-1>=0){
            	if(abs(arr[i][i]-arr[i-1][j-1])<min){
            	min=abs(arr[i][i]-arr[i-1][j-1]);
				}
			}
            
			if(i-1>=0&&j+1<m){
				if(abs(arr[i][i]-arr[i-1][j+1])<min){
            	min=abs(arr[i][i]-arr[i-1][j+1]);
			}
			}
			
			if(i+1<n&&j-1>=0){
				if(abs(arr[i][i]-arr[i+1][j-1])<min){
            	min=abs(arr[i][i]-arr[i+1][j-1]);
			}
			}
			
			if(i+1<n&&j+1<m){
				if(abs(arr[i][i]-arr[i+1][j+1])<min){
            	min=abs(arr[i][i]-arr[i+1][j+1]);
			}
			}
			
    return min;
}
void BTL(int *arr[],int m,int n,int e){
	for (int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			arr[i][j]=rand() % 100 + 1;
		}
	}
	for (int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	for (int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			//cout<<checkRound(arr,m,n,i,j);
			if(checkRound(arr,m,n,i,j)<e) cout<<"arr["<<i<<"]"<<"["<<j<<"]"<<" ";
		}
	}
}

int main(){
	int m=5,n=5;
	int *arr[n]; for(int i = 0; i < n; i++) { arr[i] = new int[m]; }
	int e=10;
	BTL(arr,m,n,e);
}

