# include <iostream>
using namespace std;

int main() {

	int userInput;
	cout << " 정수를 10번 입력하세요 (0을 입력하면 종료):";
	// 화면에 정수를 10벚 입력하세요를 띄운다. 
	for (int i = 0 ; i < 10; i++) 
	// i의 변수를 선언하고 0으로 초기화 한다, i는 10미만이여야 하고, i++은 증감연산자이다.
	{
	
			cin >> userInput;
		// 입력받은 값을 userInput에 저장한다.
			if (userInput == 0)
			{
				break;
		}
			// userinput 값이 0이면 종료된다.
			cout << "입력값 :" << userInput << " 횟수 :" << i <<  endl;
			// 입력값 : 저장된 값을 띄우고, 횟수는 i로 증감연산자를 실행한다. 


	
	}

	cout << "종료 되었습니다";
	// 10번이 되면 종료된다.
		
	return 0;

}
    