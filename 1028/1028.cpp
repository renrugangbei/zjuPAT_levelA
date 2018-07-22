#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
struct student{
	int id,score;
	char name[10];
};
int cnum;
bool cmp(student a, student b){
	if(cnum == 1){
		return a.id < b.id;
	}else if(cnum == 2){
		if(strcmp(a.name,b.name) == 0) 
			return a.id < b.id;
		else 
			return strcmp(a.name,b.name) < 0;
	}else if(cnum == 3){
		if(a.score == b.score) 
			return a.id < b.id;
		else
			return a.score < b.score; 
	}
}
int main(){
	int num;
	vector<student> ans;
	scanf("%d %d",&num,&cnum);
	for(int i = 0; i < num; i++){
		student temp;
		scanf("%d %s %d",&temp.id,&temp.name,&temp.score);
		ans.push_back(temp);
	}
	sort(ans.begin(),ans.end(),cmp);
	for(int i = 0; i < num; i++){
		printf("%06d %s %d\n",ans[i].id,ans[i].name,ans[i].score);
	}
} 
