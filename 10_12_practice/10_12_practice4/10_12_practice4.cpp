#include <iostream>
using namespace std;
enum DamageType {
	Physical,
	Fire,
	Ice
};
struct Enemy {
	string name;
	int hp;
};
void attack(Enemy& target, int damage) {
	cout << "对" << target.name << "造成" << damage << "点物理伤害" << endl;
	target.hp = target.hp - damage;
	if (target.hp <= 0) {
		cout << target.name << "被击败了" << endl;
		target.hp = 0;
	}
}
void attack(Enemy& target, int damage, DamageType type) {
	switch (type) {
		case Physical:
			cout << "对" << target.name << "造成" << damage << "点物理伤害" << endl;
			break;
		case Fire:
			cout << "对" << target.name << "造成" << damage << "点火焰伤害" << endl;
			break;
		case Ice:
			cout << "对" << target.name << "造成" << damage << "点冰霜伤害" << endl;
			break;
	}
	target.hp = target.hp - damage;
	if (target.hp <= 0) {
		cout << target.name << "被击败了" <<endl;
		target.hp = 0;
	}
}
int main() {
	Enemy enemy = { "哥布林", 100 };
	attack(enemy, 30);
	attack(enemy, 40, Fire);
	attack(enemy, 50, Ice);
	cout << "敌人最终剩余的血量为：" << enemy.hp << endl;
	return 0;
}