#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
struct node{
	int left,right;
};
vector<node> tree;
vector<int> level, in;
void invert(int troot){
	if(troot == -1)return;
	invert(tree[troot].left);
	invert(tree[troot].right);	
	swap(tree[troot].left,tree[troot].right);
}
void inorder(int node){
	if(node == -1) return;
	inorder(tree[node].left);
	in.push_back(node);
	inorder(tree[node].right);
}
void bfs(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int temp = q.front();
		if(tree[temp].left != -1){
			q.push(tree[temp].left);
		}
		if(tree[temp].right != -1){
			q.push(tree[temp].right); 
		}
		level.push_back(temp);
		q.pop();
	}
}
int main(){
	int num, troot;
	scanf("%d",&num);getchar();
	tree.resize(num);
	vector<int> root(num,0);
	for(int i = 0; i < num; i++){
		char t1,t2;
		node temp;
		scanf("%c %c",&t1,&t2);getchar();
		if(t1 == '-'){
			temp.left = -1;
		}else{
			temp.left = t1 - '0';
			root[temp.left] = 1;
		}
		if(t2 == '-'){
			temp.right = -1;
		}else{
			temp.right = t2 - '0';
			root[temp.right] = 1;
		}
		tree[i] = temp; 
	}
	for(int i = 0; i < num; i++){
		if(root[i] == 0){
			troot = i;
			break;	
		}
	}
	invert(troot);
	bfs(troot);
	printf("%d",level[0]);
	for(int i = 1; i < level.size(); i++){
		printf(" %d",level[i]);
	}
	printf("\n");
	inorder(troot);
	printf("%d",in[0]);
	for(int i = 1; i < in.size();i++){
		printf(" %d", in[i]);
	}
} 
