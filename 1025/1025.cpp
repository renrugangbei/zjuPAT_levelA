#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
struct student{
	string id;
	int localid,localrank,totalrank,score;
};
bool cmp(student a,student b){
	if(a.score != b.score){
		return a.score > b.score;
	}else{
		return a.id<b.id;
	}
}
int main() {
	int lnum;
	cin>>lnum;
	vector<student> local[101];
	vector<student> ans;
	for(int i = 0; i < lnum; i++){
		int lsnum;
		cin>>lsnum;
		for(int j = 0; j <lsnum; j++){
			student temp;
			cin>>temp.id>>temp.score;
			temp.localid = i + 1;
			local[i].push_back(temp);
		}
		sort(local[i].begin(),local[i].end(),cmp);
		local[i][0].localrank = 1;
		ans.push_back(local[i][0]);
		for(int j = 1; j < lsnum; j++){
			if(local[i][j].score == local[i][j-1].score){
				local[i][j].localrank = local[i][j - 1].localrank;
			}else{
				local[i][j].localrank = j + 1;
			}
			ans.push_back(local[i][j]);
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	int len = ans.size();
	ans[0].totalrank = 1;
	for(int i = 1; i < len; i++){
		if(ans[i].score == ans[i - 1].score){
			ans[i].totalrank = ans[i - 1].totalrank;
		}else{
			ans[i].totalrank = i+1;
		}
	}
	cout<<len<<endl;
	for(auto s : ans){
		cout<<s.id<<" "<<s.totalrank<<" "<<s.localid<<" "<<s.localrank<<endl; 
	} 
}
