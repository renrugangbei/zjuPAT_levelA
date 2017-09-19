#include<cstdio>
#include<vector>
#include<algorithm>
#define INF 0x3fffffff
using namespace std;
struct Node{
	int addr,value,next;
	int order;
};
bool cmp(Node n1,Node n2){
	return n1.order<n2.order;
}
Node n[100001];
vector<Node> n1,n2,n3;
int main(){
	int st,num,k;
	scanf("%d %d %d",&st,&num,&k);
	for(int i=0;i<num;i++){
		Node tnode;
		scanf("%d %d %d",&tnode.addr,&tnode.value,&tnode.next);
		n[tnode.addr]=tnode;
	}
	int tnext=st;
	int ord=0;
	while(tnext!=-1){
		n[tnext].order=ord++;
		if(n[tnext].value<0) n1.push_back(n[tnext]);
		if(n[tnext].value>=0&&n[tnext].value<=k)n2.push_back(n[tnext]);
		if(n[tnext].value>k)n3.push_back(n[tnext]);
		tnext=n[tnext].next;
	}
	sort(n1.begin(),n1.end(),cmp);
	sort(n2.begin(),n2.end(),cmp);
	sort(n3.begin(),n3.end(),cmp);
	int n=n1.size();
	for(auto s:n2){
		n1.push_back(s);
	}
	for(auto s:n3){
		n1.push_back(s);
	} 
	int j=n1.size();
	for(int i=0;i<j-1;i++){
		printf("%05d %d %05d\n",n1[i].addr,n1[i].value,n1[i+1].addr);
	}
	printf("%05d %d -1",n1[j-1].addr,n1[j-1].value);
}
