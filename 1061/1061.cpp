#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm> 
using namespace std;
int main(){
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	string week[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int len = min(s1.length(),s2.length());
	int i = 0;
	for(;i < len; i++){
		if(s1[i]==s2[i] && s1[i] >='A' &&s1[i] <='G'){
			cout<<week[s1[i]-'A']<<" ";
			break;
		}
	}
	for(i = i + 1;i<len;i++){
		if(s1[i] == s2[i] && s1[i]>='A' && s1[i]<= 'N'){
			printf("%02d",s1[i]-'A'+10);
		}
		if(s1[i] == s2[i] && isdigit(s1[i])){
			printf("%02d",s1[i]-'0');
			break;
		}
	}
	len = min(s3.length(),s4.length());
	for(int i = 0; i <len; i++){
		if(s3[i] == s4[i] && isalpha(s3[i])){
			printf(":%02d",i);
		}
		
	}
} 
