#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int num;
	cin>>num;
	vector<int> dis;
	dis.push_back(0);
	int sum = 0;
	for(int i = 0;i < num; i++){
		int temp;
		cin>>temp;
		sum += temp;
		dis.push_back(sum);
	}
	int testNum;
	cin>>testNum;
	for(int i = 0;i < testNum; i++){
		int left,right;
		cin>>left>>right;
		if(left>right){
			swap(left,right);
		}
		int ans = dis[right-1]-dis[left-1];
		if(ans>(sum-ans)){
			cout<<sum-ans<<endl;
		}else{
			cout<<ans<<endl;
		}
	}
}
