#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	int n,k;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k;
		vector<int> num;
		bool res = true;
		for(int j=0;j<k;j++){
			int x;
			cin>>x;
			num.push_back(x);
			for(int t=0;t<j;t++){
				if(num[t]==num[j]||abs(t-j)==abs(num[j]-num[t])) 
					res=false;
			}
		}
		cout<<(res?"YES\n":"NO\n");
	}
} 
