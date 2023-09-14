#include <iostream>
#include <string>

using namespace std;

int main() {
	char character = 'C';
	// 문자 데이터 유형 char로 선언된 character 변수 초기화, C저장
	int interger = 100;
	// 정수 데이터 유형인 int로 선언된 integer 변수 초기화, 정수 100 저장
	double precision = 3.14159;
	// 소수점 데이터 유형인 double로 선언된 precision 변수 초기화, 숫자 저장
	bool is_true = true;
	// 논리형 bool로 선언된 is_true 변수 초기화, true 나타냄
	string word = "Hello World";
	// 문자열 데이터 유형인 string 으로 선언된 word 변수를 초기화, hello world 저장

	cout << "char : " << character << endl;
	// char 문자열을 출력, character 변수의 값을 출력
	cout << "int : " << interger << endl;
	// 문자열을 출력한 후 inteter 변수의 값을 출력
	cout << "double : " << precision << endl;
	cout << "bool : " << is_true << endl;
	cout << "string : " << word << endl;

	return 0;
}
