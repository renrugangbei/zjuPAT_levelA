#include<iostream>
#include<stack>
#include<iomanip>
using namespace std;
//注意输出格式，多项式对消掉只需要输出0 不是输出 0 0 0.0
struct poly {
	double exp;
	double coe;
};
int main() {
	int n1, n2, cnt = 0;
	poly p;
	stack<poly> st1, st2, st3;
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		cin >> p.exp >> p.coe;
		st1.push(p);
	}
	cin >> n2;
	for (int i = 0; i < n2; i++) {
		cin >> p.exp >> p.coe;
		st2.push(p);
	}
	while (!st1.empty()&&!st2.empty()) {
		auto s1 = st1.top();
		auto s2 = st2.top();
		poly s3;
		if (s1.exp == s2.exp) {
			s3.coe = s1.coe + s2.coe;
			s3.exp = s1.exp;
			if (s3.coe != 0) {
				st3.push(s3);
				cnt++;
			}
			st1.pop();
			st2.pop();
		} else {
			if (s1.exp > s2.exp) {
				st3.push(s2);
				st2.pop();
			} else {
				st3.push(s1);
				st1.pop();
			}
			cnt++;
		}
	}
	if (!st1.empty()) {
		while (!st1.empty()) {
			auto s1 = st1.top();
			st3.push(s1);
			st1.pop();
			cnt++;
		}
	} else {
		while (!st2.empty()) {
			auto s2 = st2.top();
			st3.push(s2);
			st2.pop();
			cnt++;
		}
	}
	if (!st3.empty()) {
		cout << cnt << " " << st3.top().exp;
		cout << " " << fixed << setprecision(1) << st3.top().coe;
		st3.pop();
		while (!st3.empty()) {
			auto s3 = st3.top();
			cout << " " <<fixed<<setprecision(0)<< s3.exp;
			cout<< " " << fixed << setprecision(1) << s3.coe;
			st3.pop();
		}
	} else {
		cout << 0;
	}
	return 0;
	//<< fixed << setprecision(1)
}