#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>
#include<iostream>
using namespace std;
struct school{
	string name;
	int tws,ns;
	int rank;
};
bool cmp(school a, school b){
	if(a.tws != b.tws){
		return a.tws > b.tws;
	}else if(a.ns != b.ns){
		return a.ns < b.ns;
	}else{
		return a.name < b.name;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	map<string,int> cnt;
	map<string, double> sum;
	vector<school> ans;
	for(int i = 0; i < n; i++){
		string id,name;
		int score;
		cin>>id;
		scanf("%d",&score);
		cin>>name;
		int len = name.length();
		for(int j = 0; j < len;j++){
			name[j] = tolower(name[j]);
		}
		if(id[0] == 'T'){
			sum[name] +=score*1.5;
		}else if(id[0] == 'B'){
			sum[name] += score/1.5;
		}else{
			sum[name] += score; 
		} 
		cnt[name]++;
	}
	for(auto s : sum){
		school temp;
		temp.name = s.first;
		temp.tws = s.second;
		temp.ns = cnt[temp.name];
		ans.push_back(temp);
	}
	sort(ans.begin(),ans.end(),cmp);
	int len = ans.size();
	ans[0].rank = 1; 
	for(int i = 1; i < len; i++){
		if(ans[i].tws == ans [i - 1].tws){
			ans[i].rank = ans[i - 1].rank;
		}else{
			ans[i].rank = i + 1;
		} 
	}
	printf("%d\n",len);
	for(int i = 0; i < len; i++){
		printf("%d ",ans[i].rank);
		cout<<ans[i].name;
		printf(" %d %d\n",ans[i].tws,ans[i].ns);
	}
} 
