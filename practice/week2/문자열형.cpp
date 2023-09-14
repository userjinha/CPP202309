#include <iostream> 
// iostream 헤더파일을 추가, 헤더를 포함하여 .표준 입력. 및 .출력 스트림. 사용할 수 있도록 함
#include <string> 
// string 헤더파일을 추가, 헤더를 포함하여 .문자열.을 다루기 위한 기능을 사용할 수 있도록 함
using namespace std; 
// 이름 공간 설정, std 네임스페이스의 멤버를 사용할 수 있도록 함, 예: cout

int main()
// 함수 선언
{
	string s1 = "Good"; 
	// 문자열 변수 s1을 선언, Good으로 초기화, 문자형 : 알파벳 문자 1개만 가질 수 있음
		string s2 = "Morning";
	// 문자열 변수 s2를 선언, Morning으로 초기화
		string s3 = s1 + " " + s2 + "!";
	// 문자열 변수 s1, 공백 문자열, 문자열 변수 s2, 느낌표를 연결하여 새로운 문자열 변수 s3를 생성
	// 연산자를 사용하여 문자열을 이어 붙일 수 있음
		cout << s3 << endl;
	// s3를 출력하는 코드
	// cout : 텍스트 출력시 사용
	// << "A" : "A"를 cout로 전송하는 출력 연산
	// endl : 표준 줄바꿈 문
		return 0;
}
