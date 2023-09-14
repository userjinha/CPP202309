#include <iostream>

#include <string>
using namespace std;

int main()
{

	string s1 = "Good";
	// 변수 s1을 선언하고 Good으로 초기화함
		string s2 = "Bad";
	// 변수 s2를 선언하고 Bad로 초기화함
		bool b = (s1 == s2);
	// 문자열 변수 s1과 s2를 비교하여 결과를 bool변수 b에 저장
	// == 연잔자를 사용하여 두 문자열이 동일한지 확인, 이 경우 b에 false가 저장됨
		cout << b << endl;
	// b를 출력하는 코드, b는 flase이므로 0이 출력

		s2 = "Good";
	// s2 변수 값을 Bad에서 Good으로 변경
		b = (s1 == s2);
	// 문자열 s1과 s2를 다시 비교하여 결과를 bool 변수 b에 저장, 내용이 동일하므로 b에 true가 저장됨
		cout << b << endl;
	// b를 출력하는 코드, b가 true이므로 1이 출력
}
