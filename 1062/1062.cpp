#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
//ccout cin �ᳬʱ 
using namespace std;
struct student{
	int id,virtue,talent;
};
bool scmp(student s1, student s2){
	if((s1.virtue + s1.talent) == (s2.virtue + s2.talent)){
		if(s1.virtue == s2.virtue){
			return s1.id < s2.id;
		}else{
			return s1.virtue > s2 .virtue; 
		}
	}
	return (s1.virtue +s1.talent) > (s2.virtue + s2.talent);
}
int main(){
	int num,low,high;
	cin>>num>>low>>high;
	vector<student> sage,nobel,fool,rest;
	int cnt = num;
	for(int i = 0; i < num; i++){
		student temp;
		scanf("%d %d %d",&temp.id,&temp.virtue,&temp.talent);
		if(temp.virtue >= low && temp.talent >= low){
			if(temp.virtue >= high && temp.talent >= high){
				sage.push_back(temp);
			}else if(temp.virtue >= high){
				nobel.push_back(temp);
			}else if(temp.virtue >= temp.talent){
				fool.push_back(temp);
			}else{
				rest.push_back(temp);
			}
		}else{
			cnt--;
		}
	}
	sort(sage.begin(),sage.end(),scmp);
	sort(nobel.begin(),nobel.end(),scmp);
	sort(fool.begin(),fool.end(),scmp);
	sort(rest.begin(),rest.end(),scmp);
	cout<<cnt<<endl;
	if(!sage.empty()){
		for(auto s:sage){
			printf("%d %d %d\n",s.id,s.virtue,s.talent);
		}
	}
	if(!nobel.empty()){
		for(auto s:nobel){
			printf("%d %d %d\n",s.id,s.virtue,s.talent);
		}
	}	
	if(!fool.empty()){
		for(auto s:fool){
			printf("%d %d %d\n",s.id,s.virtue,s.talent);
		}
	}
	if(!rest.empty()){
		for(auto s:rest){
			printf("%d %d %d\n",s.id,s.virtue,s.talent);
		}
	}
} 
