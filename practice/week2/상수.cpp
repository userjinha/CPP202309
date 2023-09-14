#include <iostream>
#define PI 3.14159265359
// PI가 기호상수, 프로그램 내에서 PI를 사용할때 해당 값으로 대체됨
using namespace std;

int main()
{
	int income = 1000;
	// 1000이 리터럴 상수, 정수형 변수 income을 선언하고 초기화함, 이 변수는 1000으로 초기화됨
	const double TAX_RATE = 0.25;
	// TAX_RATE가 상수 변수, 이 변수는 0.25로 초기화됨
	income = income - TAX_RATE * income;
	// income은 세금이 공제된 새로운 값으로 업데이트 됨

	double x = 100;
	// double x 변수를 선언하고 100으로 초기화
	x = x * PI;
	// x를 PI값과 곱셈하여 결과를 X에 다시 저장

	cout << x << endl;
	// 변수 X 출력, 이 경우 X의 최종값이 출력됨
	return 0;
}
