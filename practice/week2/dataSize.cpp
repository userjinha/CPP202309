#include <iostream>

using namespace std;

int main()
{
	cout << "char 크기 : " << sizeof('p') << endl;
	// sizeof : 데이터 유형 또는 값의 크기를 바이트 단위로 반환
	// 문자열을 출력한 후, sizeof(p)를 사용하여 p의 크기를 바이트 단위로 출
	cout << "int 크기 : " << sizeof(10) << endl;
	
	cout << "double 크기 : " << sizeof(10.0) << endl;

	return 0;
}
