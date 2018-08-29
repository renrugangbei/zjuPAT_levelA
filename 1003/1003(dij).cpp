#include<cstdio>
#include<algorithm> 
#include<iostream>
#define INF 0x3fffffff
#define MAXN 510
using namespace std;
int e[MAXN][MAXN],dis[MAXN],weight[MAXN],path[MAXN],teamcnt[MAXN];
bool visit[MAXN];
int n;
void dij(int root){
	dis[root] = 0;
	teamcnt[root] = weight[root];
	path[root] = 1;
	for(int i = 0; i < MAXN; i++){
		int u = -1, minn = INF;
		for(int j = 0; j < n; j++){
			if(visit[j]==false && dis[j] < minn){
				u = j;
				minn = dis[j];
			}
		}
		if(u == -1)break;
		visit[u]= true;
		for(int v = 0; v < MAXN; v++){
			if(visit[v]==false && e[u][v] !=INF){
				if(dis[v] > dis[u]+ e[u][v]){
					dis[v] = dis[u]+e[u][v];
					teamcnt[v] = teamcnt[u] + weight[v];
					path[v] = path[u];
				}else if(dis[v] == dis[u]+e[u][v]){
					path[v] = path[u] + path[v];
					if(teamcnt[v] < teamcnt[u] + weight[v]){
						teamcnt[v] = teamcnt[u]+weight[v];
					} 
				}
			}
		}
	}
}
int main(){
	int roadnum,st,ed;
	fill(path,path+MAXN,0);
	fill(e[0],e[0]+MAXN*MAXN,INF);
	fill(dis,dis+MAXN,INF);
	fill(teamcnt,teamcnt+MAXN,0);
	fill(visit,visit+MAXN,false);
	fill(weight,weight+MAXN,0);
	scanf("%d %d %d %d",&n,&roadnum,&st,&ed);
	for(int i = 0; i< n; i++){
		scanf("%d",&weight[i]);
	}
	for(int i = 0; i < roadsum;i++){
		int c1,c2,cost;
		scanf("%d %d %d",&c1,&c2,&cost);
		e[c1][c2] = e[c2][c1] = cost;
	} 
	dij(st);
	printf("%d %d",path[ed],teamcnt[ed]);
	return 0;
}
