#include <iostream>
using namespace std;

int main()
{
	double c_temp;
	double f_temp;
	// 변수를 선언 

	cout << "섭씨온도: ";
	// 화면에 섭씨온도라는 메시지를 출력
	cin >> c_temp;
	// 사용자로부터 값을 입력받아 c_temp 변수에 저장

	f_temp = (c_temp * 1.8) + 32;
	// 입력받은 섭씨 온도를 화씨 온도로 변환하여 f_temp변수에 저장

	cout << "화씨온도= " << f_temp << endl;
	// 화씨온도를 화면에 출력

	return 0;
}





	
