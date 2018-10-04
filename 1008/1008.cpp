#include<cstdio>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int ans = 0,nowlevel = 0;
	for(int i = 0; i < n; i++){
		int templevel;
		scanf("%d",&templevel);
		if(templevel > nowlevel){
			ans += (templevel - nowlevel) * 6;
		}else{
			ans += (nowlevel - templevel) * 4;
		}
		ans += 5;
		nowlevel = templevel;
	}
	printf("%d",ans);
} 
