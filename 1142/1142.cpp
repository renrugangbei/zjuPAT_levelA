#include<cstdio>
#include<vector>
using namespace std;
int e[210][210];
int main(){
	int ne, nv;
	scanf("%d %d",&nv,&ne);
	for(int i = 0; i < ne; i++){
		int v1, v2;
		scanf("%d %d",&v1,&v2);
		e[v1][v2] = e[v2][v1] = 1;
	}
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		int len;
		bool visit[210];
		fill(visit,visit+210,false);
		bool isclique = true,isMaxClique = true;
		scanf("%d",&len);
		vector<int> v(len);
		for(int j = 0; j < len; j++){
			scanf("%d",&v[j]);
			visit[v[j]] = true;
		}
		for(int j = 0; j < len; j++){
			if(isclique == false) break;
			for(int k = j + 1; k < len; k++){
				if(e[v[j]][v[k]] == 0){
					isclique = false;
					printf("Not a Clique\n");
					break;
				}
			}
		}
		if(isclique == false) continue;
		for(int j = 1; j <= nv; j++){
			if(visit[j] == 0){
				for(int k = 0; k < len; k++){
					if(e[j][v[k]] == 0){
						break;
					}
					if(k == len - 1) isMaxClique = false;
				}
			}
			if(isMaxClique == false) {
				printf("Not Maximal\n");
				break;
			}
		}
		if(isMaxClique == true){
			printf("Yes\n");
		} 	
	}
	return 0;
}
