#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX 2001
using namespace std;
int main(){
	double ans[MAX],p1[MAX];
	fill(ans,ans+MAX,0);
	fill(p1,p1+MAX,0);
	int num,cnt = 0;
	cin>>num;
	for(int i = 0; i < num; i++){
		int tempexp;
		cin>>tempexp;
		cin>>p1[tempexp];
	}
	cin>>num;
	for(int i = 0; i < num; i++){
		int tempexp;
		double tempcol;
		cin>>tempexp>>tempcol;
		for(int j = 0; j < MAX; j++){
			ans[tempexp + j] = tempcol * p1[j] + ans[tempexp + j];
		}
	}
	for(int i = 0; i<MAX; i++){
		if(ans[i] != 0){
			cnt++;
		}
	}
	cout<<cnt;
	if(cnt == 0){
		cout<<" "<<0;
	}else{
		for(int i = MAX - 1; i >= 0; i--){
			if(ans[i] != 0){
				printf(" %d %.1f",i,ans[i]);
			}
		}
	}	
}
