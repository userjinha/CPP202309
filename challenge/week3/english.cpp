#include <iostream>
using namespace std;

int main() {
	// 
	int  number;
	// ���� ����
	// 
	cout << "���ڸ� �Է��Ͻÿ�:";
	// ���ڸ� �Է��Ͻÿ��� ���.
	cin >> number;
	// �Է¹��� ���� number�� �����Ѵ�

	if (number == 0)
		cout << "zero\n" << endl;
	// 0�̸� zero�� ��µȴ�.
	else if (number == 1)
		cout << "one\n" << endl;
	// 1�̸� one���� ��µȴ�.
	else
		cout << "many\n" << endl;
	// �� ���̸� many�� ��µȴ�.

	return 0;

}