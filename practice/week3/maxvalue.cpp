#include <iostream>
using namespace std;

int main()
{
	int a, b, c, largest;
	// a b c 가장 큰 값의 형태의 변수를 선언한다

	cout << "3개의 정수를 입력하시오: ";
	// 화면창에 3개의 정수를 입력하시오를 띄운다.
	cin >> a >> b >> c;
	// 입력받은 값을 a b c의 변수에 저장한다.
	if (a > b && a > c)
		// a가 b보다 크고 a가 c보다 큰가?
		largest = a;
	// 만약 a가 크면 a에 값을 저장한다.
	else if (b > a && b > c)
		// b가 a보다 크고 b가 c보다 큰가?
		largest = b;
	// b가 크면 b에 값을 저장한다.
	else
		largest = c;

	cout << " 가장 큰 점수는" << largest << endl;
	// 가장 큰 점수는 을 띄우고 저장받은 값을 화면에 띄운다. 
	return 0;
}