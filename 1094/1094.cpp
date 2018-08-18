#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<vector<int>> tree;
vector<int> book;
/*vector<int> level;
void bfs(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int index = q.front();
		q.pop();
		book[level[index]]++;
		for(int i = 0; i < tree[index].size(); i++){
			level[tree[index][i]] = level[index] + 1;
			q.push(tree[index][i]);
		}
	}
}*/
void dfs(int root, int level){
	book[level]++;
	if(tree[root].size() == 0){
		return;
	}
	for(int i = 0; i < tree[root].size(); i++){
		dfs(tree[root][i],level + 1);
	}
}
int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	tree.resize(n + 1);
	//level.resize(n + 1);
	book.resize(n + 1);
	//level[1] = 1;
	for(int i = 0; i < m; i++){
		int childnum,index;
		scanf("%d %d",&index, &childnum);
		tree[index].resize(childnum);
		for(int j = 0; j < childnum; j++){
			scanf("%d",&tree[index][j]);
		}
	}
	//bfs(1);
	dfs(1,1);
	int maxnum = -1, maxindex;
	for(int i = 1; i < n + 1; i++){
		if(book[i] > maxnum){
			maxnum = book[i];
			maxindex = i;
		}
	}
	printf("%d %d",maxnum,maxindex);
}
