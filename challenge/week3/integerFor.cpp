# include <iostream>
using namespace std;

int main() {

	int userInput;
	cout << " 정수를 10번 입력하세요 (0을 입력하면 종료):";
	// 화면에 정수를 10벚 입력하세요를 띄운다. 
	for (int i = 0 ; i < 10; i++) 
	// for루프를 시작, i를 0으로 초기화, i가 10 미만인 동안 루프 반복 i는 반복회수를 나타냄
	{
	
			cin >> userInput;
		// 입력받은 값을 userInput에 저장한다.
			if (userInput == 0)
			{
				break;
		}
			// userinput 값이 0이면 종료된다.
			cout << "입력값 :" << userInput << " 횟수 :" << i <<  endl;
			// 입력된 값을 출력하고, 현재까지의 입력횟수를 출력 


	
	}

	cout << "종료 되었습니다";
	// for루프가 종료되면, 종료되었습니다 메시지를 출력함
		
	return 0;

}
    
