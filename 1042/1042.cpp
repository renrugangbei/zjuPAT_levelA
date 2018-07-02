#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int times;
	cin>>times;
	int st[55],end[55],next[55];
	int index = 0;
	char map[5] = {'S','H','C','D','J'}; 
	for(int i = 1; i < 55; i++){
		st[i] = i;
	}
	for(int i = 1; i < 55; i++){
		cin>>next[i];
	}
	for (int i = 0;i < times; i++){
		for(int j = 1; j < 55; j++){
			end[next[j]] = st[j];
		}
		for(int j = 1; j < 55; j++){
			st[j] = end[j];
		}
	}
	for(int i = 1; i < 54; i++){
		cout<<map[(end[i]-1)/13]<<(end[i]-1)%13+1<<" ";
	}
	cout<<map[(end[54]-1)/13]<<(end[54]-1)%13+1;
}
