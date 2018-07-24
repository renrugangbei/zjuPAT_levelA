#include<cstdio>
#include<algorithm> 
using namespace std;
int main(){
	int num, hash[10010],a[100010];
	fill(hash,hash+10010,0);
	fill(a,a+100010,0);
	scanf("%d",&num);
	for(int i = 0 ; i < num; i++){
		scanf("%d",&a[i]);
		hash[a[i]]++;
	}
	int ans = -1;
	for(int i = 0; i < num; i++){
		if(hash[a[i]] == 1){
			ans = a[i];
			break;
		}
	}
	if(ans == -1){
		printf("None\n");
	}else{
		printf("%d\n",ans);
	}
} 
