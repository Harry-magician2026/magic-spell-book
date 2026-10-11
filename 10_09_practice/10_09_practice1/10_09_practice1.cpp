#include <iostream>
#include <string>
using namespace std;
int heal(int& hp, int healPoints) {
	hp = hp + healPoints;
	if (hp > 100) {
		hp = 100;
	}
	return hp;
}
int main() {
	int hp = 60;
	while (true) {
		string inputStr;
		cout << "请您输入治疗量（整数0~99，按Ctrl+Z后再按回车键时可退出程序）：";
		cin >> inputStr;
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
		if (inputStr.find_first_not_of("0123456789") != string::npos) {
			cout << "您输入的信息无效，请输入整数！" << endl;
			cout << endl;
			continue;
		}
		if (inputStr.length() > 2) {
			cout << "您输入的信息无效，数值过大！" << endl;
			cout << endl;
			continue;
		}
		int healPoints = stoi(inputStr);
		int result = heal(hp, healPoints);
		cout << "治疗后的血量为：" << result <<endl;
		cout << endl;
	}
}