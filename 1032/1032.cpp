#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
struct node{
	int addr,next;
	char val;
	bool flag = false;
}; 
int main(){
	int listf,lists,num;
	cin>>listf>>lists>>num;
	vector<node> v(100000);
	for(int i = 0; i < num; i++){
		node temp;
		scanf("%d %c %d",&temp.addr,&temp.val,&temp.next);
		v[temp.addr] = temp;
	}
	int point = listf;
	while(point != -1){
		v[point].flag = true;
		point = v[point].next;
	}
	int spoint = lists;
	while(spoint != -1){
		if(v[spoint].flag == true){
			printf("%05d",spoint);
			return 0;
		}
		spoint = v[spoint].next;
	}
	printf("-1");
}
