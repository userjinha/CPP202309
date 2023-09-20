#include <iostream>
#include <time.h>
using namespace std;

int main() {
	int i;
	// i라는 변수선언
	int ans;
	// ans라는 변수 선언
	cout << "산수 문제를 자동으로 출제합니다." << endl;
// 화면에 산수 문제를 자동으로 출제합니다를 띄운다.
	while (true) 
	{
		// 무한 루프 시작 사용자가 정답을 맞출때까지 계속
		int firstNum = rand() % 100;
		int secondNum = rand() % 100;
		// rand()함수를 사용하여 0에서 99사이의 랜덤한 정수인 firstNum과 secondNum을 생성
		cout << firstNum << "+" << secondNum << "=";
		cin >> ans;
	// firstNum과 secondNum을 덧셈문제로 출력, 사용자로부터 정답을 입력받음
		if (firstNum + secondNum == ans) {
			cout << "맞았습니다." << endl;
			break;
		}
		else {
			cout << "틀렸습니다." << endl;
		}
		// 사용자가 입력한 ans와 실제 정답인 firstNum + secondNum을 비교하여 맞았는지 틀렸는지를 판단
		// 맞았으면 맞았습니다. 메시지를 출력하고 무한 루프를 종료
		// 그렇지 않으면 틀렸습니다. 메시지를 출력하고 다시 문제를 출제하는 과정을 반복
	}
	return 0;
}
