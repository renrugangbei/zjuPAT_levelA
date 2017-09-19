#include<cstdio>
#include<iostream>
#include<algorithm> 
#define INF 0x3fffffff
#define MAXN 501 
using namespace std;
int e[MAXN][MAXN],dis[MAXN],team[MAXN]={0},teamsum[MAXN]={0};
int roadsum[MAXN]={0};
bool visit[MAXN]={false};
void dij(int st){
	fill(dis,dis+MAXN,INT_MAX);
	dis[st]=0;
	teamsum[st]=team[st];
	roadsum[st]=1;
	for(int i=0;i<MAXN;i++){
		int u=-1,min=INF;
		for(int j=0;j<MAXN;j++){
			if(visit[j]==false&&dis[j]<min){
				u=j;
				min=dis[j];
			}
		}
		if(u==-1)return;
		visit[u]=true;
		for(int k=0;k<MAXN;k++){
			if(visit[k]==false&&e[u][k]!=INF){
				if(dis[k]>dis[u]+e[k][u]){
					dis[k]=dis[u]+e[u][k];
					teamsum[k]=teamsum[u]+team[k];
					roadsum[k]=roadsum[u];
				}else if(dis[k]==dis[u]+e[k][u]){
					if(teamsum[k]<teamsum[u]+team[k]) {
						teamsum[k]=teamsum[u]+team[k];	
					}
					roadsum[k]+=roadsum[u];
				}
			}
		}
	}
}
int main(){
	int citynum,roadnum,c1,c2;
	scanf("%d %d %d %d",&citynum,&roadnum,&c1,&c2);
	for(int i=0;i<citynum;i++){
		int temp; 
		scanf("%d",&temp);
		team[i]=temp;
	}
	fill(e[0],e[0]+MAXN*MAXN,INF);
	for(int i=0;i<roadnum;i++){
		int citytemp1,citytemp2,roadtemp;
		scanf("%d %d %d",&citytemp1,&citytemp2,&roadtemp);
		e[citytemp1][citytemp2]=roadtemp;
		e[citytemp2][citytemp1]=roadtemp;
	}
	dij(c1);
	printf("%d %d",roadsum[c2],teamsum[c2]);
}
