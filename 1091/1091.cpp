#include<cstdio>
#include<queue>
#include<algorithm> 
#include<iostream> 
using namespace std;
struct node{
	int x,y,z;
};
int m,n,l,t;
bool visit[1300][130][65];
int img[1300][130][65];
int X[6] = {1,0,0,-1,0,0};
int Y[6] = {0,1,0,0,-1,0};
int Z[6] = {0,0,1,0,0,-1};
bool judge(int x, int y, int z){
	if(x < 0 || y < 0 || z < 0 || x > m - 1 || y > n - 1 || z > l - 1)return false;
	if(img[x][y][z] == 0 || visit[x][y][z] == true)return false;
	return true;
}
int bfs(int x, int y, int z){
	int cnt = 0;
	node temp;
	temp.x = x;
	temp.y = y;
	temp.z = z;
	queue<node> q;
	q.push(temp);
	visit[x][y][z] = true;
	while(!q.empty()){
		node top = q.front();
		q.pop();
		cnt++;
		for(int i = 0; i < 6; i++){
			int tx = top.x + X[i];
			int ty = top.y + Y[i];
			int tz = top.z + Z[i];
			if(judge(tx,ty,tz)){
				visit[tx][ty][tz] = true;
				temp.x = tx;
				temp.y = ty;
				temp.z = tz;
				q.push(temp);
			}
		}	
	}
	if(cnt >= t)
		return cnt;
	else
		return 0;
} 
int main(){
	fill((bool*)visit, (bool*)visit+1300*130*65, false);
	scanf("%d %d %d %d",&m,&n,&l,&t);
	for(int i = 0; i < l; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < n; k++){
				scanf("%d",&img[j][k][i]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i< l; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < n; k++){
				if(img[j][k][i] == 1 && visit[j][k][i] == false){
					ans += bfs(j,k,i);
				}
			}
		}
	}
	printf("%d",ans); 
} 
