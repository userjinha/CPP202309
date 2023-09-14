#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;
	// 문자열을 저장할 변수 name을 선언
	cout << " 이름을 입력하시오: ";
	// "이름을 입력하시오:"를 출력
	cin >> name;
	// 사용자로부터 이름을 입력받아 name 변수에 저장
	cout << name << "을 환영합니다." << endl;
	// name 변수에 저장된 이름을 출력하고, "을 환영합니다" 문자열을 추가하여 환영 메시지를 출력
	return 0;
}
