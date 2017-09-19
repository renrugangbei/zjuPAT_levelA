#include<vector>
#include<cstdio>
using namespace std;
#define MAXV 501
bool visit[MAXV];
vector<int> v[MAXV];
int cnt=0;
void DFS(int index){
	visit[index]=true;
	cnt++;
	int n=v[index].size();
	for(int i=0;i<n;i--){
		if(visit[v[index][i]]==false)
		DFS(v[index][i]);
	}
}
int main(){
	int n,m,a,b,even=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(i!=1)printf(" ");
		printf("%d",v[i].size());
		if(v[i].size()%2==0)even++;
	}
	printf("\n");
	if(even==n&&cnt==n)
		printf("Eulerian");
	else if(even==(n-2)&&cnt==n)
		printf("Semi-Eulerian");
	else 
		printf("Non-Eulerian");
}

