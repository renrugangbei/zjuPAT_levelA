#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int mian(){
	int n,m;
	scanf("%d %d",&n,&m);
	string s = to_string(n);
	for(int cnt = 1; cnt < m; cmt++){
		string t;
		int j = 0;
		for(int i = 0; i < s.length(),i++){
			for(j = i; j < s.length() &&s[j] == s[i]; j++);
			t = to_string(s[i]-'0') + to_string(j-i);
		}
		s = t;	
	}
	cout<<s;
} 
