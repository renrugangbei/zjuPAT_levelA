#include<cstdio>
#include<vector>
#include<queue> 
using namespace std;
struct node{
	int value;
	node *rchild,*lchild; 
	int depth;
};
vector<int> inOrder,postOrder;
vector<int> result[30];
node* buildTree(int inLeft,int inRight,int postLeft,int postRight,int dept){
	if(inLeft>inRight) return NULL;
	node *root=new node;
	root->value=postOrder[postRight];
	root->depth=dept;
	int i=0;
	while(inOrder[i]!=postOrder[postRight])i++;
	root->lchild=buildTree(inLeft,i-1,postLeft,postLeft+i-inLeft-1,dept+1);
	root->rchild=buildTree(i+1,inRight,postLeft+i-inLeft,postRight-1,dept+1); 
	return root;
}
void bfs(node *root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node *temp=q.front();
		q.pop();
		result[temp->depth].push_back(temp->value);
		if(temp->lchild!=NULL)q.push(temp->lchild);
		if(temp->rchild!=NULL)q.push(temp->rchild);
	}
}
int main(){
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		int temp;
		scanf("%d",&temp);
		inOrder.push_back(temp);
	}
	for(int i=0;i<num;i++){
		int temp;
		scanf("%d",&temp);
		postOrder.push_back(temp);
	}
	node *root=buildTree(0,num-1,0,num-1,0);
	bfs(root);
	printf("%d",result[0][0]);

	for(int i=1;i<num;i++){
		if(i%2!=0){
			int k=result[i].size();
			for(int j=0;j<k;j++)
			printf(" %d",result[i][j]);
		}else {
			int k=result[i].size();
			for(int j=k-1;j>=0;j--)
			printf(" %d",result[i][j]);
		}
	}	
}
