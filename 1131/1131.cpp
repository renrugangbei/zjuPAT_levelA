#include<cstdio>
#include<iostream>
#include<vector>
#define INF 0x3fffffff
using namespace std;
int line[10000][10000];
vector<int> v[10000];
int mincnt = INF, mintrans = INF;
vector<int> path, temppath;
bool visit[10000];
int transcnt(vector<int> pre) {
	int cnt = -1, preline = 0;
	int n = pre.size();
	for (int i = 0; i<n - 1; i++) {
		if (line[pre[i]][pre[i + 1]] != preline) {
			cnt++;
		}
		preline = line[pre[i]][pre[i + 1]];
	}
	return cnt;
}
void dfs(int st, int ed, int cnt) {
	//st为起点，ed为终点 
	visit[st] = true;
	temppath.push_back(st);
	if (st == ed) {
		if (cnt<mincnt) {
			path = temppath;
			mincnt = cnt;
			mintrans = transcnt(temppath);
		}
		else if (mincnt == cnt&&mintrans>transcnt(temppath)) {
			path = temppath;
			mintrans = transcnt(temppath);
		}
		temppath.pop_back();
		return;
	}
	int n = v[st].size();
	for (int i = 0; i<n; i++) {
		if (visit[v[st][i]] == false) {
			dfs(v[st][i], ed, cnt + 1);
			visit[v[st][i]] = false;
		}
	}
	temppath.pop_back();
}
int main() {
	int linenum;
	scanf("%d", &linenum);
	for (int i = 0; i<linenum; i++) {
		int stionnum, prestion;
		scanf("%d %d", &stionnum, &prestion);
		for (int j = 1; j<stionnum; j++) {
			int temp;
			scanf("%d", &temp);
			v[prestion].push_back(temp);
			v[temp].push_back(prestion);
			line[temp][prestion] = line[prestion][temp] = i + 1;
			prestion = temp;
		}
	}
	int testnum;
	scanf("%d", &testnum);
	for (int i = 0; i<testnum; i++) {
		mincnt=INF;
		int st, ed;
		scanf("%d %d", &st, &ed);
		temppath.clear();
		dfs(st, ed, 0);
		printf("%d\n", mincnt);
		int preline=0,pretransfer=st;
		int n=path.size();
		for(int i=0;i<n-1;i++){
			if(line[path[i]][path[i+1]]!=preline){
				if(preline!=0)
					printf("Take Line#%d from %04d to %04d.\n",preline,pretransfer,path[i]);
				preline=line[path[i]][path[i+1]];
				pretransfer=path[i];
			}
		}
		 printf("Take Line#%d from %04d to %04d.\n", preline, pretransfer, ed); 
	}
}/*
#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int>> v(10000);
int line[10000][10000], visit[10000];
vector<int> path, tempPath;
int transferCnt(vector<int> a) {
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i-1]][a[i]] != preLine) cnt++;
        preLine = line[a[i-1]][a[i]];
    }
    return cnt;
}
void dfs(int node, int end, int cnt, int &minCnt, int &minTransfer) {
    if (node == end && (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer))) {
        minCnt = cnt;
        minTransfer = transferCnt(tempPath);
        path = tempPath;
    }
    if (node == end) return;
    for (int i = 0; i < v[node].size(); i++) {
        if (visit[v[node][i]] == 0) {
            visit[v[node][i]] = 1;
            tempPath.push_back(v[node][i]);
            dfs(v[node][i], end, cnt + 1, minCnt, minTransfer);
            visit[v[node][i]] = 0;
            tempPath.pop_back();
        }
    }
}
int main() {
    int n, m, k, pre, temp, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &m, &pre);
        for (int j = 1; j < m; j++) {
            scanf("%d", &temp);
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre][temp] = line[temp][pre] = i + 1;
            pre = temp;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &a, &b);
        int minCnt = 99999, minTransfer = 99999;
        tempPath.clear();
        tempPath.push_back(a);
        visit[a] = 1;
        dfs(a, b, 0, minCnt, minTransfer);
        visit[a] = 0;
        printf("%d\n", minCnt);
        int preLine = 0, preTransfer = a;
        for (int j = 1; j < path.size(); j++) {
            if (line[path[j-1]][path[j]] != preLine) {
                if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);
                preLine = line[path[j-1]][path[j]];
                preTransfer = path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, b);
    }
    return 0;
}*/
