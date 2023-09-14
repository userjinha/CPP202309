#include <iostream>
using namespace std;

int main()
{
	int one = 1;
	int two = 2;
	int three = 3;
	int four = 4;
	// 정수 변수를 선언하고 값을 할당

	cout << "1 + 3 = " << one + three << endl;
	cout << "4 - 2 = " << four - two << endl;
	cout << "2 * 3 = " << two * three << endl;
	cout << "4 / 2 = " << four / two << endl;
	// 1과 3을 더한 결과를 출력

	cout << "2 + 3 * 4 = " << two + three * four << endl;
	cout << "2 + 3 * 4 = " << two + three * four << endl;
	cout << "1 + 4 / 2 = " << one + four / two << endl;
	// 연산자 우선 순위를 고려하여 2+(3*4)의 결과를 출력
}
