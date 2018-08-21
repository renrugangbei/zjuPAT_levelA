#include<vector>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
	int left,right,val;
};
vector<node> tree;
vector<int> value,level;
int index = 0;
void inorder(int root){
	if(root == -1) return;
	inorder(tree[root].left);
	tree[root].val = value[index++];
	inorder(tree[root].right);
}
void bfs(int root){
	queue<node> q;
	q.push(tree[root]);
	while(!q.empty()){
		node temp = q.front();
		q.pop();
		level.push_back(temp.val);
		if(temp.left != -1){
			q.push(tree[temp.left]);
		}
		if(temp.right != -1){
			q.push(tree[temp.right]);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	tree.resize(n);
	value.resize(n);
	for(int i = 0; i < n; i++){
		scanf("%d %d",&tree[i].left,&tree[i].right); 
	}
	for(int i = 0; i < n; i++){
		scanf("%d",&value[i]);
	}
	sort(value.begin(),value.end());
	inorder(0);
	bfs(0);
	printf("%d",level[0]);
	for(int i = 1; i < n; i++){
		printf(" %d",level[i]);
	}
} 
