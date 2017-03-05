#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
int main() {
	double w, t, l;
	double res = 1.0;
	vector<char> s;
	for (int i = 0; i < 3; i++) {
		cin >> w >> t >> l;
		if (w > t&&w > l) {
			s.push_back('W');
			res *= w;
		}
		if (t > w&&t > l) {
			s.push_back('T');
			res *= t;
		}
		if (l > w&&l > t) {
			s.push_back('L');
			res *= l;
		}
	}
	for (auto s1 : s) {
		cout << s1 << " ";
	}
	cout << fixed << setprecision(2) << (res*0.65 - 1) * 2;
}