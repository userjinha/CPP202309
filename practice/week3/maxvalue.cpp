#include <iostream>
using namespace std;

int main()
{
	int a, b, c, largest;
	// a b c ���� ū ���� ������ ������ �����Ѵ�

	cout << "3���� ������ �Է��Ͻÿ�: ";
	// ȭ��â�� 3���� ������ �Է��Ͻÿ��� ����.
	cin >> a >> b >> c;
	// �Է¹��� ���� a b c�� ������ �����Ѵ�.
	if (a > b && a > c)
		// a�� b���� ũ�� a�� c���� ū��?
		largest = a;
	// ���� a�� ũ�� a�� ���� �����Ѵ�.
	else if (b > a && b > c)
		// b�� a���� ũ�� b�� c���� ū��?
		largest = b;
	// b�� ũ�� b�� ���� �����Ѵ�.
	else
		largest = c;

	cout << " ���� ū ������" << largest << endl;
	// ���� ū ������ �� ���� ������� ���� ȭ�鿡 ����. 
	return 0;
}