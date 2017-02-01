#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[100];//v�������ÿһ�����ڵ��������������ӽڵ㣬�ڵ��1��ʼ����˳���ַ
int level[100], cnt[100], levelcnt = -1;//level �洢ÿ���ڵ�Ĳ�����cnt�洢ÿ���м���Ҷ�ӽڵ㣬levelcnt�洢�м��� 
void bfs() {
	queue<int> q;
	q.push(1);
	level[1] = 0;
	while (!q.empty()) {
		int m = q.front();
		q.pop();
		levelcnt = max(level[m], levelcnt);
		if (v[m].size() == 0) {
			cnt[level[m]]++;//v[m].size()==0��������ڵ�û���ӽڵ�
		}
		for (int i = 0; i < v[m].size(); i++) {
			q.push(v[m][i]);//����һ��ȫ����ӣ���������ȱ���
			level[v[m][i]] = level[m] + 1;//���ӵĲ����ȸ��״�һ
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