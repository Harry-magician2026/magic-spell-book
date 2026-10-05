#include <iostream>
#include <vector>
using namespace std;
struct Weapon {
	string name;
	int damage;
};
void printWeapons(const vector<Weapon>& weapons) {
	for (const auto& w : weapons) {
		cout << w.name << "的伤害是：" << w.damage << endl;
	}
	cout << endl;
}
int main() {
	while (true) {
		vector<Weapon> weapons;
		for (int i = 0; i < 3; i++) {
			Weapon wp;
			cout << "请输入第" << i + 1 << "把武器的名字和伤害（按Ctrl+Z后再按回车键时退出程序）：";
			cin >> wp.name >> wp.damage;
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
				break;
			}
			if (wp.damage <= 0) {
				cout << "您输入的数字无效，请重新输入！" << endl;
				cout << endl;
				break;
			}
			weapons.push_back(wp);
		}
		if (weapons.size() < 3) {
			continue;
		}
		cout << "======删除最后1把武器之前的输出======" << endl;
		printWeapons(weapons);
		weapons.pop_back();
		cout << "======删除最后1把武器之后的输出======" << endl;
		printWeapons(weapons);
	}
	return 0;
}