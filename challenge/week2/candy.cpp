#include <iostream>
using namespace std;

int main()
{
	int money;
	int candy_price;
	// 정수형 변수를 선언

	cout << "현재 가지고 있는 돈: ";
	// 화면에서 현재 가지고 있는 돈 이라는 메시지 출력
	cin >> money;
	// 사용자로부터 정수 값을 입력받아 money 변수에 저장
	cout << "캔디의 가격: ";
	// 화면에서 캔디의 가격 이라는 메시지 출력
	cin >> candy_price;
	// 사용자로부터 정수의 가격을 입력받아 candy_price 변수에 저

        int n_candies = money / candy_price;
	// 입력받은 것을 나눠서 캔디의 개수를 계산하고 그 값을 변수에 저장
	cout << "최대로 살 수 있는 캔디의 개수=" << n_candies << endl;
	// 최대로 살 수 있는 캔디의 개수를 화면에 출력 


	int change = money % candy_price;
	// 나눈 것을 캔디 구입 후 남은 돈을 chanbge 변수에 저장
	cout << "캔디 구입 후 남은 돈=" << change << endl;
	// 캔디 구입후 남은 돈을 화면에 출력
	return 0;


}
