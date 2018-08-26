#include<vector>
#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#define  INF 0x3fffffff 
using namespace std;
int n,k;
int e[205][205], weight[205], dis[205];
bool visit[205];
vector<int> pre[205], temppath, path;
map<string,int> m;
map<int,string> m2;
int cost = INF, costnum = INF, happiness = -1, avghappiness = -1, pathcnt = 0;
void dij(int root){
	dis[root] = 0;
	for(int i = 0; i < n; i++){
		int u = -1, minn = INF;
		for(int j = 0; j < n; j++){
			if(visit[j]== false && dis[j] < minn){
				u = j;
				minn = dis[j];
			}
		}
		if( u == -1)break;
		visit[u] = true;
		for(int v = 0; v < n; v++){
			if(e[u][v] != INF && visit[v] == false){
				if(dis[v] > dis[u]+e[u][v]){
					pre[v].clear();
					pre[v].push_back(u);
					dis[v] = dis[u] + e[u][v]; 
				}else if(dis[v] == dis[u]+e[u][v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
void dfs(int st){
	temppath.push_back(st);
	if(st == 0){
		int tempha = 0,tempavg = 0;
		int len = temppath.size();
		for(int i = 0; i < len - 1; i++){
			tempha += weight[temppath[i]];
		}
		tempavg = tempha/(len - 1);
		if(tempha > happiness){
			happiness = tempha;
			avghappiness = tempavg;
			path = temppath;
		}else if(tempha == happiness && tempavg > avghappiness){
			avghappiness = tempavg;
			path = temppath;
		}
		temppath.pop_back();
		pathcnt++;
		return;	
	}
	int lenth = pre[st].size();
	for(int i = 0; i < lenth; i++){
		dfs(pre[st][i]);
	}
	temppath.pop_back();
}
int main(){
	fill(e[0], e[0] + 205 * 205, INF);
	fill(visit, visit+205, false);
	fill(dis, dis+205, INF);
	string st;
	scanf("%d %d",&n,&k);
	cin>>st;
	m[st] = 0;
	m2[0] = st;
	for(int i = 1; i < n; i++){
		string temp;
		int wtemp;
		cin>>temp>>wtemp;
		m[temp] = i;
		m2[i] = temp;
		weight[i] = wtemp;
	}
	for(int i = 0; i < k; i++){
		string temp1, temp2;
		int ctemp;
		cin>>temp1>>temp2>>ctemp;
		e[m[temp1]][m[temp2]] = e[m[temp2]][m[temp1]] = ctemp;
	}
	dij(0);
	int root = m["ROM"];
	dfs(root);
	printf("%d %d %d %d\n",pathcnt,dis[root],happiness,avghappiness);
	int len = path.size();
	for(int i = len - 1; i > 0; i--){
		cout<<m2[path[i]]<<"->";
		
	}
/*	for(int i = 0; i < n; i++){
		cout<<m2[i]<<" "; 
	}*/
	cout<<"ROM";
}
