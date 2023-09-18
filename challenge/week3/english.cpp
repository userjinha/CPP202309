#include <iostream>
using namespace std;

int main() {
	// 
	int  number;
	// 변수 선언
	// 
	cout << "숫자를 입려하시오:";
	// 숫자를 입력하시오를 띈다.
	cin >> number;
	// 입력받은 값을 number에 저장한다

	if (number == 0)
		cout << "zero\n" << endl;
	// 0이면 zero로 출력된다.
	else if (number == 1)
		cout << "one\n" << endl;
	// 1이면 one으로 출력된다.
	else
		cout << "many\n" << endl;
	// 그 외이면 many로 출력된다.

	return 0;

}
