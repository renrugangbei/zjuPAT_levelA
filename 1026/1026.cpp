#include<cmath>
#include<vector>
#include<cstdio>
#include<algorithm>
#define INF 0x3fffffff
using namespace std;
struct Player{
	int arriveTime,startTime,serveTime;
	bool isVIP = false;
};
struct Table{
	int endTime = 8*3600,serveCnt = 0;
	bool isVIP = false;
};
vector<Player> player,ans;
vector<Table> table;
bool cmp1(Player a, Player b){
	return a.arriveTime < b.arriveTime;
}
bool cmp2(Player a, Player b){
	return a.startTime < b.startTime;
}
int findNextVip(int vipid){
	vipid ++;
	while(!player[vipid].isVIP) vipid++;
	return vipid;
}
void allocTbale(int tid, int pid){
	if(player[pid].arriveTime < table[tid].endTime){
		player[pid].startTime = table[tid].endTime;
	}else{
		player[pid].startTime = player[pid].arriveTime;
	}
	table[tid].endTime = player[pid].startTime + player[pid].serveTime;
	table[tid].serveCnt++;
	ans.push_back(player[pid]);
	player.erase(player.begin() + pid);
}

int main(){
	int pnum;
	scanf("%d",&pnum);
	player.resize(pnum);
	for(int i = 0; i < pnum; i++){
		int th,tm,ts,tp,tv;
		scanf("%d:%d:%d %d %d",&th,&tm,&ts,&tp,&tv);
		player[i].arriveTime = th*3600+tm*60+ts;
		player[i].serveTime = (tp<=120)? tp*60 : 120*60;
		player[i].isVIP = (tv==1)? true : false;
	}
	sort(player.begin(),player.end(),cmp1);
	int tnum,vnum;
	scanf("%d %d",&tnum,&vnum);
	table.resize(tnum + 1);
	for(int i = 0; i < vnum; i++){
		int temp;
		scanf("%d",&temp);
		table[temp].isVIP = true;
	}
	int id = 0,vipid = -1;
	while(player.size()){
		int firstTable = 0, minEndTime = INF;
		for(int i = 1;i <= tnum; i++){
			if(table[i].endTime < minEndTime){
				firstTable = i;
				minEndTime = table[i].endTime;
			}
		}
		if(minEndTime >= 21 * 3600)break;
		if(table[firstTable].isVIP){
			if(player.front().isVIP){
				allocTbale(firstTable,0);	
			}else{
				vipid = findNextVip(0);
				if(player[vipid].arriveTime <= table[firstTable].endTime){
					allocTbale(firstTable,vipid);
				}else{
					allocTbale(firstTable,0);
				}
			}
		}else{
			if(player.front().isVIP){
				int vipTable = 0, minEndVipTime = INF;
				for(int j = 1; j < tnum; j++){
					if(table[j].isVIP && table[j].endTime < minEndVipTime){
						minEndVipTime = table[j].endTime;
						vipTable = j;
					}
				}
				if(table[vipTable].endTime < player.front().arriveTime){
					allocTbale(vipTable,0);
				}else{
					allocTbale(firstTable,0);
				}
			}else{
				allocTbale(firstTable,0);
			}
		}
	}
	sort(ans.begin(),ans.end(),cmp2);
	for(int i = 0; i < ans.size(); i++){
		if(player[i].startTime < 21 * 3600){
				printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",ans[i].arriveTime/3600,ans[i].arriveTime%3600/60,ans[i].arriveTime%60,
											ans[i].startTime/3600,ans[i].startTime%3600/60,ans[i].startTime%60,
											round((ans[i].startTime - ans[i].arriveTime)/60.0));
		}
	}
	printf("%d",table[1].serveCnt);
	for(int i = 2; i<= tnum; i++){
		printf(" %d",table[i].serveCnt);
	}
}
