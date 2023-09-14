#include <iostream>

using namespace std;

int main()
{
	int two = 2;
	int eight = 8;
	int sum1 = 2;
	int sum2 = 8;
	// 정수변수 선언, 각 값 할당

	sum1*= two;
	// sum1 = summ1 * two 를 축약한 표현
	sum2 /= eight;
	// sum2 = sum2/eight 를 축약한 표현
	

	cout << "sum1 = " << sum1 << endl;
	// 문자열 출력, sum1 변수의 값을 출력
	cout << "sum2 = " << sum2 << endl;
	// 문자열 출력, sum2 변수의 값을 출력

	return 0;
	
}
