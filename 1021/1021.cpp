#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#define MAXN 10010
using namespace std;
int cnt, maxHeight;
bool visit[MAXN];
vector<vector<int>> e;
vector<int> temp;
set<int> ans;
void dfs(int root, int height){
	if(height > maxHeight){
		maxHeight = height;
		temp.clear();
		temp.push_back(root);
	}else if(height == maxHeight){
		temp.push_back(root);
	}
	visit[root] = true;
	for(int i = 0; i < e[root].size(); i++){
		if(visit[e[root][i]] == false){
			dfs(e[root][i],height+1);
		}
	}
}
int main(){
	int n,s1;
	scanf("%d",&n);
	e.resize(n+1); 
	for(int i = 0; i < n - 1 ; i++){
		int c1,c2;
		scanf("%d %d",&c1,&c2);
		e[c1].push_back(c2);
		e[c2].push_back(c1);
	}
	for(int i = 1; i <=n; i++){
		if(visit[i] == false){
			dfs(i,1);
			if(i == 1){
				if(temp.size()){
					s1 = temp[0];
					for(int j = 0; j < temp.size(); j++){
						ans.insert(temp[j]);
					}		
				}
			}
			cnt++;
		}
	}
	if(cnt >= 2){
		printf("Error: %d components",cnt);
	}else{
		temp.clear();
		fill(visit,visit+MAXN,false);
		maxHeight = 0;
		dfs(s1,1);
		for(int i = 0; i < temp.size();i++){
			ans.insert(temp[i]);
		}
		for(auto t : ans){
			printf("%d\n",t);
		}	
	}
} 
