#include<iostream>
#include<vector>
#include<cstdio>
#define INF 0x3fffffff
#define MAXV 501
using namespace std;
int g[MAXV][MAXV],cost[MAXV][MAXV],dis[MAXV],mincost=INF;
vector<int> pre[MAXV];
bool visit[MAXV]={false};
vector<int> path,temppath;
void dijstra(int st){
	fill(dis,dis+MAXV,INF);
	dis[st]=0;
	for(int i=0;i<MAXV;i++){
		int u=-1,min=INF;
		for(int j=0;j<MAXV;j++){
			if(dis[j]<min&&visit[j]==false){
				min=dis[j];
				u=j;
			}
		}
		if(u==-1)return;
		visit[u]=true;
		for(int k=0;k<MAXV;k++){
			if(visit[k]==false&&g[u][k]!=INF){
				if(dis[k]>dis[u]+g[u][k]){
					pre[k].clear();
					pre[k].push_back(u);
					dis[k]=dis[u]+g[u][k];
				}else if(dis[k]==dis[u]+g[u][k]){
					pre[k].push_back(u);
				}
			}
		}
	}
}
void dfs(int st,int ed){
	//st 为路径起点，end为递归起点；
	temppath.push_back(ed);
	if(ed==st){
		
		int tempcost=0;
		for(int i=temppath.size()-1;i>0;i--){//注意i的范围，因为size()的返回结果比下标大一。注意是>0因为下面访问数组要-1.
			tempcost+=cost[temppath[i-1]][temppath[i]];
		}
		if(tempcost<mincost){
			mincost=tempcost;
			path=temppath;
		}
		temppath.pop_back();
		return;	
	}
	//temppath.push_back(ed);
	for(int i=0;i<=pre[ed].size()-1;i++){//注意i的范围，因为size()的返回结果比下标大一。
		dfs(st,pre[ed][i]);
	} 
	temppath.pop_back();	 
}
int main(){
	fill(g[0],g[0]+MAXV*MAXV,INF);
	fill(cost[0],cost[0]+MAXV*MAXV,INF);
	int citynum,roadnum,st,end;
	scanf("%d %d %d %d",&citynum,&roadnum,&st,&end);
	for(int i=0;i<roadnum;i++){
		int city1,city2,tempdis,tempcost;
		scanf("%d %d %d %d",&city1,&city2,&tempdis,&tempcost);
		g[city1][city2]=tempdis;
		g[city2][city1]=tempdis;
		cost[city1][city2]=tempcost;
		cost[city2][city1]=tempcost;
	}
	dijstra(st); 
	dfs(st,end);
	for(int i=path.size()-1;i>=0;i--){
		printf("%d ",path[i]);
	}
	printf("%d %d",dis[end],mincost); 
}
