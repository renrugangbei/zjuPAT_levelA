#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct mouse{
	int weight,rank;
};
int main(){
	int pnum,gnum;
	scanf("%d %d",&pnum,&gnum);
	vector<mouse> v(pnum);
	queue<int> q;
	for(int i = 0; i < pnum; i++){
		scanf("%d",&v[i].weight);
	}
	for(int i = 0; i < pnum; i++){
		int temp;
		scanf("%d",&temp);
		q.push(temp);
	}
	int totalnum = pnum;
	while(q.size() != 1){
		int groupNum;
		if(totalnum % gnum == 0){
			groupNum = totalnum/gnum;
		}else{
			groupNum = totalnum/gnum + 1;
		}
		for(int i = 0; i < groupNum; i++){
			int max = q.front();
			for(int j = 0; j < gnum; j++){
				if(i * gnum + j > totalnum - 1){
					break;
				}
				int front = q.front();
				if(v[front].weight > v[max].weight){
					max = front;
				}
				v[front].rank = groupNum + 1;
				q.pop();
			}
			q.push(max);
		}
		totalnum = groupNum;
	}
	v[q.front()].rank = 1;
	for(int i = 0; i < pnum - 1; i++){
		printf("%d ",v[i].rank);
	}
	printf("%d", v[pnum - 1].rank);
}
