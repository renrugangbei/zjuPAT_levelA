#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	char bet[3] = {'W','T','L'};
	char bestbet[3];
	double radio = 1;
	for(int i = 0; i < 3; i++){
		double maxbet = 0;
		for(int j = 0;j < 3; j++){
			double temp;
			cin>>temp;
			if(temp > maxbet){
				bestbet[i] = bet[j];
				maxbet = temp;
			}
		}
		radio *= maxbet;
	}
	for(int i = 0; i < 3; i++){
		cout<<bestbet[i]<<" ";
	}
	printf("%.2f",(radio*0.65-1)*2.0);
}
