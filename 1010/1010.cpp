#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
long long convert(string s, int radix){
	long long sum = 0;
	int index = 0, temp = 0;
	for(auto it = s.rbegin(); it != s.rend(); it++){
		temp = isdigit(*it)? *it - '0' : *it - 'a' + 10;
		sum += temp * pow(radix,index++);
	}
	return sum;
}
long long find_radix(string s, long long num){
	char it = *max_element(s.begin(),s.end());
	long long low = (isdigit(it)? it-'0':it-'a' + 10)+ 1;
	long long high = max(num,low);
	while(low <= high){
		long long mid = (low + high)/2;
		long long t = convert(s, mid);
		if(t < 0 || t > num)high = mid - 1;
		else if(t == num) return mid;
		else low = mid + 1;
	}
	return -1;
}
int main(){
	string n1, n2;
	int radix,  flag = 1, ans = 0;
	cin>>n1>>n2>>flag>>radix;
	if(flag == 1){
		ans = find_radix(n2,convert(n1,radix));
	}else{
		ans = find_radix(n1,convert(n2,radix));
	}
	if(ans == -1){
		cout<<"Impossible";
	}else{
		cout<<ans;
	}
} 
