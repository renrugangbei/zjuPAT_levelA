#include<iostream>
using namespace std;
int main() {
	int n, num = 0, cnt = 0;;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp > num) {
			cnt += (temp - num) * 6 + 5;
		} else if(temp<num){
			cnt += (num - temp) * 4 + 5;
		} else {
			cnt += 5;
		}
		num = temp;
	}
	cout << cnt;
}//这电梯竟然能一直按一层。。。。