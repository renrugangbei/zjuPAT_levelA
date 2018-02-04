#include<vector>
#include<cstdio>
#include<iostream>
using namespace std;
int main() {
	int vnum, en;
	scanf("%d %d", &vnum, &en);
	vector<int> g[10000];
	for (int i = 0; i<en; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].push_back(i);
		g[b].push_back(i);
	}
	int snum;
	scanf("%d", &snum);
	for (int i = 0; i<snum; i++) {
		vector<int> ans(en, 0);
		int flag = 0;
		int pnum;
		scanf("%d", &pnum);
		for (int j = 0; j<pnum; j++) {
			int p;
			scanf("%d", &p);
			int temp = g[p].size();
			for (int k = 0; k<temp; k++) {
				ans[g[p][k]] = 1;
			}		
	}
		for (int k = 0; k<en; k++) {
			if (ans[k] == 0) {
				printf("No\n");
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			printf("Yes\n");
	}
}
