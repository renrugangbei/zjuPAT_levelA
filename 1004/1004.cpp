#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[100];//v存放树，每一个父节点链接所有他的子节点，节点从1开始，按顺序编址
int level[100], cnt[100], levelcnt = -1;//level 存储每个节点的层数，cnt存储每层有几个叶子节点，levelcnt存储有几层 
void bfs() {
	queue<int> q;
	q.push(1);
	level[1] = 0;
	while (!q.empty()) {
		int m = q.front();
		q.pop();
		levelcnt = max(level[m], levelcnt);
		if (v[m].size() == 0) {
			cnt[level[m]]++;//v[m].size()==0代表这个节点没有子节点
		}
		for (int i = 0; i < v[m].size(); i++) {
			q.push(v[m][i]);//将下一层全部入队，做宽度优先遍历
			level[v[m][i]] = level[m] + 1;//儿子的层数比父亲大一
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b,c;
		cin >> a>>b;
		for (int j = 0; j < b; j++) {
			cin >> c;
			v[a].push_back(c);
		}
	}
	bfs();
	cout << cnt[0];
	for (int i = 1; i <= levelcnt; i++) {
		cout << " " << cnt[i];
	}
}