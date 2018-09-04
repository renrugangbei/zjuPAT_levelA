#include<vector>
#include<cstdio>
#include<map>
using namespace std;
map<int,bool> mp;
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	vector<int> tree(n);
	for(int i = 0; i < n; i++){
		scanf("%d",&tree[i]);
		mp[tree[i]] = true;
	}
	for(int i = 0; i < m; i++){
		int u,v,ans;
		scanf("%d %d",&u,&v);
		for(int j = 1; j < n; j++){
			ans = tree[j];
			if(ans >=u && ans <=v || ans <=u && ans>=v)break;
		}
		if(mp[u]==false && mp[v]==false){
			printf("ERROR: %d and %d are not found.\n",u,v);
		}else if(mp[u]==false || mp[v]==false){
			printf("ERROR: %d is not found.\n",(mp[u])?v:u);
		}else if(ans ==u||ans ==v){
			printf("%d is an ancestor of %d.\n",ans,ans==v?u:v);
		}else{
			printf("LCA of %d and %d is %d.\n", u,v,ans);
		}
	} 
} 
