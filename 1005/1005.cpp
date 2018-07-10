#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	string mp[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	string num;
	cin>>num;
	int out = 0;
	int len = num.length();
	for(int i = 0; i < len; i++){
		out = out + num[i]-'0';
	}
	num = to_string(out);
	len = num.length();
	cout<<mp[(num[0]-'0')];
	for(int i = 1; i < len; i++){
		cout<<" "<<mp[(num[i]-'0')];
	} 
}
