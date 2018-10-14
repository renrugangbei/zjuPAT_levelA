#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
map<string,vector<int>> trans;
int main(){
	int n,k;
	scanf("%d %d",&n, &k);
	for(int i = 0; i < k; i++){
		int index, num;
		scanf("%d %d",&index, &num);
		string name;
		for(int j = 0; j < num; j++){
			cin>>name;
			trans[name].push_back(index);
		}
	}
	for(int i = 0; i < n; i++){
		string name;
		cin>>name;
		int len = trans[name].size();
		cout<<name<<" "<<len;
		sort(trans[name].begin(),trans[name].end());
		for(int j = 0; j < len; j++){
			printf(" %d",trans[name][j]);
		}
		printf("\n");
	}
}
 
