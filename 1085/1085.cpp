#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n;
	long long num;
	vector<int> v;
	scanf("%d %lld",&n,&num);
	for(int i = 0; i < n; i++){
		long long temp;
		scanf("%lld",&temp);
		v.push_back(temp); 
	}
	sort(v.begin(),v.end());
	long long ans = 1;
	for(int i = 0; i< n; i++){
		long long tempans = upper_bound(v.begin() + i, v.end(), v[i]*num) - (v.begin() + i);
		ans = max(ans,tempans);
	}
	printf("%d",ans);
} 
