#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long toTen(string n1, long long radix) {
	long long res = 0;
	for (auto s : n1) {
		if (s >= '0'&&s <= '9') {
			res = (s - '0') + radix*res;
		}
		if (s >= 'a'&&s <= 'z') {
			res = (s - 'a' + 10) + radix*res;
		}
	}
	return res;
}
int cmp(string n, long long radix, long long n1t) {
	long long n2t = toTen(n, radix);
	if (n2t < 0) {
		//n2转换为十进制后溢出
		return 1;
	}
	if (n2t == n1t) {
		return 0;
	}
	if (n2t > n1t) {
		return 1;
	} else {
		return -1;
	}
}
long long binarySearchRadix(string n2, long long left, long long right, long long n1t) {
	long long mid;
	while (left<=right) {
		mid = (left + right) / 2;
		int tmp = cmp(n2, mid, n1t);
		if (tmp == 0) {
			return mid;
		} else if (tmp == -1) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return -1;
}
int findLargestDigit(string n1) {
	int max = -1;
	int tmp = 0;
	for (auto s : n1) {
		if (s <= '9'&&s >= '0') {
			tmp = s - '0';
			if (tmp > max) 
				max = tmp;
		} else if (s >= 'a'&&s <= 'z') {
			tmp = s - 'a' + 10;
			if (tmp > max)
				max = tmp;
		}
	}
	return max;
}
int main() {
	string n1, n2;
	long long radix;
	int tag;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 2) {
		swap(n1, n2);
	}
	long long n1t = toTen(n1, radix);
	int low = findLargestDigit(n2) + 1;
	long long high = n1t + 1;
	long long res = binarySearchRadix(n2, low, high, n1t);
	if (res == -1) {
		cout << "Impossible" << endl;
	} else {
		cout << res;
	}
}
