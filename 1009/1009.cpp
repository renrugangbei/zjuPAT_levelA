#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;
struct poly {
	double exp;
	double coe;
};
vector<poly> resv;
void add(vector<poly> &result,vector<poly> &v) {
	auto v1 = result.begin();
	auto v2 = v.begin();
	while (v1 != result.end()&&v2 != v.end()) {
		if (v1->exp < v2->exp) {
			result.insert(v1, *v2);
			v2++;
		} else {
			if (v1->exp > v2->exp) {
				v1++;
			} else {
				v1->coe += v2->coe;
				v1++;
				v2++;
			}
		}
	}
	while (v2!=v.end()) {
		result.push_back(*v2);
		v2++;
	}
}
int main() {
	vector<poly> v1, v2, v3;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		poly p;
		cin >> p.exp >> p.coe;
		v1.push_back(p);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		poly p;
		cin >> p.exp >> p.coe;
		v2.push_back(p);
	}
	for (auto v : v1) {
		v3.clear();
		for (auto vv : v2) {
			poly tmp;
			tmp.coe = v.coe * vv.coe;
			tmp.exp = v.exp + vv.exp;
			v3.push_back(tmp);
		}
		add(resv, v3);
	}
	for (auto v = resv.begin(); v != resv.end(); v++) {
		if (fabs(v->coe) < 1e-3)
			v = resv.erase(v);
	}//第一个检查点，如果系数小于1e-3视为0
	if (!resv.empty()) {
		cout << resv.size();
		for (auto v : resv) {
			cout << " " << fixed << setprecision(0) << v.exp;
			cout << " " << fixed << setprecision(1) << v.coe;
		}
	} else {
		cout << 0;
	}
}