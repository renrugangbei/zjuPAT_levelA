#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
struct student {
	string id;
	string inTime;
	string outTime;
};
bool cmp1(student s1,student s2) {
	return s1.inTime < s2.inTime;
}
bool cmp2(student s1, student s2) {
	return s1.outTime > s2.outTime;
}
int main() {
	student s1;
	int n;
	vector<student> sIn,sOut;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s1.id >> s1.inTime >> s1.outTime;
		sIn.push_back(s1);
		sOut.push_back(s1);
	}
	sort(sOut.begin(), sOut.end(), cmp2);
	sort(sIn.begin(), sIn.end(), cmp1);
	cout << sIn.front().id << " " << sOut.front().id;
}