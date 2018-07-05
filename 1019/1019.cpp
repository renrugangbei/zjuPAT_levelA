#include<iostream>
#include<vector>
using namespace std;
int main(){
	int a, b;
	cin>>a>>b;
	vector<int> ans;
	while(a != 0){
		ans.push_back(a % b);
		a = a / b;
	}
	bool flag = 1;
	int len = ans.size();
	for(int i = 0; i < len/2; i++){
		if(ans[i] != ans[len - i - 1]){
			cout<<"No"<<endl;
			flag = 0;
			break;
		}
	}
	if(flag){
		cout<<"Yes"<<endl;
	}
	for(int i = len - 1; i >= 1; i--){
		cout<<ans[i]<<" ";
	}
	cout<<ans[0];
} 
