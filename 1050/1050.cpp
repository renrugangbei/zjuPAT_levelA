#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int main(){
	char a[100000],b[100000];
	cin.getline(a,10005);
	cin.getline(a,10005);
	int alen = strlen(a);
	int blen = strlen(b);
	bool table[256];
	fill(table,table+256,true);
	for(int i = 0; i < blen; i++){
		table[b[i]] = false;
	}
	for(int i = 0; i < alen; i++){
		if(table[a[i]] == true){
			printf("%c",a[i]);
		}
	} 
} 
