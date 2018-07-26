#include<map>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
struct car{
	char id[10],status[4];
	int time;
}; 
bool cmp(car a, car b){
	if(strcmp(a.id,b.id))return strcmp(a.id,b.id)<0;
	else return a.time<b.time;
}
bool cmpt(car a, car b){
	return a.time < b.time;
}
int main(){
	int rnum, qnum;
	scanf("%d %d",&rnum,&qnum);
	vector<car> all,valid;
	map<string,int>park;
	int maxtime = -1;
	for(int i = 0; i < rnum; i++){
		int th,tm,ts;
		car tempc;
		char temps[4];
		scanf("%s %d:%d:%d %s",&tempc.id,&th,&tm,&ts,&tempc.status);
		tempc.time = th*3600+tm*60+ts;
		all.push_back(tempc);
	}
	sort(all.begin(),all.end(),cmp);
	for(int i = 0; i < rnum; i++){
		if(!strcmp(all[i].id,all[i + 1].id) &&
		!strcmp(all[i].status,"in") && !strcmp(all[i + 1].status,"out")){
			valid.push_back(all[i]);
			valid.push_back(all[i+1]);
			int parktime = all[i+1].time-all[i].time;
			if(park.count(all[i].id) == 0){
				park[all[i].id] = 0;
			}
			park[all[i].id] += parktime;
			maxtime = max(maxtime,park[all[i].id]);	
		}
	}
	sort(valid.begin(),valid.end(),cmpt);
	int index = 0, carnum = 0;
	for(int i = 0; i< qnum; i++){
		int th,tm,ts;
		scanf("%d:%d:%d",&th,&tm,&ts);
		int qtime = th*3600+tm*60+ts;

		while(index < rnum && valid[index].time <= qtime){
			if(!strcmp(valid[index].status,"in")) carnum++;
			else carnum--;
			index++;
		}
		printf("%d\n",carnum);
	}
	for(auto c: park){
		if(c.second == maxtime){
			printf("%s ",c.first.c_str());
		}
	}
	printf("%02d:%02d:%02d\n",maxtime/3600,maxtime%3600/60,maxtime%60);
}
