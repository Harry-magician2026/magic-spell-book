#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Weapon {
	string name;
	int damage;
};
void printWeapons(const vector<Weapon>& weapons){
	for (const auto& w : weapons) {
		cout << w.name << "的伤害是：" << w.damage << endl;
	}
}
void findMaxDamage(const vector<Weapon>& weapons) {
	int maxDamage = weapons[0].damage;
	string maxDamageName = weapons[0].name;
	for (const auto& w : weapons) {
		if (w.damage > maxDamage) {
			maxDamage = w.damage;
			maxDamageName = w.name;
		}
	}
	cout << "伤害值最高的武器的名字是：" << maxDamageName << "，" << "其伤害值为：" << maxDamage;
}
int main() {
	vector<Weapon> weapons;
	weapons.push_back({"长剑", 50});
	weapons.push_back({"法杖", 35});
	weapons.push_back({"匕首", 20});
	printWeapons(weapons);
	findMaxDamage(weapons);
	return 0;
}