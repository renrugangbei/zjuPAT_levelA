#include<iostream>
#include<stack>
#include<iomanip>
using namespace std;
int main() {
	int input1, input2, num;
	cin >> input1 >> input2;
	num = input1 + input2;
	if (num < 0) {
		num = -num;
		cout << "-";
	}
	stack<int> stk;
	if (num == 0) {
		stk.push(0);
	}
	else{
		while (num != 0) {
			stk.push(num % 1000);
			num /= 1000;
		}
	}
	cout << stk.top();
	stk.pop();
	while (!stk.empty()) {
		cout << "," << setfill('0') << setw(3) << stk.top();//²¹Áã
		stk.pop();
	}
	return 0;
}