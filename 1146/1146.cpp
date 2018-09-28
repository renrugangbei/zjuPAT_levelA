#include<vector>
#include<iostream>
#include<cstdio> 
using namespace std;
int main(){
	int m,n,k,flag = 0,in[1010];
	vector<int> v[1010];
	fill(in,in+1010,0);
	scanf("%d %d",&n,&m);
	for(int i = 0; i < m; i++){
		int t1,t2;
		scanf("%d %d",&t1,&t2);
		v[t1].push_back(t2);
		in[t2]++;
	}
	scanf("%d",&k);
	for(int i = 0; i < k; i++){
		int isTop = true;
		vector<int> tempin (in,in+n+1);
		int node;
		for(int j = 0; j < n; j++){
			scanf("%d",&node);
			if(tempin[node] != 0){
				isTop = false;
			}
			for(auto temp : v[node]) tempin[temp]--;
		}
		if(isTop == true)continue;
		if(flag == 1)printf(" ");
		printf("%d",i);
		flag = 1;
	}
}
