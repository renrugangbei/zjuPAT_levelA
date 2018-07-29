#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int cnum,pnum;
	long long ans = 0;
	vector<int> coupons, product; 
	scanf("%d",&cnum);
	for(int i = 0; i < cnum; i++){
		int temp;
		scanf("%d",&temp);
		coupons.push_back(temp);
	}
	scanf("%d",&pnum);
	for(int i = 0; i < pnum; i++){
		int temp;
		scanf("%d",&temp);
		product.push_back(temp); 
	}
	sort(coupons.begin(),coupons.end());
	sort(product.begin(),product.end());
	int len = min(cnum,pnum);
	int clen = cnum - 1, plen = pnum - 1;
	for(int i = 0; i < len; i++){
		if(coupons[i] < 0 && product[i] < 0){
			ans += coupons[i]*product[i];
		}else{
			break;
		}
	}
	while(clen >=0 && plen >= 0 && coupons[clen] > 0 && product[plen] > 0){
		ans += coupons[clen] * product[plen];
		clen --;
		plen --;
	}
	printf("%lld\n",ans);
} 
