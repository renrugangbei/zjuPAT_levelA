#include<iostream>
#include<string>
using namespace std;
int main(){
	int a, b;
	cin>>a>>b;
	int ans = a+b;
	if(ans < 0){
		cout<<"-";
		ans = -ans;
	}
	int arr[8];
	int len = 0;
	if(ans == 0)arr[len++]=0;
	while(ans){
		arr[len++] = ans % 10;
		ans = ans / 10;
	}
	for(int i = len - 1; i>=0; i--){
		cout<<arr[i];
		if(i % 3 == 0 && i!=0){
			cout<<","; 
		}
	}
} 
