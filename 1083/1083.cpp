#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct student{
	char name[12],id[12];
	int grade;
}; 
bool cmp(student a, student b){
	return a.grade > b.grade;
}
int main(){
	int num;
	scanf("%d",&num);
	vector<student> s,ans; 
	for(int i = 0 ; i < num; i++){
		student temp;
		scanf("%s %s %d",&temp.name,&temp.id,&temp.grade);
		s.push_back(temp);
	}
	sort(s.begin(),s.end(),cmp);
	int low,high;
	scanf("%d %d",&low,&high);
	int len = s.size();
	for(int i = 0 ; i < len; i++){
		if(s[i].grade >= low &&s[i].grade <=high){
			ans.push_back(s[i]);
		}else if(s[i].grade <low){
			break;
		}
	}
	len = ans.size();
	if(len==0){
		printf("NONE\n");
	}else{
		for(int i = 0; i < len; i++){
			printf("%s %s\n",ans[i].name,ans[i].id);
		}
	} 
}
