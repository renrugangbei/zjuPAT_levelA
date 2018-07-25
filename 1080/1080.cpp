#include<cstdio>
#include<vector>
#include<algorithm>
#include<map> 
using namespace std;
struct student{
	int Ge,Gi,Gf,rank,order;
	vector<int> chioce;
};
bool cmp(student a, student b){
	if(a.Gf != b.Gf){
		return a.Gf > b.Gf;
	}else if(a.Ge != b.Ge){
		return a.Ge > b.Ge;
	}else{
		return a.order < b.order;
	}
}
int main(){
	int anum,snum,cnum;
	scanf("%d %d %d",&anum,&snum,&cnum);
	if(anum==0 || snum == 0 || cnum == 0){
		printf("\n");
		return 0;
	}
	vector<int> school;
	vector<vector<int>> adminsion(snum);
	for(int i = 0; i < snum; i++){
		int temp;
		scanf("%d",&temp);
		school.push_back(temp);
	}
	vector<student> stu(anum);
	for(int i = 0; i < anum; i++){
		scanf("%d %d",&stu[i].Ge,&stu[i].Gi);
		stu[i].order = i;
		stu[i].Gf = (stu[i].Ge + stu[i].Gi) / 2;
		for(int j = 0; j < cnum; j++){
			int tempc;
			scanf("%d",&tempc);
			stu[i].chioce.push_back(tempc);
		}
	}
	sort(stu.begin(),stu.end(),cmp);
	stu[0].rank = 1;
	map<int, student> ostu;
	for(int i = 1; i < anum; i++){
		if(stu[i].Gf == stu[i - 1].Gf){
			if(stu[i].Ge == stu[i - 1].Ge){
				stu[i].rank = stu[i - 1].rank;
			}else{
				stu[i].rank = i + 1;
			}
		}else{
			stu[i].rank = i + 1; 
		}
		ostu[stu[i].order] = stu[i];	
	}
	for(int i = 0; i < anum; i++){
		for(int j = 0; j < cnum; j++){
			if(school[stu[i].chioce[j]] > 0){
				school[stu[i].chioce[j]]--;
				adminsion[stu[i].chioce[j]].push_back(stu[i].order);
				break;
			}else if(stu[i].rank == ostu[adminsion[stu[i].chioce[j]].back()].rank){
				school[stu[i].chioce[j]]--;
				adminsion[stu[i].chioce[j]].push_back(stu[i].order);
				break;
			}
		}
	}
	for(int i = 0; i < snum; i++){
		sort(adminsion[i].begin(),adminsion[i].end());
		if(!adminsion[i].empty()){
			int len = adminsion[i].size();
			for(int j = 0; j < len - 1; j++){
				printf("%d ",adminsion[i][j]);
			}
			printf("%d\n",adminsion[i][len - 1]);
		}else{
			printf("\n");
		}
	}  
} 
