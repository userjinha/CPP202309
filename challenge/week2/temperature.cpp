#include <iostream>
using namespace std;

int main()
{
	double f_temp;
	double c_temp;
	// 변수 선언

	cout << "화씨온도: ";
	// 화면에 화씨온도라는 메시지 출력
	cin >> f_temp;
	// 사용자로부터 값을 입력받아 f_temp변수에 저장

	c_temp = (5.0 / 9.0) * (f_temp - 32);
	// 입력받은 화씨온도를 섭씨온도로 변환하아 c_temp 변수에 저장

	cout << "섭씨온도= " << c_temp << endl;
	// 섭씨 온도를 화면에 출력

	return 0;
}
