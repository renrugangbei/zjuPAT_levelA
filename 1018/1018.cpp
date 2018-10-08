#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define MAXN 510
#define INF 0x3fffffff
using namespace std;
int e[MAXN][MAXN], dis[MAXN], bike[MAXN], minSend = INF, minBack = INF; 
bool visit[MAXN];
vector<int> pre[MAXN],temppath,path;
void dij(){
	dis[0] = 0;
	for(int i = 0; i < MAXN; i++){
		int u = -1, min = INF;
		for(int j = 0; j < MAXN; j++){
			if(visit[j] == false && dis[j] < min){
				min = dis[j];
				u = j;
			}
		}
		if(u == -1)return;
		visit[u] = true;
		for(int j = 0; j < MAXN; j++){
			if(visit[j] == false && e[u][j] != INF){
				if(dis[j] > e[u][j] + dis[u]){
					pre[j].clear();
					pre[j].push_back(u);
					dis[j] = e[u][j]+dis[u];
				}else if(dis[j] == dis[u] + e[u][j]){
					pre[j].push_back(u);
				}
			}
		}
	}
}
void dfs(int st){
	temppath.push_back(st);
	if(st == 0){
		int send = 0, back = 0;
		int len = temppath.size();
		for(int i = len - 2; i >= 0; i--){
			int index = temppath[i];
			if(bike[index] > 0){
				back += bike[index];
			}else if((back + bike[index])> 0){
				back+=bike[index];
			}else{
				send += -(back + bike[index]);
				back = 0;
			}
		}
		if(send < minSend){
			path = temppath;
			minSend = send;
			minBack = back;
		}else if(send == minSend && back < minBack){
			path = temppath;
			minSend = send;
			minBack = back;
		}
		temppath.pop_back();
		return;
	}
	int size = pre[st].size();
	for(int i =0; i < size; i++){
		dfs(pre[st][i]);
	}
	temppath.pop_back();
}
int main(){
	int cmax,snum,rnum,sp;
	fill(e[0],e[0]+MAXN*MAXN,INF);
	fill(dis,dis+MAXN,INF);
	fill(visit,visit+MAXN,false);
	scanf("%d %d %d %d",&cmax,&snum,&sp,&rnum);
	for(int i = 1; i <= snum; i++){
		int temp;
		scanf("%d",&temp);
		bike[i] = temp - cmax/2;
	}
	for(int i = 0; i < rnum; i++){
		int t1, t2,t;
		scanf("%d %d %d",&t1,&t2,&t);
		e[t1][t2] = e[t2][t1] = t;
	}
	dij();
	dfs(sp);
	printf("%d 0",minSend);
	int len = path.size();
	for(int i = len - 2; i >= 0; i--){
		printf("->%d",path[i]);
	}
	printf(" %d",minBack);
} 
