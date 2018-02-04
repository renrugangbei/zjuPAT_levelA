#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string add(string a){
	string b = a, ans;
	reverse(b.begin(),b.end());
	int carry=0,len=a.length();
	int num;
	for(int i=0;i<len;i++){
		num = (a[i]-'0')+(b[i]-'0')+carry;
		carry=0;
		if(num>=10){
			carry=1;
			num=num-10;
		}
		ans+=char('0'+num);
	}
	if(carry==1) ans+='1';
	reverse(ans.begin(),ans.end());
	return ans;
}
int main(){
	string s;
	cin>>s;
	int cnt=0;
	while(cnt<10){
		string t=s;
		reverse(t.begin(),t.end());
		if(s==t){
			cout<<s<<" is a palindromic number."<<endl;
			break;
		}else{
			string temp=add(s);
			cout<<s<<" + "<<t<<" = "<<temp<<endl;
			s=temp;
			
		}
		cnt++;
	}
	if(cnt==10) cout<<"Not found in 10 iterations."<<endl;
	return 0;
}
