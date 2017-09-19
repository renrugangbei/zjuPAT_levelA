#include<vector>
#include<map>
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main(){
	int num,skip,start;
	string str;
	map<string,bool> map;
	scanf("%d %d %d",&num,&skip,&start);
	if(num<start){
		cout<<"Keep going..."<<endl;
	}
	for(int i=1;i<=num;i++){
	
		cin>>str;
		
		if(map[str]==true)start=start+1;
		if(i==start&&map[str]==false){
			map[str]=true;
			cout<<str<<endl;
			start=start+skip;
			}
		}
		
}

