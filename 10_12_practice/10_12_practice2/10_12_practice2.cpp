#include <iostream>
#include <string>
using namespace std;
void attack(int damage, string target = "敌人") {
	cout << "攻击" << target << "造成" << damage << "点伤害" << endl;
}
int readInput(string prompt, string& outString) {
	cout << prompt;
	cin >> outString;
	if (!cin) {
		if (cin.eof()) {
			cout << "程序已退出" << endl;
			return 2; // 2代表程序退出
		}
		else {
			cout << "您输入的信息无效，请重新输入！" << endl;
		}
		cin.clear();
		cin.ignore(1000, '\n');
		cout << endl;
		return 0; // 0代表读取失败，需要重试
	}
	return 1; // 1代表读取成功
}
bool damageValidateAndConvert(string inputStr, int maxLength, int minVal, int maxVal, int& result) {
	if (inputStr.find_first_not_of("0123456789") != string::npos) {
		cout << "您输入的伤害值无效！！！请重新输入，请输入一个整数！" << endl;
		return false;
	}
	if (inputStr.size() > maxLength) {
		cout << "您输入的伤害信息无效！！！数值过大，请重新输入！" << endl;
		return false;
	}
	int value = stoi(inputStr);
	if (value < minVal || value > maxVal) {
		cout << "您输入的伤害信息无效，请输入" << minVal << "到" << maxVal << "之间的值" << endl;
		return false;
	}
	result = value;
	return true;
}
int main() {
	while (true) {
		int damage = 0;
		string target;
		string inputString;
		int status;
		status = readInput("请您输入伤害值（整数1~200，按Ctrl+Z后再按回车键时可退出程序）：", inputString);
		if (status == 2) {
			return 0; // 退出
		}
		if (status == 0) {
			continue; // 重试
		}
		if (!damageValidateAndConvert(inputString, 3, 1, 200, damage)) {
			cout << endl;
			continue;
		}
		cout << "===您是否选择手动输入攻击目标？请在下面的菜单中选择（输入1代表选择，输入0代表不选择）===" << endl;
		cout << "1.选择" << endl;
		cout << "0.不选择（此时攻击目标默认输出为敌人）" << endl;
		status = readInput("请输入您的选择(按Ctrl+Z后再按回车键时可退出程序)：", inputString);
		if (status == 2) {
			return 0; // 退出
		}
		if (status == 0) {
			continue; // 重试
		}
		if (inputString != "0" && inputString != "1") {
			cout << "请只输入0或1这两个数中的一个，请重新输入!" << endl;
			cout << endl;
			continue;
		}
		if (inputString == "1") {
			status = readInput("请输入攻击目标：", target);
			if (status == 2) {
				return 0; // 退出
			}
			if (status == 0) {
				continue; // 重试
			}
			cout << endl;
			attack(damage, target);
			cout << endl;
		}
		if (inputString == "0") {
			cout << endl;
			attack(damage);
			cout << endl;
		}
	}
	return 0;
}