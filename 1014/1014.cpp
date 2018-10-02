#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct Windows{
	int endTime, popTime;
	queue<int> q;
};
vector<int> ans, needTime;
vector<Windows> windows;
int main(){
	int wnum,mline,cnum,qnum;
	scanf("%d %d %d %d",&wnum,&mline,&cnum,&qnum);
	needTime.resize(cnum);
	ans.resize(cnum);
	windows.resize(wnum);
	for(int i = 0; i < cnum; i++){
		scanf("%d",&needTime[i]);
	}
	for(int i = 0; i < wnum; i++){
		windows[i].popTime = windows[i].endTime = 8*60;
	}
	int index = 0;
	for(int i = 0; i < min(wnum * mline, cnum); i++){
		windows[index % wnum].q.push(index);
		windows[index % wnum].endTime += needTime[index];
		if(index < wnum)windows[index].popTime = needTime[index];
		ans[index] = windows[index % wnum].endTime;
		index ++; 
	}
	for(; index < cnum; index++){
		int idx = -1, minPopTime = 0x3fffffff;
		for(int i = 0; i < wnum; i++){
			if(windows[i].popTime < minPopTime){
				idx = i;
				minPopTime = windows[i].popTime;
			}
		}
		windows[idx].q.pop();
		windows[idx].q.push(index);
		windows[idx].endTime += needTime[index];
		windows[idx].popTime += needTime[windows[idx].q.front()];
		ans[index] = windows[idx].endTime; 
	}
	for(int i = 0; i < qnum; i++){
		int q;
		scanf("%d",&q);
		if(ans[q - 1] - needTime[q - 1] >= (17*60)){
			printf("Sorry\n");
		}else{
			printf("%02d:%02d\n",ans[q-1]/60,ans[q-1]%60);
		}
	}
} 
