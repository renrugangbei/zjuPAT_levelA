#include<iostream>
#include<set>
using namespace std;
int book[50001];
struct node{
	int value,cnt;
	node(int a,int b):value(a),cnt(b){}
	bool operator < (const node &a)const{
	return (cnt!=a.cnt)?cnt>a.cnt:value<a.value;//点击多的在前面，在SET中就是小； 
	} 
};
int main(){
	int len,k,num;
	cin>>len>>k;
	set<node> s;
	for(int i=0;i<len;i++){
		cin>>num;
		if(i!=0){
			cout<<num<<":";
			int j=0;
			for(auto it=s.begin();it!=s.end()&&j<k;it++){
				cout<<" "<<it->value;
				j++;
			}
			cout<<endl;
		}
		auto it=s.find(node(num,book[num]));
		if(it!=s.end()){
			s.erase(it);
		}
		book[num]++;
		s.insert(node(num,book[num]));	
	}
}
