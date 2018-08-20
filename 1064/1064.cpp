#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
//假设leveorder为一棵BST，而inorder是该BST的中序遍历结果 所以对BST进行中序遍历，并在相应位置上置inorder的值 
vector<int> inorder,leveorder;
int index , n;
void levelorder(int root){
	if(root >= n) return;
	levelorder(root * 2 + 1);
	leveorder[root] = inorder[index++];
	levelorder(root * 2 + 2);
}
int main(){
	scanf("%d", &n);
	inorder.resize(n);
	leveorder.resize(n + 1);
	for(int i = 0 ; i < n; i++){
		scanf("%d",&inorder[i]);
	}
	sort(inorder.begin(),inorder.end());
	levelorder(0);
	printf("%d",leveorder[0]);
	for(int i = 1; i < n; i++){
		printf(" %d",leveorder[i]);
	}
} 
