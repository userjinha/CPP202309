#include <iostream>
using namespace std;

bool isValid(int x, int y, int numCell, char board[5][5]);
int checkWin(int numCell, char board[5][5], char currentUser);

int main() {
	// ������ �����ϴ� �� �ʿ��� ���� ����

	const int numCell = 5; // �������� ���� ���� ����
	int k = 0; // ���� �������� üũ�ϱ� ���� ����
	char currentUser = 'X'; // ���� ������ ���� �����ϱ� ���� ����
	char board[numCell][numCell]{}; // �������� ��Ÿ���� 2���� �迭
	int x = 0;
	int y = 0; // ����ڿ��� xy��ǥ���� �Է¹ޱ� ���� ����

	// ������ �ʱ�ȭ
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// ������ ���� �ݺ�
	while (true) {
		// 1. ���� �������� ���
		// TODO 1.1: 3�ο� �������� ����
		switch (k % 3) {
		case 0:
			currentUser = 'X';
			break;
		case 1:
			currentUser = 'O';
			break;
		case 2:
			currentUser = 'H';
		}
		cout << k % 3 + 1 << "�� ����(" << currentUser << ")�� �����Դϴ�. -> ";


		// 2. ��ǥ �Է� �ޱ�
		cout << "(x, y) ��ǥ�� �Է��ϼ���: ";
		int x, y;
		cin >> x >> y;

		// 3. �Է¹��� ��ǥ�� ��ȿ�� üũ
		// TODO FUNC 1: isValid �Լ� ���� �� ȣ��

		if (false == isValid(x, y, numCell, board)) {
			cout << x << "," << y << ": x�� y�� �� �ϳ��� ĭ�� ����ϴ�. " << endl;
			continue;
		}
		if (true == isValid(x, y, numCell, board)) {
			cout << x << "," << y << ": �̹� ���� ���ֽ��ϴ�. " << endl;
			continue;
		}





		// 4. �Է¹��� ��ǥ�� ���� ������ �� ����
		board[x][y] = currentUser;

		// 5. ���� ���� �� ���
		// TODO 1.2: numCell ���ڿ� ���� ������ ���


		for (int i = 0; i < numCell; i++) {
			cout << "---|---|---|---|---" << endl;
			for (int j = 0; j < numCell; j++)
			{
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  |";
			}
			cout << endl;
		}
		cout << "---|---|---|---|---" << endl;



		bool isWin = false; // �¸� ����
		// TODO FUNC2: 6.1���� 6.2���� checkWin �Լ� ���� �� ȣ��



	   // 6.1. ����/���� �� üũ�ϱ�

		if (0 == checkWin(numCell, board, currentUser)) {
			cout << "���ο� ��� ���� �������ϴ�!!";
			isWin = true;
			break;
		}

		if (1 == checkWin(numCell, board, currentUser)) {
			cout << "���ο� ��� ���� �������ϴ�!!";
			isWin = true;
			break;
		}

		if (2 == checkWin(numCell, board, currentUser)) {
			cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
			isWin = true;
			break;
		}

		if (3 == checkWin(numCell, board, currentUser)) {
			cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
			isWin = true;
			break;
		}

		// �¸��ڰ� �����Ǿ����� �ش� �÷��̾ ����ϰ� ������ �����Ѵ�.
		if (isWin == true) {
			cout << k % 2 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
			break;
		}

		// 7. ��� ĭ �� á���� üũ�ϱ�
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "��� ĭ�� �� á���ϴ�.  �����մϴ�. " << endl;
			break;
		}

		k++;
	}
	return 0;
}

bool isValid(int x, int y, int numCell, char board[5][5]) {
	if (x >= numCell || y >= numCell) {
		return false;
	}
	if (board[x][y] != ' ')
		return true;
}

int checkWin(int numCell, char board[5][5], char currentUser) {

	for (int i = 0; i < numCell; i++) {
		if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser && board[i][3] == currentUser && board[i][4] == currentUser) {
			return 0;
		}
		if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser && board[3][i] == currentUser && board[4][i] == currentUser) {
			return 1;
		}
	}

	// 6.2. �밢���� üũ�ϱ�
	bool leftDiagonalWin = true;
	bool rightDiagonalWin = true;

	// ���� �밢�� üũ
	for (int i = 0; i < numCell; i++) {
		if (board[i][i] != currentUser) {
			leftDiagonalWin = false;
			break; // �ϳ��� �ٸ��� �� �̻� üũ�� �ʿ䰡 ����
		}
	}

	// ������ �밢�� üũ
	for (int i = 0; i < numCell; i++) {
		if (board[i][numCell - 1 - i] != currentUser) {
			rightDiagonalWin = false;
			break; // �ϳ��� �ٸ��� �� �̻� üũ�� �ʿ䰡 ����
		}
	}

	if (leftDiagonalWin) {
		return 2; // ���� �밢�� �¸�
	}

	if (rightDiagonalWin) {
		return 3; // ������ �밢�� �¸�
	}

}

