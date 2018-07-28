#include<cstdio>
#include<algorithm> 
#include<vector>
#define INF 0x3fffffff
using namespace std;
struct station{
	double price,dis;
};
bool cmp(station a,station b){
	return  a.dis < b.dis;
}
int main(){
	double tank,des,per,gnum;
	vector<station> s;
	scanf("%lf %lf %lf %lf",&tank,&des,&per,&gnum);
	station temp;
	for(int i = 0; i < gnum; i++){
		scanf("%lf %lf",&temp.price,&temp.dis);
		s.push_back(temp);
	}
	temp.price = 0;
	temp.dis = des;
	s.push_back(temp);
	sort(s.begin(),s.end(),cmp);
	int snum = s.size();
	if(s[0].dis != 0){
		printf("The maximum travel distance = %.2lf\n",0);
	}else{
		int nows = 0;
		double ans = 0, nowtank = 0, maxdis = per * tank;
		while(nows < gnum){
			int mins = -1;
			double minprice = INF;
			for(int i = nows + 1; i<= gnum && s[i].dis - s[nows].dis <= maxdis; i++){
				if(s[i].price < minprice){
					minprice = s[i].price;
					mins = i;
					if(s[i].price < s[nows].price){
						break;
					}
				}
			}
			if(mins == -1){
				printf("The maximum travel distance = %.2lf\n",s[nows].dis + maxdis);
				return 0;
			}
			double need = (s[mins].dis - s[nows].dis)/per;
			if(s[mins].price < s[nows].price){
				if(nowtank < need){
					ans = ans + (need - nowtank) * s[nows].price;
					nowtank = 0;
				}else{
					nowtank = nowtank - need;
				}
			}else{
				ans = ans + (tank - nowtank)*s[nows].price;
				nowtank = tank-need;
			}
			nows = mins;
		}
		if(nows == gnum){
			printf("%.2lf",ans);
		}
	}
}
