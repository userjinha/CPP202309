#include <iostream>
using namespace std;

int main() {
	int choice;

	cout << "1. 파일 저장" << endl;
	// 화면창에 파일 저장을 띄운다
	cout << "2. 저장 없이 닫기" << endl;
	// 화면창에 저장 없이 닫기를 띄운다
	cout << "3. 종료" << endl;
	// 화면창에 종료를 띄운다
	cin >> choice;
	// 사용자에게 받은 값을 변수에 저장한다

	switch (choice) {
	case 1:
		cout << "파일 저장을 선택했습니다." << endl;
		break;
		// 1으로 받으면 파일 저장을 선택했습니다가 창에 뜬다
	case2:
		cout << "파일 닫기를 선택했습니다." << endl;
		break;
		// 2로 받으면 파일 닫기를 선택했습니다가 창에 뜬다
	case3:
		cout << "프로그램을 종료합니다." << endl;
		break;
		// 3으로 받으면 프로그램을 종료합니다가 창에 뜬다.
	default:
		cout << "잘못된 선택입니다." << endl;
		break;
	}// 이외에 다른 것을 받으면 잘못된 선택입니다가 창에 뜬다.

	return 0;
}
