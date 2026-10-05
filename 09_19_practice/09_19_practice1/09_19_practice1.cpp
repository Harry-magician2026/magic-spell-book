#include <iostream>
using namespace std;
void printEven(int n) {
	cout << "1到" << n << "之间的所有偶数如下：" << endl;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			cout << i << endl;
		}
	}
}
int main() {
	int n;
	do {
		cout << "请输入1个正整数n（输入0或负数时退出程序）：";
		cin >> n;
		if (n > 0) {
			printEven(n);
		}
		else {
			cout << "程序已退出！";
		}

	} while (n > 0);
	return 0;
}