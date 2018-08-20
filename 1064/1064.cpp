#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
//����leveorderΪһ��BST����inorder�Ǹ�BST������������ ���Զ�BST�������������������Ӧλ������inorder��ֵ 
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
