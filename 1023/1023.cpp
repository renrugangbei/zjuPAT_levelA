#include<string>
#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int book[10];
	fill(book,book+10,0);
	int len = s.length(), carry = 0;
	for(int i = len - 1; i >= 0; i--){
		int temp = (s[i] - '0');
		book[temp]++;
		temp = temp * 2 + carry;
		if(temp >= 10){
			s[i] = temp - 10 + '0';
			temp = temp - 10;
			carry = 1;
		}else{
			s[i] = temp + '0';
			carry = 0;
		}
		book[temp]--;
	}
	int flag = 0;
	for(int i = 0; i < 10; i++){
		if(book[i] != 0)flag = 1;
	}
	if(flag == 1){
		printf("No\n");
	}else{
		printf("Yes\n");
	}
	//注意最高进位的处理 
	if(carry == 1){
		printf("1");
	}
	printf("%s",s.c_str());
}
