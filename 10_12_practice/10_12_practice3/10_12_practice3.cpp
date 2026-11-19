#include <iostream>
using namespace std;
enum WeaponType {
	Sword,
	Bow,
	Staff
};
int main() {
	while (true) {
		int n;
		cout << "请输入一个1~3之间的数字（包含1和3，按Ctrl+Z后再按回车键或按0时可退出程序）：";
		cin >> n;
		if (!cin) {
			if (cin.eof()) {
				cout << "程序已退出！" << endl;
				return 0;
			}
			else {
				cout << "您输入的信息无效，请重新输入！" << endl;
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
		switch (n) {
		case 1:
			cout << "你装备了长剑" << endl;
			break;
		case 2:
			cout << "你装备了弓箭" << endl;
			break;
		case 3:
			cout << "你装备了法杖" << endl;
			break;
		default:
			cout << "未知武器" << endl;
		}
		cout << endl;
	}
	return 0;
}