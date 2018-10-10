#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int cnt;
	string s, ans;
	cin>>s>>cnt;
	for(int i = 0; i < cnt; i++){
		int len = s.length();
		ans = s;
		reverse(ans.begin(),ans.end());
		if(s == ans){
			cout<<s<<endl;
			cout<<i;
			return 0;
		}
		int carry = 0;
		for(int j = len - 1; j>=0; j--){
			int temp = ans[j]-'0' + s[j] - '0' + carry;
			carry = 0;
			if(temp >= 10){
				temp = temp - 10;
				carry = 1;
			}
			ans[j] = temp + '0';
		}
		if(carry == 1){
			ans = "1"+ans;
		}
		s = ans;
	}
	cout<<s<<endl;
	cout<<cnt;
} 
