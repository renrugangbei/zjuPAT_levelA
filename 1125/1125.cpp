#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int num;
	vector<int> v;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		int temp;
		scanf("%d",&temp);
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	int res=v[0];
	for(int i=1;i<num;i++){
		res=(res+v[i])/2;
	}
	cout<<res;
}
 
