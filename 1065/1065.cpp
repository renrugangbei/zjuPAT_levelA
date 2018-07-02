#include<iostream>
using namespace std;
int main(){
	long long a, b, c;
	int times;
	cin>>times;
	for(int i = 0; i < times; i++){
		cin>>a>>b>>c;
		long long sum = a + b;
		if(a>0&&b>0&&sum<0){
			cout<<"Case #"<<i + 1<<": true"<<endl;
		}else if(a<0&&b<0&&sum=>0){//xiang deng
			cout<<"Case #"<<i + 1<<": false"<<endl;
		}else if(sum>c){
			cout<<"Case #"<<i + 1<<": true"<<endl;
		}else {
			cout<<"Case #"<<i + 1<<": false"<<endl;
		}
	}
}
