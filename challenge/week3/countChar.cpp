#include <iostream>
#include <time.h>
using namespace std;

int mian() {
	srand(time(NULL));
	// 다른 난수가 생성됨
	int answer = rand() % 100;
	// 0에서 99까지의 랜덤 정수를 생성하고 answer변수에 저장
	int tries = 0;
	// 시도횟수를 추척하는 변수를 초기화

	int guess;

	do {
		cout << "정답을 추측하여 보시오: ";
		cin >> guess;
		// 값을 입력받아 guess 변수에 저장
		tries++;
		// 시도횟수 tries를 증가시킴

		if (guess > answer)
			
			cout << "제시한 정수가 높습니다" << endl;
		// 만약 guess 가 answer보다 크면 제시한 정수가 높습니다가 출력된다.
		if (guess < answer)
			cout << "제시한 정수가 낮습니다" << endl;
		//만약 guess가 answer보다 작으면 제시한 정수가 낮습니가 출력된다.

		while (guess != answer);

		cout << " 축하합니다. 시도 횟수 =" << tries << endl;
		// guess와 answer가 같으면 축하합니다. 시도횟수는 tires라는  메시지가 출력되고 루프가 종료됨
		return 0;

	}
}

