#include <iostream>
using namespace std;

int main() {
	const int numCell = 3; // numCell를 상수 3으로 초기화
	char board[numCell][numCell]{}; // 배열을 만듬
	int x, y; //사용자에게 입력받는 x, y좌표를 저장할 변수

	//보드판 초기화
	for (x = 0; x < numCell; x++)
	{
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
		// 3*3의 보드판을 만든다. 
	}

	// 게임하는 코드
	int k = 0; // 누구 차례인지 체크하기 위한 변수
	char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 문자 변수

	while (true) {
		//1. 누구 차례인지 출력
		switch (k % 2) {
		case 0:
			cout << k % 2 + 1 << "번 유저(X)의 차례입니다 ->";
			currentUser = 'X';
			break; //  k가 짝수이면(나머지가 0), X플레이어의 차례
		case 1:
			cout << k % 2 + 1 << "번 유저(0)의 차례입니다 ->";
			currentUser = '0';
			break; // K가 홀수이면(나머지가1), 0플레이어의 차례
		}
		// 2. 좌표 입력받기
		cout << "(x, y)좌표를 입력하세요: ";
		cin >> x >> y; // 문장을 출력하고 입력받은 값을 변수에 저장

		// 3. 입력받은 좌표의 유효성 체크
		if (x >= numCell || y >= numCell) {
			cout << x << ", " << y << ": ";
			cout << "x와 y둘 중 하나가 칸을 벗어납니다." << endl;
			continue; // 입력받은 값 x ,y가 하나라도 numCell보다 크면 이 문장이 출력되고 계속됨
		}
		if (board[x][y] != ' ') {
			cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
			continue; // x,y의 좌표가 공백과 다르면 이 문장이 출력되고 계속됨
		}
		// 4. 입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;

		// 5. 현재 보드 판 출력
		for (int i = 0; i < numCell; i++) {
			cout << "---|---|---" << endl;
			for (int j = 0; j < numCell; j++) {
				cout << board[i][j];
				if (j == numCell - 1) {
					break; // 만약 j가 numCell-1과 같다면 멈춤 아래 문장 출력하지 않음
				}
				cout << "  |"; //문장 출력
			}
			cout << endl;// 줄바꿈

			cout << "---|---|---" << endl; // 문장 출력
			k++; // 누구차례인지 증감

		}

		// 6. 모든 칸 다 찼는지 체크하기
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "모든 칸이 다 찼습니다. 종료합니다" << endl;
			break;


			// 7. 승자 체크하기
			bool isWin = false;

			// 7.1. 가로/세로돌 체크하기
			for (int i = 0; i < numCell; i++) {
				if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
					cout << "가로에 모두 돌이 놓였습니다!: "; // 가로에 입력받은 값에 저장된 값과 동일하면 이 문장이 출력
					isWin = true; // true로 초기화
				}
				if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
					cout << "세로에 모두 돌이 놓였습니다!: ";
					isWin = true;
				}
			}

			// 7.2 대각선돌 체크하기
			if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
				cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!";
				isWin = true; // 대각선에 입력받은 값에 저장된 값과 동일하면 이 문장이 출력
			}
			if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
				cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!";
				isWin = true;
			}
			if (isWin == true) {
				cout << "k % 2 +1" << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
				cout << "종료합니다" << endl;
				break; // 만약 ture이면 이문장이 출력되며 종료된다.
			}

		}
	}
}




