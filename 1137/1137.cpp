#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
//��ΪҪ������������Բ�����map map������sort���� 
using namespace std;
struct student{
	string name;
	int ps=-1,ms=-1,fs=-1,score=-1;
}; 
bool cmp(student a,student b){
	return a.score!=b.score?a.score>b.score:a.name<b.name;
}
int main(){
	string names;
	int pn,mn,fn,cnt=0;
	vector<student> v, ans;
	map<string,int> index;
	cin>>pn>>mn>>fn;
	for(int i=0;i<pn;i++){
		string tn;
		int ts;
		cin>>tn>>ts;
		if(ts >= 200){
			student temp;
			temp.name=tn;
			temp.ps=ts;
			v.push_back(temp);
			index[tn]=cnt++;
		}
	}
	for(int i=0;i<mn;i++){
		string tn;
		int ts;
		cin>>tn>>ts;
		auto inx=index.find(tn);
		if(inx!=index.end()){
			v[inx->second].ms=ts;
		}
	}
	for(int i=0;i<fn;i++){
		string tn;
		int ts;
		cin>>tn>>ts;
		auto inx=index.find(tn);
		if(inx!=index.end()){
			v[inx->second].fs=ts;
			if(v[inx->second].ms>ts&&ts!=-1){
				v[inx->second].score=int(v[inx->second].ms*0.4+ts*0.6+0.5);//ע���������봦�� 
			}else{
				v[inx->second].score=ts;
			}
		}
		
	}
	for(auto s:v){
		if(s.score>=60){
			ans.push_back(s);
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	for(auto s:ans){
		cout<<s.name<<" "<<s.ps<<" "<<s.ms<<" "<<s.fs<<" "<<s.score<<endl;
	}
}
