#include<cstdio>
#include<iostream>
#include<vector>
#define INF 0xfffffff
#define MAXN 510
using namespace std;
int e[MAXN][MAXN],cost[MAXN][MAXN],dis[MAXN],minDis = INF, minCost = INF, start, ed;
vector<int> pre[MAXN], temppath,path;
bool visit[MAXN];
void dij(int st){
	dis[st] = 0;
	for(int i = 0; i < MAXN; i++){
		int u = -1,min = INF;
		for(int j = 0; j < MAXN; j++){
			if(dis[j] < min && visit [j] == false){
				u = j;
				min = dis[j];
			}
		}
		if(u == -1)return;
		visit[u] = true;
		for(int v = 0; v < MAXN; v++){
			if(e[u][v] != INF && visit[v] == false){
				if(dis[v] > e[u][v] + dis[u]){
					pre[v].clear();
					pre[v].push_back(u);
					dis[v] = e[u][v] + dis[u];
				}else if(dis[v] == e[u][v] + dis[u]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
void dfs(int index){
	temppath.push_back(index);
	if(index == start){
		int len = temppath.size();
		int dis = 0,costt = 0;
		for(int i = 0; i < len - 1; i++){
			costt += cost[temppath[i]][temppath[i + 1]];
		}
		if(costt < minCost){
			minCost = costt;
			path = temppath;
		}
		temppath.pop_back();
		return;
	}
	int len = pre[index].size();
	for(int i = 0; i < len; i++){
		dfs(pre[index][i]);
	}
	temppath.pop_back();
	return;
}
int main(){
	fill(dis,dis+MAXN,INF);
	fill(e[0],e[0]+MAXN*MAXN,INF);
	fill(visit,visit+MAXN,false);
	int n,m;
	scanf("%d %d %d %d",&n,&m,&start,&ed);
	for(int i = 0; i < m; i++){
		int c1,c2, td, tc;
		scanf("%d %d %d %d",&c1,&c2,&td,&tc);
		e[c1][c2] = e[c2][c1] = td;
		cost[c1][c2] = cost[c2][c1] = tc;  
	}
	dij(start);
	dfs(ed);
	for(int i = path.size() - 1; i >= 0; i--){
		printf("%d ", path[i]);
	}
	printf("%d %d",dis[ed],minCost);
} 
