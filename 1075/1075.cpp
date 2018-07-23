#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
struct tester{
	int id;
	int score[6] = {-1};
	bool passc = false;
	int tscore = 0;
	int slove = 0;
	int rank;
};
bool cmp(tester a, tester b){
	if(a.tscore != b.tscore){
		return a.tscore > b.tscore;
	}else if(a.slove != b.slove){
		return a.slove > b.slove;
	}else if((a.passc == true && b.passc == true)||(a.passc == false && b.passc == false)){
		return a.id < b.id;
	}else{
		return a.passc > b.passc;
	}
}
int main(){
	int tnum,pnum,snum;
	scanf("%d %d %d",&tnum,&pnum,&snum);
	vector<tester> student(tnum + 1); 
	int fullscore[6] = {0};
	for(int i = 1 ; i <= pnum; i++){
		scanf("%d",&fullscore[i]);
	}
	for(int i = 0; i < snum; i++){
		int tempid,temporder,tempscore;
		scanf("%d %d %d",&tempid,&temporder,&tempscore);
		student[tempid].id = tempid;
		if(tempscore == -1 && (student[tempid].score[temporder] == 0 || student[tempid].score[temporder] == -1)){
			student[tempid].score[temporder] = -1;
		}else if(tempscore == 0){
			student[tempid].score[temporder] = -2;
			student[tempid].passc = true;
		}else{
			if(student[tempid].score[temporder] < tempscore){
				student[tempid].score[temporder] = tempscore;
			}
			if(tempscore == fullscore[temporder]){
				student[tempid].slove++;
			}
			student[tempid].passc = true;
		}
	}
	for(int i = 1; i <= tnum; i++){
		for(int j = 1; j < pnum + 1; j++){
			if(student[i].score[j] != -1 && student[i].score[j] != -2){
				student[i].tscore +=student[i].score[j];
			}
		}
	}
	sort(++student.begin(),student.end(),cmp);
	student[1].rank = 1;
	for(int i = 2; i < tnum + 1; i++){
		if(student[i].tscore == student[i - 1].tscore){
			student[i].rank = student[i-1].rank;
		}else{
			student[i].rank = i;
		}
	}
	for(int i = 1; i < tnum + 1; i++){
		if(student[i].passc == true){
		printf("%d %05d %d",student[i].rank,student[i].id,student[i].tscore);
		for(int j = 1; j < pnum + 1; j++){
			if(student[i].score[j] == 0){
				printf(" -");
			}else{
				if(student[i].score[j] == -1 ||student[i].score[j] == -2){
					printf(" %d",0);
				}else{
					printf(" %d",student[i].score[j]);
					} 
				}
			}
		printf("\n");	
		}
	}
} 
