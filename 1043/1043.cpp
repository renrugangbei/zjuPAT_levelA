#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> pre,post;
bool isMirror = false;
void getPost(int root, int tail){
	//ÏÈÐò±äºóÐò 
	if(root > tail) return;
	int i = root + 1, j= tail;
	if(!isMirror){
		while(pre[root] > pre[i] && i<=tail) i++;
		while(pre[root] <= pre[j] && j > root) j--;
	}else{
		while(i <= tail && pre[root] <= pre[i]) i++;
		while(j > root && pre[root] > pre[j]) j--;
	}
	if(i-j!=1)return;
	getPost(root+1,j);
	getPost(i,tail);
	post.push_back(pre[root]);
}
int main(){
	int num;
	cin>>num;
	pre.resize(num);
	for(int i=0;i<num;i++){
		cin>>pre[i];
	}
	getPost(0,num-1);
	if(post.size()!=num){
		isMirror = true;
		getPost(0,num-1);
	}
	if(post.size()==num){
		printf("YES\n");
		cout<<post[0];
		for(int i=1;i<post.size();i++){
			cout<<" "<<post[i];
		}
	}else{
		cout<<"NO"<<endl;
	}
} 
