#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	long long g,s,k;
	scanf("%lld.%lld.%lld",&g,&s,&k);
	long long num1 = g*17*29 + s*29 + k;
	scanf("%lld.%lld.%lld",&g,&s,&k);
	long long num2 = g*17*29 + s*29 + k;
	long long num = num1+num2;
	printf("%lld.%lld.%lld",num/(17*29),num%(17*29)/29,(num%(17*29))%29);
} 
