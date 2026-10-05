#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	cout << "vec中的每个元素分别是：";
	bool needComma = false;
	for (const auto& num : vec) {
		if (needComma) {
			cout << "，";
		}
		cout << num;
		needComma = true;
	}
	cout << endl;
	cout << "vec中的元素个数为：" <<vec.size() << endl;
	return 0;
}
