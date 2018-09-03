#include<cstdio>
#include<vector>
using namespace std;
bool isPrime(int a){
	for(int i = 2; i*i <= a; i++){
		if(a%i == 0)return false;
	}
	return true;
}
int main(){
	int msize,n,m;
	scanf("%d %d %d",&msize,&n,&m);
	while(!isPrime(msize))msize++;
	vector<int> table(msize);
	for(int i = 0; i < n; i++){
		int temp;
		scanf("%d",&temp);
		int flag = 0;
		for(int j = 0; j < msize; j++){
			int pos = (temp + j*j)%msize;
			if(table[pos] == 0){
				table[pos] = temp;
				flag = 1;
				break;
			}
		}
		if(flag == 0)printf("%d cannot be inserted.\n",temp);
	}
	int ans = 0;
	for(int i = 0; i < m; i++){
		int temp;
		scanf("%d",&temp);
		for(int j = 0; j <= msize; j++){
			ans++;
			int pos = (temp + j*j) % msize;
			if(table[pos] == temp ||table[pos] ==0)break; 
		}
	}
	printf("%.1f",ans/(m*1.0));
} 
