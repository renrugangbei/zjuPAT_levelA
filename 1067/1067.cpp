#include<vector>
#include<cstdio> 
#include<algorithm>
using namespace std;
int main(){
	int num, ans = 0;
	int cnt = 0;
	scanf("%d",&num);
	vector<int> v;
	v.resize(num);
	for(int i = 0; i < num; i++){
		int temp;
		scanf("%d",&temp);
		v[temp] = i;
		if(temp != i && temp != 0 ){
			cnt++;
		}
	}
	int index = 1;
    while(cnt > 0) {
        if(v[0] == 0) {
            while(index < num) {
                if(v[index] != index) {
                    swap(v[index], v[0]);
                    ans++;
                    break;
                }
                index++;
            }
        }
        while(v[0] != 0) {
            swap(v[v[0]], v[0]);
            ans++;
            cnt--;
        }
    }
	printf("%d\n",ans);
}

