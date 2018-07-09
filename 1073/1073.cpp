#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	cin>>s;
	if(s[0] == '-'){
		cout<<"-";
	}
	int pos;
	int len = s.length();
	for(int i = 0; i<len ; i++){
		if(s[i]=='E'){
			pos = i;
		}
	}
	int times = 0;
	for(int i = pos + 2; i < len; i++){
		times = (s[i] - '0')+ times*10;
	}
	if(s[pos + 1] == '-'){
		cout<<"0.";
		for(int i = 1;i<times;i++){
			cout<<"0";
		}
		for(int i = 0; i<pos; i++){
			if(isdigit(s[i])){
				cout<<s[i];
			}
		}
	}else{
		if(times > pos - 3){
			for(int i = 0; i < pos; i++){
				if(isdigit(s[i])){
					cout<<s[i];
				}
			}
			for(int i = 0; i < times-pos+3; i++){
				cout<<"0";
			}
		}else{
			for(int i = 0; i< pos; i++){
				if(i == 3+times){
					cout<<".";
				}
				if(isdigit(s[i])){
					cout<<s[i];
				}
			}
		}
	}
}

