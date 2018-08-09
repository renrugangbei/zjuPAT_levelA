#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int addr,val,next,order = 0x3fffffff;
};
bool cmp(node a, node b){
	return a.order < b.order;
}
int main(){
	int first, num;
	scanf("%d %d",&first,&num);
	vector<node> remove;
	vector<node> v(100000);
	int valmark[100000];
	fill(valmark,valmark+100000,0);
	for(int i = 0; i < num; i++){
		node temp;
		scanf("%d %d %d",&temp.addr,&temp.val,&temp.next);
		v[temp.addr] = temp;
	}
	int point = first;
	int cnt = 0;
	while(point != -1){
		v[point].order = cnt;
		point = v[point].next;
		cnt++;
	}
	point = first;
	while(point != -1){
		if(valmark[abs(v[point].val)] == 0){
			valmark[abs(v[point].val)]++;
			point = v[point].next;
		}else{
			remove.push_back(v[point]);
			v[point].order = 0x3fffffff;
			point = v[point].next;
			num--;
		}
	}
		sort(v.begin(),v.end(),cmp);
	if(remove.size() != 0){
		for(int i = 0; i < num - 1; i++){
			printf("%05d %d %05d\n",v[i].addr,v[i].val,v[i+1].addr);
	}
		printf("%05d %d -1\n",v[num - 1].addr,v[num - 1].val);
		int len = remove.size();
		for(int i = 0; i < len - 1; i++){
			printf("%05d %d %05d\n",remove[i].addr,remove[i].val,remove[i + 1].addr);
		} 
		printf("%05d %d -1\n",remove[len - 1].addr,remove[len - 1].val);	
	}else{
		for(int i = 0; i < num - 1; i++){
			printf("%05d %d %05d\n",v[i].addr,v[i].val,v[i+1].addr);
	}
		printf("%05d %d -1\n",v[num - 1].addr,v[num - 1].val);	
	}
} 
