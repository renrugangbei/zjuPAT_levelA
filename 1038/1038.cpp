#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(string a, string b){
	return a+b<b+a;
}
int main(){
	vector<string> v;
	int num;
	cin>> num;
	for(int i = 0; i < num; i++){
		string temp;
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end(),cmp);
	string ans;
	int len = v.size();
	for(int i = 0; i < len; i++){
		ans += v[i];
	}
	while(ans.length() != 0 && ans[0] == '0'){
		ans.erase(ans.begin());
	}
	if(ans.length() == 0){
		cout<<"0"<<endl;
	}else{
		cout<<ans<<endl;
	}
} 
