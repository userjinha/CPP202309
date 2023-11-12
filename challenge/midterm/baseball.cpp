#include <iostream>
#include <string>
using namespace std;

bool checkNumber(int randomNum);
bool checkNumber2(int userNumber);
int main() {
	int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수


	while (1) {
		randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성

		bool same = false; // 모든 수가 다를 경우 true를 갖는 변수

		// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
		if (checkNumber(randomNum) == true) {
			break;
		}
		else {
			continue;
		}
	}

	int turn = 0;
	while (1) {
		cout << turn + 1 << "번째 시도입니다. " << endl;

		int userNumber; // 사용자가 입력한 세자리수 저장 변수



		// 사용자에게 세자리 수를 입력받는 코드 블록
		while (1) {
			cout << "세자리 수를 입력해주세요: ";
			cin >> userNumber;

			bool same = false; // 모든 수가 다를 경우 true를 갖는 변수
			// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
			if (checkNumber2(userNumber) == true) {
				break;
			}
			else {
				continue;
			}
		}

		int strike = 0; // 스트라이크 갯수를 저장하는 변수
		int ball = 0; // 볼 갯수를 저장하는 변수

		// TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록 작성
		string numStr = to_string(randomNum);
		string numSt = to_string(userNumber);


		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (numStr[i] == numSt[j]) {
					if (i == j) {
						strike++;
					}
					else {
						ball++;
					}
				}
			}
		}



		cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << "볼 입니다." << endl;

		if (strike == 3) {

			cout << "정답을 맞췄습니다. 축하합니다.";
			break;
		}

		turn += 1;
	}

	return 0;
}

bool checkNumber(int randomNum) {
	string numStr = to_string(randomNum);
	bool same = false;
	if (numStr[0] == numStr[1] || numStr[1] == numStr[2] || numStr[2] == numStr[0]) {
		return false;
	}
	else {
		same = true;
	}
	return same;
}

bool checkNumber2(int userNumber) {
	bool same = false; // 모든 수가 다를 경우 true를 갖는 변수
	// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
	string numSt = to_string(userNumber);
	if (numSt[0] == numSt[1] || numSt[1] == numSt[2] || numSt[3] == numSt[0]) {
		cout << "입력한 숫자에 중복된 숫자가 있습니다. 다시 입력하세요";
		return false;
	}

	if (to_string(userNumber).length() != 3) {
		cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
		return false;
	}
	else {
		return true;
	}
}