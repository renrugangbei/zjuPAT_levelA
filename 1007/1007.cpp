#include<iostream>
using namespace std;
int main() {
	int n, maxSum = -1, thisSum = 0, m1, end, start;
	cin >> n;
	int a[10005] = {0};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	m1= 0;
	for (int i = 0; i < n; i++) {
		thisSum += a[i];
		if (thisSum > maxSum) {
			maxSum = thisSum;
			end = i;
			start = m1;;
		} else if (thisSum < 0) {
			thisSum = 0;
			m1 = i + 1;;
		}
	}
	if (maxSum != -1) {
		cout << maxSum << " " << a[start] << " " << a[end];
	} else {
		cout << 0 << " " << a[0] << " " << a[n-1];
	}
	
}