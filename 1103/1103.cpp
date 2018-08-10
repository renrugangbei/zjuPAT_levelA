#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int n,k,p, maxFacSum = -1;
vector<int>ans, tempans, v;
void init(){
	int temp = 0,index = 1;
	while(temp < n){
		v.push_back(temp);
		temp = pow(index,p);
		index++;
	}
}
void dfs(int index, int nowK, int nowSum, int facSum){
	if(nowK == k && nowSum == n ){
		if(facSum > maxFacSum){
			ans = tempans;
			maxFacSum = facSum;
		}
		return;
	}
	if(nowK > k || nowSum > n)return;
	if(index - 1 > 0){
		tempans.push_back(index);
		dfs(index, nowK + 1, nowSum + v[index], facSum + index);
		tempans.pop_back();
		dfs(index - 1, nowK, nowSum, facSum);	
	}
}
int main(){
	scanf("%d %d %d",&n,&k,&p);
	init();
	dfs(v.size() - 1, 0, 0, 0);
	if(maxFacSum == -1){
		printf("Impossible\n");
	}else{
		printf("%d = %d^%d",n,ans[0],p);
		for(int i = 1; i < ans.size(); i++){
			printf(" + %d^%d",ans[i],p);
		}
	}
}
 
