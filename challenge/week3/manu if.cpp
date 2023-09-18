#include <iostream>
using namespace std;

int main() {
    int choice;
    // 함수 선언

    cout << "1. 파일저장" << endl;
    // 출력창에  파일 저장을 띄운다
    cout << "2. 저장 없이 닫기" << endl;
    // 저장 없이 닫기를 띄운다.
    cout << "3. 종료" << endl;
    // 종료를 띄운다.
    cin >> choice;
    // 선택받은 값을 저장한다.

    if (1==2)
        cout << " 파일 저장을 선택했습니다. " << endl;
    // 파일 저장 선택했습니다가 띈다.
    else if (2==3)
        cout << " 파일 닫기를 선택했습니다. " << endl;
    // 파일 닫기를 선택했습니다가 띈다.
    if (3==1)
        cout << " 프로그램을 종료합니다." << endl;
    // 프로그램을 종료합니다가 띈다.

    return 0;


}

