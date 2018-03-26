#include<iostream>
#include<vector>
using namespace std;
int main(){
	int dnum,num;
	cin>>dnum>>num;
	vector<int> ans, temp;
	ans.push_back(dnum);
	for(int i=0; i < num-1; i++){
		int pre = ans[0], cnt = 1;
		int length = ans.size();
		for(int j=1;j<length;j++){
			if(ans[j] != pre){
				temp.push_back(pre);
				temp.push_back(cnt);
				pre = ans[j];
				cnt = 1;
			}else{
				cnt++;
			}
		}
		temp.push_back(pre);
		temp.push_back(cnt);
		ans=temp;
		temp.clear();
	}
	for(auto s:ans){
		cout<<s;
	}
} 

