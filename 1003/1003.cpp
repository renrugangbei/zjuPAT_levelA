#include<iostream>
#include<climits>
using namespace std;
#define MAXN 510
bool visited[MAXN];
int teams[MAXN], city[MAXN][MAXN];
int roadcnt = 0, teamcnt = 0;
int minDistance=INT_MAX;
int cityNum, roadNum;
void dfs(int start, int end, int team, int dist) {
	visited[start] = true;
	if (start == end) {
		if (minDistance > dist) {
			roadcnt = 1;
			teamcnt = team;
			minDistance = dist;
		} else if (minDistance==dist) {
			roadcnt++;
			if (teamcnt<team) {
				teamcnt = team;
			}
		}
		return;
	}
	for (int i = 0; i < cityNum; i++) {
		if (!visited[i] && city[start][i] != INT_MAX) {
			dfs(i, end, team + teams[i], dist + city[start][i]);
			visited[i] = false;
		}
	}
}
int main() {
	int  start, end;
	cin >> cityNum >> roadNum >> start >> end;
	for (int i = 0; i < cityNum; i++) {
		visited[i] = false;
		for (int j = 0; j < cityNum; j++) {
			city[i][j] = INT_MAX;
		}
	}
	for (int i = 0; i < cityNum; i++) {
		cin >> teams[i];
	}
	for (int i = 0; i < roadNum; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		city[a][b] = c;
		city[b][a] = c;
	}
	dfs(start, end, teams[start], 0);
	cout << roadcnt << " " << teamcnt;
}