#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int n;
	int ans[100001];
	fill(ans,ans+100001,0);
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		int temp;
		scanf("%d",&temp);
		if(temp > 0 && temp < 100001){
			ans[temp]++;
		}
	}
	for(int i = 1; i < 100001; i++){
		if(ans[i] == 0){
			printf("%d",i);
			return 0;
 		}
	}
	printf("%d",n+1);
}

