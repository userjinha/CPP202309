#include <iostream>

using namespace std;

int main()
{
	int x = 1;
	// 정수 변수 x 선언 및 1로 초기화

	cout << "x = " << x++ << endl;
	// 문자열 출력한 후, x++을 사용하 x의 현재 값을 출력하고 그 다음에 x를 1증가 시킴
	cout << "x = " << x++ << endl;
	// x의 현재값을 출력하고, x를 1증가시킴
	cout << "x = " << ++x << endl;
	// 문자열을 출력한 후, ++x를 사용하여 x를 1증가 시키고 그 값을 출력
	cout << "x = " << x-- << endl;
	// 문자열을 출력한 후, x--를 사용하여 x를 1감소 시키고 그 값을 출력
	cout << "x = " << --x << endl;
	// 문자열을 출력한 후, --x를 사용하여 x를 1감소 시키고 그 값을 출력

	return 0;
}
