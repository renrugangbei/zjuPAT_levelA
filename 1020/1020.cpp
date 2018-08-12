#include<vector>
#include<cstdio>
using namespace std;
vector<int>post, in, level(100000,-1);
void pre(int root, int start, int end, int index){
	if(start > end) return;
	int i = start;
	while(i < end && in[i] != post[root]) i++;
	level[index] = post[root];
	pre(root - end - 1 + i, start, i - 1, index * 2 + 1);
	pre(root - 1, i + 1, end, index * 2 + 2);
}
int main(){
	int n;
	scanf("%d",&n);
	post.resize(n);
	in.resize(n);
	for(int i = 0; i < n; i++){
		scanf("%d",&post[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d",&in[i]); 
	}
	pre(n-1, 0, n-1, 0);
	int cnt = 0;
	for(int i = 0; i < 100000; i++){
		if(level[i] != -1){
			if(cnt != 0)printf(" ");
			printf("%d",level[i]);
			cnt++;
		}
		if(cnt == n)break;
	}
}
