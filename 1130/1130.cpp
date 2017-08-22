#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct node{
	string value;
	int left,right;
};
vector<node> v;
int root=1;
string dfs(int index){
	if(index==-1) return "";
	if(v[index].right!=-1){
		v[index].value=dfs(v[index].left)+v[index].value+dfs(v[index].right);
		if(index!=root) v[index].value='('+v[index].value+')';	
	}
	return v[index].value;
}
int main(){
	int num;
	cin>>num;
	vector<bool> visit (num+1,false);//因为下标从一开始 所以为num+1 
	v.resize(num+1);
	for(int i=1;i<=num;i++){
		cin>>v[i].value>>v[i].left>>v[i].right;
		if(v[i].left!=-1) visit[v[i].left]=true;
		if(v[i].right!=-1) visit[v[i].right]=true; 
	}
	while(visit[root]==true)root++;
	cout<<dfs(root)<<endl;
}

