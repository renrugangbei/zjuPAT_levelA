#include<iostream>
#include<vector>
#include<algorithm>
#define inf 0x3fffffff
#define MAXN 510
using namespace std;
int map[MAXN][MAXN],dis[MAXN],numB[MAXN],maxB,numS,indexP,numR,minNeed=inf,minBack=inf;
bool visit[MAXN];
vector<int> pre[MAXN];
vector<int> path, temppath;
void dij(){
	for(int i = 0; i <= numS; i++){
		int u=-1,min=inf;
		for(int j = 0; j <= numS; j++){
			if(visit[j]==false&&dis[j]<min){
				u=j;
				min=dis[j];
			}
		}
		if(u==-1) break;
		visit[u]=true;
		for(int k=0;k <= numS; k++){
			if(visit[k]==false && map[u][k] != inf){
				if(dis[k] > dis[u]+map[u][k]){
					pre[k].clear();
					pre[k].push_back(u);
					dis[k]=dis[u]+map[u][k];
				}else if(dis[k] == dis[u]+map[u][k]){
					pre[k].push_back(u); 
				} 
			}
		}
	}
}
void dfs(int index){
	temppath.push_back(index);
	if(index == 0){
		int need = 0, back = 0, path_length = temppath.size();
		for(int i= path_length-1; i>=0;i--){
			int id = temppath[i];
			if(numB[id] > 0){
				back+=numB[id];
			}else{
				if(back>abs(numB[id])){
					back+=numB[id];
				}else{
					need = abs(back + numB[id]) ;
					back=0;
				}
			}
		}
		if(need<minNeed){
			path=temppath;
			minNeed = need;
			minBack = back;
		}else if(minNeed == need && back<minBack){
			minBack=back;
			path=temppath;
		}
		temppath.pop_back();
		return;
	}
	int length = pre[index].size();
	for(int i=0;i<length;i++){
		dfs(pre[index][i]);
	}
	temppath.pop_back(); 
}
int main(){
	fill(map[0],map[0]+MAXN*MAXN,inf);
	fill(dis,dis+MAXN,inf);
	fill(visit,visit+MAXN,false);
	cin>>maxB>>numS>>indexP>>numR;
	for(int i=1;i<=numS;i++){
		cin>>numB[i];
		numB[i] = numB[i]- maxB/2;
	}
	for(int i=0; i<numR; i++){
		int c1,c2,road;
		cin>>c1>>c2>>road;
		map[c1][c2]=map[c2][c1]=road; 
	}
	dis[0]=0;
	dij();
	dfs(indexP);
	printf("%d 0",minNeed);
	int i = path.size()-2;
	for(;i>=0;i--){
		printf("->%d",path[i]);
	}
	printf(" %d",minBack);
}
