#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
struct student{
	string name,id,gender;
	int score;
};
bool fcmp(student s1, student s2){
	return s1.score>s2.score;
}
bool mcmp(student s1, student s2){
	return s2.score>s2.score;
}
int main(){
	int num;
	cin>>num;
	vector<student> f,m;
	for(int i = 0;i < num; i++){
		student temp;
		cin>>temp.name>>temp.gender>>temp.id;
		cin>>temp.score;
		if(temp.gender=="M"){
			m.push_back(temp);
		}else{
			f.push_back(temp);
		}	
	}
	sort(m.begin(),m.end(),mcmp);
	sort(f.begin(),f.end(),fcmp);
	if(!m.empty() && !f.empty()){
		cout<<f.front().name<<" "<<f.front().id<<endl;
		cout<<m.front().name<<" "<<m.front().id<<endl;
		cout<<abs(f.front().score-m.front().score);
	}
	if(m.empty()){
		cout<<"Absent"<<endl;
		cout<<f.front().name<<" "<<f.front().id<<endl;
		cout<<"NA";
	}
	if(f.empty()){
		cout<<"Absent"<<endl;
		cout<<m.front().name<<" "<<m.front().id<<endl;
		cout<<"NA"	;
	}
}
