#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
map<string,set<int>> title, auther, keyword, pub,year;
void query(map<string,set<int>> &m, string &str){
	if(m.find(str) == m.end()){
		printf("Not Found\n");
	}else{
		for(auto it = m[str].begin(); it != m[str].end(); it++){
			printf("%07d\n",*it);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		int id;
		string tt, ta, tk, tp, ty;
		scanf("%d\n", &id);
		getline(cin,tt);
		title[tt].insert(id);
		getline(cin,ta);
		auther[ta].insert(id);
		while(cin>>tk){
			keyword[tk].insert(id);
			char c = getchar();
			if(c == '\n') break;
		}
		getline(cin,tp);
		pub[tp].insert(id);
		getline(cin,ty);
		year[ty].insert(id); 
	}
	int m;
	scanf("%d",&m);
	for(int i = 0; i < m; i++){
		int index;
		scanf("%d: ",&index);
		string test;
		getline(cin,test);
		printf("%d: ",index);
		cout<<test<<endl;
		if(index == 1)query(title,test);
		else if(index == 2)query(auther,test);
		else if(index == 3)query(keyword,test);
		else if(index == 4)query(pub,test);
		else if(index == 5)query(year,test);	
	} 
}
