#include <iostream>
using namespace std;
int main() {
	int n;
	while (true) {
		cout << "======操作菜单======" << endl;
		cout << "  1.释放火系魔法  " << endl;
		cout << "  2.释放冰系魔法  " << endl;
		cout << "  3.执行物理攻击  " << endl;
		cout << "请输入一个正整数n来选择您的操作（输入0或按Ctrl+Z后再按回车键时退出程序）：";
		cin >> n;
		if (!cin) {
			if (cin.eof()) {
				cout << "程序已退出。" << endl;
				break;
			}
			else {
				cout << "您输入的指令无效，请重新输入！" << endl;
			}
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
			continue;
		}
		if (n == 0) {
			cout << "程序已退出。" << endl;
			break;
		}
		switch (n) {
		case 1:
			cout << "释放火系魔法" << endl;
			cout << endl;
			break;
		case 2:
			cout << "释放冰系魔法" << endl;
			cout << endl;
			break;
		case 3:
			cout << "执行物理攻击" << endl;
			cout << endl;
			break;
		default:
			cout << "您输入的指令无效，请重新输入！" << endl;
			cout << endl;
			break;
		}
	}
	return 0;
}