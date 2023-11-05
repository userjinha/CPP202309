#include <iostream>
#include <string>
using namespace std;

const int mapX = 5; // mapX를 5의 상수로 정의한 뒤 저장
const int mapY = 5;
int userHP = 20; // 20으로 정수 선언

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY); // 유효한 좌표인지 확인하기 위한 함수
void displayMap(int map[][mapX], int user_x, int user_y); // 현재 맵 상태와 사용자의 위치를 출력하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y); // 유저 위치가 목적지인지 확인하기 위한 함수
void checkState(int map[][mapX], int user_x, int user_y); // 사용자의 위치에 따라 상태를 체크하고 메시지를 출력하기 위한 함수

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} }; // 지도 2차원 배열 선언


	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호 // 초기에는 (0,0)설정되어 게임시작지점

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "현재 HP: " << userHP << "  명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;

		if (user_input == "상") {
			// TODO: 위로 한 칸 올라가기
			user_y -= 1; // 만약 상이면 user_y는 -1이 저장됨			
			bool inMap = checkXY(user_x, mapX, user_y, mapY); // 함수에서 반환된 값이 저장됨
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y += 1; // 만약 false면 이 문장이 출력되고, user_y에 +1 추가됨
			}
			else {
				cout << "위로 한 칸 올라갑니다." << endl; // true면 이 문장이 출력됨
				displayMap(map, user_x, user_y); // 이 함수 호출
				userHP -= 1; // Hp-1로 계산하여 저장
			}
		}
		else if (user_input == "하") {
			// TODO: 아래로 한 칸 내려가기
			user_y += 1; // user_y에 +1을 함
			bool inMap = checkXY(user_x, mapX, user_y, mapY); // 함수를 호출하여 값을 저장
			if (inMap == false) { // 만약 값이 flase면 
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y -= 1;
			}
			else {
				cout << "위로 한 칸 내려갑니다." << endl;
				displayMap(map, user_x, user_y); // 함수를 호출
				userHP -= 1; // hp-1을 하여 저장
			}
		}
		else if (user_input == "좌") {
			// TODO: 왼쪽으로 이동하기
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);

			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x += 1;
			}
			else {
				cout << "왼쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
				userHP -= 1;
			}
		}
		else if (user_input == "우") {
			// TODO: 오른쪽으로 이동하기
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x -= 1;
			}
			else {
				cout << "오른쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
				userHP -= 1;
			}
		}
		else if (user_input == "지도") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;
		}
		else { // 이외에 다른 문자를 입력시
			cout << "잘못된 입력입니다." << endl;
			continue; // while문이 다시 반복됨
		}

		// 사용자의 위치 정보 체크
		checkState(map, user_x, user_y); // 이 함수를 호출

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y); // 함수를 호출하여 저장
		if (finish == true) { // ture면 
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break; // 위 문장이 출력되고 while문이 1이되어 빠져나감
		}

		// 사용자의 HP 체크
		if (userHP <= 0) {
			cout << "HP가 0 이하가 되었습니다. 실패했습니다. " << endl;
			cout << "게임을 종료합니다." << endl;
			break; // 위 문장이 출력되고 while문 빠져나감
		}

	}
	return 0;
}

// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백 // user y와 userx의 값이 같다면 이 문장출력

			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false; // checkFlag flase로 초기화
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true; // 만약 이 조건이 충족될시 true 저장됨
	}
	return checkFlag; // 저장된 값이 반환됨
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true; // 만약 이 조건이 충족시 true 반환
	}
	return false; // 만약 이 조건이 불 충족시 false 반환
}




// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
// 사용자가 위치한 장소의 상태를 출력하는 함수
void checkState(int map[][mapX], int user_x, int user_y) {

	switch (map[user_y][user_x]) {
	case 1:
		cout << "아이템이 있습니다" << endl;
		break; // 1에 있으면 위 문장 출력 하고 멈춤
	case 2:
		cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
		userHP -= 2; // 2에 있으면 위 문장 출력하고 hp-2 로 계산되고 저장
		break;
	case 3:
		cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;
		// 3에 있으면 위 문장 출력하고 hP +2로 계산됨
		userHP += 2;
		break;
	}
}
