#include <iostream>
using namespace std;

int main()
{
	int money;
	int candy_price;

	cout << "���� ������ �ִ� ��: ";
	cin >> money;
	cout << "ĵ���� ����: ";
	cin >> candy_price;


	int n_candies = money / candy_price;
	cout << "ĵ�� ���� �� ���� ��=" << money << endl;
	return 0;


}