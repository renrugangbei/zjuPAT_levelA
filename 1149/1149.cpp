#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	map<int,vector<int>> in;
	for(int i = 0; i < n; i++){
		int temp1, temp2;
		scanf("%d %d",&temp1,&temp2);
		in[temp1].push_back(temp2);
		in[temp2].push_back(temp1);
	}
	for(int i = 0; i < m; i++){
		int num, good,a[100000];
		fill(a,a+100000,0);
		bool flag = false;
		scanf("%d",&num);
		vector<int> v(num);
		for(int j = 0; j < num; j ++){
			int temp;
			scanf("%d",&v[j]);
			a[v[j]] = 1;
		}
	for(int j = 0; j < num; j++){
		for(int k = 0; k < in[v[j]].size(); k++){
			if(a[in[v[j]][k]] == 1)
				flag = 1;
		}
	}
		printf("%s\n",flag?"No":"Yes");
	} 
}
