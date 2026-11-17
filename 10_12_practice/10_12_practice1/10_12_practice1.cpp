#include <iostream>
#include<string>
using namespace std;
void dealDamage(int damage) {
	cout << "普通攻击造成了" << damage << "点伤害" << endl;
}
void dealDamage(int damage, string element) {
	cout << element << "元素攻击造成了" << damage << "点伤害" << endl;
}
int readInput(string prompt, string& outStr) {
	cout << prompt;
	cin >> outStr;
	if (!cin) {
		if (cin.eof()) {
			cout << "程序已退出！" << endl;
			return 2; // 2代表退出程序
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
bool normalAttackValidateAndConvert(string inputStr, int maxLength, int minVal, int maxVal, int& result) {
	if (inputStr.find_first_not_of("0123456789") != string::npos) {
		cout << "您输入的普通攻击的伤害信息无效，请输入整数！" << endl;
		return false;
	}
	if (inputStr.length() > maxLength) {
		cout << "您输入的普通攻击的伤害信息无效，数值过大！" << endl;
		return false;
	}
	int value = stoi(inputStr);
	if (value < minVal || value > maxVal) {
		cout << "您输入的普通攻击的伤害信息无效，请输入" << minVal << "到" << maxVal << "之间的值";
		return false;
	}
	result = value;
	return true;
}
bool elementAttackValidateAndConvert(string inputStr, int maxLength, int minVal, int maxVal, int& result, string element) {
	if (inputStr.find_first_not_of("0123456789") != string::npos) {
		cout << "您输入的" << element << "元素攻击的伤害信息无效，请输入整数！" << endl;
		return false;
	}
	if (inputStr.length() > maxLength) {
		cout << "您输入的" << element << "元素攻击的伤害信息无效，数值过大！" << endl;
		return false;
	}
	int value = stoi(inputStr);
	if (value < minVal || value > maxVal) {
		cout << "您输入的" << element << "元素攻击的伤害信息无效，请输入" << minVal << "到" << maxVal << "之间的值";
		return false;
	}
	result = value;
	return true;
}
int main() {
	while (true) {
		string inputStr1;
		string inputStr2;
		string element;
		int normalAttack = 0;
		int elementAttack = 0;
		int status;
		status = readInput("请您输入普通攻击的伤害（整数1~20，按Ctrl+Z后再按回车键时可退出程序）：", inputStr1);
		if (status == 2) {
			return 0; // 退出
		}
		if (status == 0) {
			continue; // 重试
		}
		if (!normalAttackValidateAndConvert(inputStr1, 2, 1, 20, normalAttack)) {
			cout << endl;
			continue;
		}
		status = readInput("请您输入元素攻击的名字（按Ctrl+Z后再按回车键时可退出程序）：", element);
		if (status == 2) {
			return 0; // 退出
		}
		if (status == 0) {
			continue; // 重试
		}
		status = readInput("请您输入元素攻击的伤害（整数1~100，按Ctrl+Z后再按回车键时可退出程序）：", inputStr2);
		if (status == 2) {
			return 0; // 退出
		}
		if (status == 0) {
			continue; // 重试
		}
		if (!elementAttackValidateAndConvert(inputStr2, 3, 1, 100, elementAttack, element)) {
			cout << endl;
			continue;
		}
		cout << endl;
		dealDamage(normalAttack);
		dealDamage(elementAttack, element);
		cout << endl;
	}
	return 0;
}