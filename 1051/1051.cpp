#include<stack>
#include<vector>
#include<iostream>
using namespace std;
int main(){
	int max,len,qnum;
	cin>>max>>len>>qnum;
	for(int i = 0; i < qnum; i++){
		stack<int> s;
		vector<int> v;
		v.push_back(0);
		for(int j = 1; j <= len; j++){
			int temp;
			cin>>temp;
			v.push_back(temp); 
		}
		int current = 1;
		for(int j = 1; j <= len; j++){
			s.push(j);
			if(s.size() > max)break;
			while(!s.empty() && s.top() == v[current]){
				s.pop();
				current ++;
			}
		}
		if(current == len + 1){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
} 
