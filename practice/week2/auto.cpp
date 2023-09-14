#include <iostream>
using namespace std;

auto add(int x, int y) {
	return x + y;
}
// auto: 변수/표현식의 데이터 형식을 컴파일러가 자동으로 추천, 'add' 함수 선언 ->
// 두개의 정수를 입력으로 받아서 그들의 합을 반환

int main()
{
	auto sum = add(5, 6);
	// add 함수를 호출, 그 결과를 sum이라는 변수에 저장
	cout << sum;
	// 변수 sum의 값 출력
	return 0;
}
