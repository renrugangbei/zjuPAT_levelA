#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
//超时 两个方法都超时 测试点2和3 
using namespace std;
struct richer{
	char name[10];
	int age,worth;
};
bool cmp(richer a, richer b){
	if(a.worth != b.worth) return a.worth > b.worth;
	else if(a.age != b.age) return a.age < b.age;
	else return(strcmp(a.name,b.name) < 0);
}
int main(){
	int num, qnum;
	vector<richer> v[205];
	scanf("%d %d",&num,&qnum);
	for(int i = 0; i < num; i++){
		richer temp;
		scanf("%s %d %d",&temp.name,&temp.age,&temp.worth);
		v[temp.age].push_back(temp);
	}
	for(int i = 0; i < qnum; i++){
		int onum, amin, amax;
		scanf("%d %d %d",&onum,&amin,&amax);
		int range = amax - amin + 1;
		vector<richer> ans; 
		for(int j = amin; j < amin+range; j++){
			ans.insert(ans.end(),v[j].begin(),v[j].end()); 
		}
		sort(ans.begin(),ans.end(),cmp);
		printf("Case #%d:\n",i + 1);
		if(ans.size() == 0){
			printf("None\n");
		}else{
			int len = ans.size();
			for(int j = 0; j < onum && j < len; j++){
				printf("%s %d %d\n",ans[j].name,ans[j].age,ans[j].worth);
			}
		}
	}
}
/*int main(){
	int num,qnum;
	vector<richer> v,ans;
	scanf("%d %d",&num,&qnum);
	for(int i = 0; i < num; i++){
		richer temp;
		scanf("%s %d %d",temp.name,&temp.age,&temp.worth);
		v.push_back(temp);
	}
	int book[205];
	fill(book,book+205,0);
	sort(v.begin(),v.end(),cmp);
	for(int i = 0; i < num; i++){
		if(book[v[i].age]<100){
			ans.push_back(v[i]);
			book[v[i].age]++;
		}
	}
	for(int i = 0 ; i < qnum; i++){
		int onum,amin,amax;
		scanf("%d %d %d",&onum,&amin,&amax);
		vector<richer> n;
		int len = ans.size();
		for(int j = 0; j < len; j++){
			if(ans[j].age >= amin && ans[j].age <= amax){
				n.push_back(ans[j]);
			}
		}
		printf("Case #%d:\n", i + 1);
		int size = n.size();
		if(size == 0){
			printf("None\n");
			return 0;
		}
		for(int j = 0; j < size && j < onum; j++){
			printf("%s %d %d\n",n[j].name,n[j].age,n[j].worth); 
		}	
	}
}
/**/
