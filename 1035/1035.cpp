#include<iostream>
#include<string>
#include<vector> 
using namespace std;
struct stu{
	string id;
	string pw;
};
int main(){
	vector<stu> ans;
	int num, cnt = 0;
	cin>>num;
	for(int i = 0; i < num; i++){
		string id, pw;
		cin>>id>>pw;
		int len = pw.length();
		bool flag = 0 ;
		for(int i = 0; i < len; i++){
			if(pw[i] == 'l'){
				pw[i] = 'L';
				flag = 1;
			}else if(pw[i]=='1'){
				pw[i] = '@';
				flag = 1;
			}else if(pw[i] == '0'){
				pw[i] = '%';
				flag = 1;
			}else if(pw[i] == 'O'){
				pw[i] = 'o';
				flag = 1;
			}
		}
		if(flag == 1){
			cnt++;
			stu temp;
			temp.id = id;
			temp.pw = pw;
			ans.push_back(temp);
		}
	}
	if(cnt == 0){
		if(num==1){
			cout<<"There is "<<num<<" account and no account is modified";
		}else{
			cout<<"There are "<<num<<" accounts and no account is modified";
		}
		
	}else{
		cout<<cnt<<endl;
		for(auto s:ans){
			cout<<s.id<<" "<<s.pw<<endl;
		}
	}
} 
