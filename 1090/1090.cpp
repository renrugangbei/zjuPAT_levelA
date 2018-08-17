#include<vector>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct node{
	double val;
	vector<int> child;
};
vector<node> tree;
int cnt = 0, maxdepth = -1000000;
double ans;
void dfs(int root, int depth){
	if(tree[root].child.size() == 0){
		if(depth > maxdepth){
			cnt = 1;
			maxdepth = depth;
		}else if(depth == maxdepth){
			cnt++;
		}
	}
	for(int i = 0; i < tree[root].child.size(); i++){
		dfs(tree[root].child[i],depth + 1);
	}
}
 int main(){
 	 int num;
 	 double price, rate;
 	 scanf("%d %lf %lf",&num,&price,&rate);
 	 tree.resize(num);
 	 rate = rate/100.0;
 	 int root = -1;
 	 for(int i =0; i < num; i++){
 	 	int temp;
 	 	scanf("%d",&temp);
 	 	if(temp == -1){
 	 		root = i;
 	 	}else{
 	 		tree[temp].child.push_back(i);
 	 	}
 	 }
 	dfs(root,0);
	printf("%.2lf %d",pow(1+rate,maxdepth)*price, cnt); 
 }
