#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> father, course(1010), isRoot;
bool cmp(int a, int b){
	return a > b;
}
int findFather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	while( a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
} 
int main(){
	int n, k ,h;
	scanf("%d",&n);
	father.resize(n + 1);
	isRoot.resize(n + 1);
	for(int i = 1; i< n+1; i++){
		father[i] = i;
	}
	for(int i = 1; i< n+1; i++){
		scanf("%d:",&k);
		for(int j = 0; j < k; j++){
			scanf("%d",&h);
			if(course[h] == 0){
				course[h] = i;
			}
			Union(i,findFather(course[h]));
		} 
	}
	for(int i = 1; i < n + 1; i++){
		isRoot[findFather(i)]++;
	}
	int cnt = 0;
	for(int i = 1; i< n+1; i++){
		if(isRoot[i]!=0) cnt++;
	}
	printf("%d\n",cnt);
	sort(isRoot.begin(),isRoot.end(),cmp);//排序之后从0下标开始 
	printf("%d",isRoot[0]);
	for(int i =1; i< n+1; i++){
		if(isRoot[i] != 0){
			printf(" %d",isRoot[i]);
		}
		
	} 
}
