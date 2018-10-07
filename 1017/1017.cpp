#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
struct Customer{
	int arriveTime, serveTime;
};
vector<Customer> customer;
vector<int> window;
bool cmp(Customer a, Customer b){
	return a.arriveTime < b.arriveTime; 
}
int main(){
	int cnum,wnum;
	scanf("%d %d",&cnum,&wnum);
	window.resize(wnum,8*3600);
	for(int i = 0; i < cnum; i++){
		int h,m,s,q;
		scanf("%d:%d:%d %d",&h,&m,&s,&q);
		Customer temp;
		int tempTime = h*3600+m*60+s;
		if(tempTime >= 17*3600)
			continue;
		temp.arriveTime = tempTime;
		temp.serveTime = q * 60;
		customer.push_back(temp);
	}
	sort(customer.begin(),customer.end(),cmp);
	double ans = 0.0;
	int len = customer.size();

	for(int i = 0; i < len; i++){
		int minWindow = 0, minTime = 0x3fffffff;
		for(int j = 0; j < wnum; j++){
			if(window[j] < minTime){
				minTime = window[j];
				minWindow = j;
			}
		}
		if(window[minWindow] <= customer[i].arriveTime){
			window[minWindow] = customer[i].arriveTime + customer[i].serveTime;
		}else{
			ans = window[minWindow] - customer[i].arriveTime  + ans;
			window[minWindow] += customer[i].serveTime;
		}
	}
	if(len == 0){
		printf("0.0");
	}else{
		printf("%.1f",ans/60.0/len);
	}
}
