#include<cstdio>
#include<vector>
#define INF  0x7fffffff
using namespace std;
int main(){
	vector<int> s1, s2;
	int n1, n2;
	scanf("%d", &n1);
	s1.resize(n1 + 1);
	for(int i = 0; i < n1; i++){
		scanf("%d",&s1[i]);
	}
	s1[n1] = INF;
	scanf("%d",&n2);
	s2.resize(n2 + 1);
	for(int i = 0; i < n2; i++){
		scanf("%d",&s2[i]);
	}
	s2[n2] = INF;
	int midPos = (n1 + n2 - 1)/2;
	int i = 0, j = 0, cnt = 0;
	while(cnt != midPos){
		if(s1[i] > s2[j]){
			j++;
		}else{
			i++;
		}
		cnt++;
	}
	if(s1[i] < s2[j]){
		printf("%d",s1[i]);
	}else{
		printf("%d",s2[j]);
	}
} 
