#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;

struct node{
	double val = -1;
	vector<int> child; 
};
vector<node> v;
double rate;
double ans;
void dfs(int index, int depth){
	int len = v[index].child.size();
	if(len == 0){
		ans += v[index].val * pow(1 + rate, depth);
		return;
	}
	for(int i = 0; i < len; i++){
		dfs(v[index].child[i],depth + 1);	
	}
}
int main(){
	double n,p,r;
	scanf("%lf %lf %lf",&n,&p,&r);
	v.resize(n);
	for(int i = 0; i < n; i++){
		int temp;
		scanf("%d",&temp);
		if(temp == 0){
			scanf("%lf",&v[i].val);
		}else{
			for(int j = 0; j < temp; j++){
				int tnext;
				scanf("%d",&tnext);
				v[i].child.push_back(tnext);
			}
		}
	}
	rate = r/100.0;
	dfs(0,0);
	printf("%.1lf",p*ans);
} 
