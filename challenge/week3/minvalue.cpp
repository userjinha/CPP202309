#include <iostream>
using namespace std;

int main()
{
	int a, b, c, smallest;
	// a b c ���� ���� ������ ������ �����Ѵ�

	cout << "3���� ������ �Է��Ͻÿ�: ";
	// ȭ��â�� 3���� ������ �Է��Ͻÿ��� ����.
	cin >> a >> b >> c;
	// �Է¹��� ���� a b c�� ������ �����Ѵ�.
	if (a < b && a < c)
		// a�� b���� �۰� a�� c���� ������?
		smallest = a;
	// ���� a�� ������ a�� ���� �����Ѵ�.
	else if (b < a && b < c)
		// b�� a���� �۰� b�� c���� ������?
		smallest = b;
	// b�� ������ b�� ���� �����Ѵ�.
	else
		smallest = c;

	cout << " ���� ū ����������" << smallest << endl;
	// ���� ���� ������ �� ���� ������� ���� ȭ�鿡 ����. 
	return 0;
}