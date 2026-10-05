#include <iostream>
using namespace std;
int sumArray(int arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + arr[i];
	}
	return sum;
}
int main() {
	int n;
	int result;
	while (true) {
		bool inputError = false;
		cout << "请输入一个正整数n（输入0或按Ctrl+Z后再按回车键时退出程序）：";
		cin >> n;
		if (!cin) {
			if (cin.eof()) {
				cout << "程序已退出！" << endl;
				return 0;
			}
			else {
				cout << "您输入的数字无效，请重新输入！" << endl;
			}
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
			continue;
		}
		if (n == 0) {
			cout << "程序已退出！" << endl;
			return 0;
		}
		if (n < 0) {
			cout << "您输入的数字无效，请重新输入！" << endl;
			cout << endl;
			continue;
		}
		int* arr = new int[n];
		cout << "请输入" << n << "个整数：";
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (!cin) {
				if (cin.eof()) {
					cout << "程序已退出！" << endl;
				}
				else {
					cout << "您输入的指令无效，请重新输入！" << endl;
				}
				cin.clear();
				cin.ignore(1000, '\n');
				inputError = true;
				cout << endl;
				break;
			}
		}
		if (inputError) {
			delete[] arr;
			arr = nullptr;
			continue;
		}
		result = sumArray(arr, n);
		cout << "本次数组中元素的总和为：" << result << endl;
		cout << endl;
		delete[] arr;
		arr = nullptr;
	}
	return 0;
}