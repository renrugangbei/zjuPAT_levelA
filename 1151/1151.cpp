#include<vector>
#include<map>
#include<iostream>
using namespace std;
map<int,int>pos;
vector<int> pre,in;
void lca(int inl,int inr, int preRoot, int t1, int t2){
	if(inl > inr)return;
	int inRoot = pos[pre[preRoot]], t1In = pos[t1],t2In = pos[t2];
	if(t1In < inRoot && t2In < inRoot)
		lca(inl,inRoot - 1, preRoot + 1, t1, t2);
	else if((t1In < inRoot && t2In > inRoot) || (t1In > inRoot && t2In < inRoot))
		printf("LCA of %d and %d is %d.\n",t1,t2,in[inRoot]);
	else if(t1In > inRoot && t2In > inRoot)
		lca(inRoot + 1, inr,preRoot + inRoot - inl + 1,t1,t2);
	else if(t1In == inRoot)
		printf("%d is an ancestor of %d.\n", t1, t2);
	else if(t2In == inRoot)
		printf("%d is an ancestor of %d.\n", t2, t1);
}
int main(){
	int m, n, a, b;
	scanf("%d %d",&m,&n);
	in.resize(n + 1);
	pre.resize(n + 1);
	for(int i = 1; i < n + 1; i++){
		scanf("%d",&in[i]);
		pos[in[i]] = i;
	}
	for(int i = 1; i < n + 1; i++)scanf("%d",&pre[i]);
	for(int i = 0; i < m; i++){
		int t1,t2;
		scanf("%d %d",&t1,&t2);
		if(pos[t1] == 0 && pos[t2] == 0){
			printf("ERROR: %d and %d are not found.\n",t1,t2);
		}else if(pos[t1] == 0 || pos[t2] == 0){
			printf("ERROR: %d is not found.\n",pos[t1] == 0?t1:t2);
		}else{
			lca(1,n,1,t1,t2);
		}
	}
} 
