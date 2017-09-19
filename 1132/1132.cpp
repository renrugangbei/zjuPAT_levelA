#include<string>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<sstream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int length=s.size();
		string s1,s2;
		int n,n1,n2;
		s1.assign(s,0,length/2);
		s2.assign(s,length/2,length/2);
		istringstream temp;
		temp.str(s);
		temp>>n;
		temp.clear();
		temp.str(s1);
		temp>>n1;
		temp.clear();
		temp.str(s2);
		temp>>n2;
		temp.clear();
		if(n1*n2==0){
			cout<<"No"<<endl;
		}
		if(n%(n1*n2)==0){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
} 
