#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	char out[30][30];
	fill(out[0],out[0]+30*30,' ');
	string s;
	cin>>s;
	int num = s.size()+2;
	int n1 = num/3;
	int n2 = num/3 + num%3;
	int index = 0;
	for(int i = 0; i < n1; i++){
		out[i][0] = s[index++];
	}
	for(int i = 1; i< n2 - 1; i++){
		out[n1-1][i] = s[index++];
	}
	for(int i = n1 - 1; i >= 0; i--){
		out[i][n2-1] = s[index++];
	}
	for(int i = 0; i < n1; i++){
		for(int j = 0; j < n2; j++){
			printf("%c",out[i][j]);
		}
		printf("\n");
	}
}
