#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int val,next,order = 1000000,addr;
};
bool cmp(node a, node b){
	return a.order < b.order;
}
 int main(){
 	int first, nodenum, len;
 	scanf("%d %d %d",&first,&nodenum,&len);
 	vector<node> v(100000);
 	for(int i = 0; i < nodenum; i++){
 		int tempaddr;
 		node tempnode;
 		scanf("%d %d %d", &tempaddr, &tempnode.val, &tempnode.next);
 		tempnode.addr = tempaddr;
 		v[tempaddr] = tempnode;
 	}
 	int ptemp = first,cnt = 0; 
 	while(ptemp != -1){
 		v[ptemp].order = cnt;
 		cnt++;
 		ptemp = v[ptemp].next;
 	}
 	sort(v.begin(),v.end(),cmp);
 	int times = nodenum / len;
 	for(int i = 0; i < times; i++){
 		for(int j = (i + 1)*len - 1; j > i*len; j--){
 			printf("%05d %d %05d\n",v[j].addr,v[j].val,v[j - 1].addr);
 		}
 		printf("%05d %d ", v[i * len].addr,v[i * len].val);
 		if(i < times - 1){
 			printf("%05d\n", v[(i+2) * len - 1].addr);
 		}else{
 	 	 	if(nodenum % len == 0){
 	 	 		printf("-1\n");
 	 	 	}else{
 	 	 		printf("%05d\n",v[(i+1)*len].addr);
 	 	 		for(int k = times * len; k < nodenum; k++){
 	 	 			printf("%05d %d ",v[k].addr,v[k].val);
 	 	 			if(k < nodenum - 1){
 	 	 				printf("%05d\n", v[k + 1].addr);
 	 	 			}else{
 	 	 				printf("-1\n");
 	 	 			}
 	 	 		} 
 	 	 	}
 		}
 	}
}
