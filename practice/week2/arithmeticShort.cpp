#include <iostream>

using namespace std;

int main()
{
	int two = 2;
	int eight = 8;
	int sum1 = 2;
	int sum2 = 2;
// 정수변수 선언 및 값 할당
	sum1 = sum1 + two;
	// sum1 변수에 two 변수의 값을 더하고 그 결과를 다시 sum1 변수에 할당
	sum2 += eight;
	// sum2 변수에 eight 변수의 값을 더하고 그 결과를 다시 sum2 변수에 할당
	// +=는 현재 변수값에 값을 더한 후 다시 변수에 할당함
	cout << "sum1 = " << sum1 << endl;
	// 문자열 출력, sum1 변수 값을 출력
	cout << "sum2 = " << sum2 << endl;
	// 문자열을 출력, sum2 변수 값을 출력
}
