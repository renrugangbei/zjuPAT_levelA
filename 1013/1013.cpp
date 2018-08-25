#include<vector>
#include<cstdio>
#include<iostream>
using namespace std;
int map[1010][1010];
bool visit[1010];
int n;
void dfs(int root){
	visit[root] = true;
	for(int i = 1; i <= n; i++){
		if(map[root][i] == 1 && visit[i] == false){
			dfs(i);
		}
	}
}
int main(){
	int m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i = 0; i < m; i++){
		int c1,c2;
		scanf("%d %d",&c1,&c2);
		map[c1][c2] = map[c2][c1] = 1;
	}
	for(int i = 0; i < k; i++){
		fill(visit,visit+1010,false);
		int oc;
		scanf("%d",&oc);
		visit[oc] = true;
		int cnt = 0;
		for(int j = 1; j <= n; j++){
			if(visit[j]==false){
				dfs(j);
				cnt++;
			}
		}
		printf("%d\n",cnt-1);
	}
}
