#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
struct user{
	string id;
	int mouth,day,hour,minute,statu;
	int time;
};
bool cmp(user a, user b){
	if(a.id != b.id){
		return a.id<b.id;
	}
	return a.time<b.time;
}
double calbillfromzero(user temp, int rate[]){
	double total = rate[temp.hour] * temp.minute + rate[24] * 60 * temp.day;
    for (int i = 0; i < temp.hour; i++){
    	total += rate[i] * 60;
    }
    return total / 100.0;
}
int main(){
	int cost[25];
	fill(cost,cost+25,0);
	for(int i = 0; i < 24; i++){
		cin>>cost[i];
		cost[24] +=cost[i];
	}
	int num;
	vector<user> v;
	cin>>num;
	for(int i  = 0; i < num; i++){
		user temp;
		cin>>temp.id;
		scanf("%d:%d:%d:%d", &temp.mouth, &temp.day, &temp.hour, &temp.minute);
		string ts;
		cin>>ts;
		temp.statu = (ts == "on-line")?1:0;
		temp.time = temp.day*24*60 + temp.hour*60 + temp.minute;
		v.push_back(temp);
	}
	sort(v.begin(),v.end(),cmp);
	map<string,vector<user>> custom;
	for(int i = 0; i < num - 1; i++){
		if(v[i].id == v[i+1].id && v[i].statu == 1 && v[i + 1].statu == 0){
			custom[v[i].id].push_back(v[i]);
			custom[v[i].id].push_back(v[i+1]);
		}
	}
	for(auto s : custom){
		cout<<s.first;
		vector<user> temp = s.second;
		printf(" %02d\n",temp[0].mouth);
		int len = temp.size();
		double total = 0.0;
		for(int i = 0; i < len - 1; i+=2){
			double t1 = calbillfromzero(temp[i + 1],cost);
			double t2 = calbillfromzero(temp[i],cost);
			double t = t1- t2;	
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
					temp[i].day,temp[i].hour,temp[i].minute,
					temp[i+1].day,temp[i+1].hour,temp[i+1].minute,temp[i+1].time-temp[i].time,t);
			total += t;				
		}
		printf("Total amount: $%.2f\n",total);
	}
}
