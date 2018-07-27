#include<cstdio>
#include<iostream>
using namespace std;
int table[1005];
int main(){
	int cnum,mnum;
	scanf("%d %d",&cnum,&mnum);
	fill(table,table+1005,0);
	for(int i = 0; i < cnum; i++){
		int temp;
		scanf("%d",&temp);
		table[temp]++;
	}
	for(int i = 0; i < 1005; i++){
		if(table[i] && table[mnum - i]){
			if((i == mnum - i) && table[i] <= 1){
				continue;
			}else{
				printf("%d %d\n",i,mnum - i);
				return 0;
			}
		}
		/*if(table[i]){
			table[i]--;
			if(table[mnum-i]){
				printf("%d %d\n",i,mnum - i);
				return 0;
			}
			table[i]++;
		}*/
	}
	printf("No Solution");
}
