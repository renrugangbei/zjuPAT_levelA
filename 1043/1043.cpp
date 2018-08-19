#include<vector>
#include<cstdio>
using namespace std;
vector<int> pre,post;
bool ismirror = false;
void getpost(int root, int tail){
	int i = root + 1, j = tail;
	if(!ismirror){
		while(i <= tail && pre[i] < pre[root]) i++;
		while(j > root && pre[j] >= pre[root]) j--;	
	}else{
		while(i <= tail && pre[i] >= pre[root]) i++;
		while(j > root && pre[j] < pre[root]) j--;
	}
	if(i - j != 1) return;
	getpost(root + 1, j);
	getpost(i, tail);
	post.push_back(pre[root]);
}
int main(){
	int num;
	scanf("%d",&num);
	pre.resize(num);
	for(int i = 0; i < num; i++){
		scanf("%d",&pre[i]);
	}
	getpost(0 , num-1);
	if(post.size() != num){
		post.clear();
		ismirror = true;
		getpost(0,num-1);
	}
	if(post.size() == num){
		printf("Yes\n%d",post[0]);
		for(int i = 1; i< num; i++){
			printf(" %d",post[i]);
		}
	}else{
		printf("No");
	}
} 
