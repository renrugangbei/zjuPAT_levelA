#include<iostream>
#include<map>
#define MAXN  2010
using namespace std;
map<string, int> stringToInt;
map<int,string> intToString;
map<string, int> ans;
int e[MAXN][MAXN], weight[MAXN];
bool visit[MAXN];
void dfs(int index, int &head, int &numMember, int &totalWeight){
	visit[index] = true;
	numMember++;
	if(weight[index] > weight[head]){
		head = index;
	}
	for(int i = 1; i < MAXN; i++){
		if(e[index][i] > 0){
			totalWeight+=e[index][i];
			e[index][i] = e[i][index] = 0;
			if(visit[i] == false){
				dfs(i,head,numMember,totalWeight);
			}
		}
	}
}

int main(){
	int n,threthold;
	cin>>n>>threthold;
	int index = 1;
	for(int i = 0; i < n; i++){
		string s1, s2;
		int time;
		cin>>s1>>s2>>time;
		if(stringToInt[s1] == 0){
			intToString[index] = s1;
			stringToInt[s1] = index++;
		}
		if(stringToInt[s2] == 0){
			intToString[index] = s2;
			stringToInt[s2] = index++;
		}
		e[stringToInt[s1]][stringToInt[s2]] += time;
		e[stringToInt[s2]][stringToInt[s1]] += time;
		weight[stringToInt[s1]] += time;
		weight[stringToInt[s2]] += time;
	}
	for(int i = 1; i < MAXN; i++){
		if(visit[i] == false){
			int head = i, numMember = 0, totalWeight = 0;
			dfs(i,head,numMember,totalWeight);
			if(numMember > 2 && totalWeight > threthold){
				ans[intToString[head]] = numMember;
			}
		}
	}
	cout<<ans.size()<<endl;
	for(auto it = ans.begin(); it != ans.end(); it++)
        cout << it->first << " " << it->second << endl;
}
