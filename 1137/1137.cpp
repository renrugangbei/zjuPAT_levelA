#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string> 
using namespace std;
struct student{
	string name;
	int Gp = -1,Gm = -1,Gf = -1,G = -1;
}; 
bool cmp(student a, student b){
	if(a.G != b.G){
		return a.G > b.G;
	}else{
		return a.name < b.name;
	}
}
int main(){
	int p, m, n;
	scanf("%d %d %d",&p,&m,&n);
	map<string,int> hash;
	vector<student> s;
	int index = 1;
	for(int i = 0; i < p; i++){
		student temp;
		cin>>temp.name>>temp.Gp;
		if(temp.Gp >= 200){
			hash[temp.name]= index++;
			s.push_back(temp);
		}
	}
	for(int i = 0; i < m; i++){
		student temp;
		cin>>temp.name>>temp.Gm;
		if(hash.count(temp.name)){
			s[hash[temp.name] - 1].Gm = temp.Gm;
		}
	}
	for(int i = 0; i < n; i++){
		student temp;
		int cnt = 0;
		cin>>temp.name>>temp.Gf;
		if(hash.count(temp.name)){
			if(temp.Gf >= 60){
				if(temp.Gf < s[hash[temp.name] - 1].Gm){
					s[hash[temp.name] - 1].G = int(temp.Gf*0.6 + s[hash[temp.name] - 1].Gm*0.4 + 0.5);
					s[hash[temp.name] - 1].Gf = temp.Gf;
				}else{
					s[hash[temp.name] - 1].G = s[hash[temp.name] - 1].Gf = temp.Gf;
				}
			}
		}
	}
	sort(s.begin(),s.end(),cmp);
	int len = s.size();
	for(int i = 0; i < len; i++){
		if(s[i].Gf >= 60){
			cout<<s[i].name<<" "<<s[i].Gp<<" "<<s[i].Gm<<" "<<s[i].Gf<<" "<<s[i].G<<endl;
		}
	}
}
