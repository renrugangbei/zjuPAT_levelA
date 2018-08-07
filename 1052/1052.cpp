#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int addr,next,val;
	bool flag = false;
};
bool cmp(node a, node b){
	if(a.flag != b.flag){
		return a.flag > b.flag;
	}else{
		return a.val < b.val;
	}
}
int main(){
	int num,first;
	vector<node> v(100000);
	scanf("%d %d",&num,&first);
	for(int i = 0; i < num; i++){
		node temp;
		scanf("%d %d %d",&temp.addr,&temp.val,&temp.next);
		v[temp.addr] = temp;
	}
	int point = first;
	int cnt = 0;
	while(point != -1){
		v[point].flag = true;
		cnt++;
		point = v[point].next;
	}
	if(cnt == 0){
		printf("0 -1\n");
		return 0;
	} 
	sort(v.begin(),v.end(),cmp);
	printf("%d %05d\n",cnt,v[0].addr);
	for(int i = 0; i < cnt - 1; i++){
		printf("%05d %d %05d\n",v[i].addr,v[i].val,v[i + 1].addr);
	}
	printf("%05d %d -1\n",v[cnt-1].addr,v[cnt-1].val);
} 
