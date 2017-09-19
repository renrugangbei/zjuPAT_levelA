#include<iostream>
#include<vector>
#include<cstdio>
#define MAXV 501
#define INF 0x3fffffff
using namespace std;
int g[MAXV][MAXV],dis[MAXV],cost[MAXV][MAXV],costsum[MAXV]={INF},pre[MAXV];
bool visit[MAXV]={false};
void dijstra(int st){
	fill(dis,dis+MAXV,INF);
	fill(costsum,costsum+MAXV,INF);
	dis[st]=0;
	costsum[st]=0;
	for(int i=0;i<MAXV;i++){
		int u=-1,min=INF;
		for(int j=0;j<MAXV;j++){
			if(visit[j]==false&&dis[j]<min){
				u=j;
				min=dis[j]; 	
			}
		}
		if(u==-1) return;
		visit[u]=true;
		for(int k=0;k<MAXV;k++){
			if(visit[k]==false&&g[u][k]!=INF){
				if(dis[k]>dis[u]+g[u][k]){
					pre[k]=u;
					dis[k]=dis[u]+g[u][k];
					costsum[k]=costsum[u]+cost[u][k];
				}else if(dis[k]==dis[u]+g[u][k]){
					if(costsum[k]>costsum[u]+cost[u][k]){
						pre[k]=u;
						costsum[k]=costsum[u]+cost[u][k];
					}
				}
			}
		}
	}
}
void DFS(int v,int st){
	if(v==st){
		printf("%d ",v);
		return;
	}
	DFS(pre[v],st);
	printf("%d ",v);
} 
int main(){
	fill(g[0],g[0]+MAXV*MAXV,INF);
	fill(cost[0],cost[0]+MAXV*MAXV,INF);
	int citynum,roadnum,endcity,startcity;
	scanf("%d %d %d %d",&citynum,&roadnum,&startcity,&endcity);
	for(int i=0;i<roadnum;i++){
		int city1,city2,tempdis,tempcost;
		scanf("%d %d %d %d",&city1,&city2,&tempdis,&tempcost);
		g[city1][city2]=tempdis;
		g[city2][city1]=tempdis;
		cost[city1][city2]=tempcost;
		cost[city1][city2]=tempcost;
	}
	for(int i=0;i<MAXV;i++){
			pre[i]=i;
	}
	dijstra(startcity);
	DFS(endcity,startcity);
	printf("%d %d",dis[endcity],costsum[endcity]);
}

