#include <iostream>
#include <string>
using namespace std;

const int mapX = 5; // mapX�� 5�� ����� ������ �� ����
const int mapY = 5;
int userHP = 20; // 20���� ���� ����

// ����� ���� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY); // ��ȿ�� ��ǥ���� Ȯ���ϱ� ���� �Լ�
void displayMap(int map[][mapX], int user_x, int user_y); // ���� �� ���¿� ������� ��ġ�� ����ϴ� �Լ�
bool checkGoal(int map[][mapX], int user_x, int user_y); // ���� ��ġ�� ���������� Ȯ���ϱ� ���� �Լ�
void checkState(int map[][mapX], int user_x, int user_y); // ������� ��ġ�� ���� ���¸� üũ�ϰ� �޽����� ����ϱ� ���� �Լ�

// ����  �Լ�
int main() {
	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} }; // ���� 2���� �迭 ����


	// ������ ��ġ�� ������ ����
	int user_x = 0; // ���� ��ȣ
	int user_y = 0; // ���� ��ȣ // �ʱ⿡�� (0,0)�����Ǿ� ���ӽ�������

	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

		// ������� �Է��� ������ ����
		string user_input = "";

		cout << "���� HP: " << userHP << "  ��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input;

		if (user_input == "��") {
			// TODO: ���� �� ĭ �ö󰡱�
			user_y -= 1; // ���� ���̸� user_y�� -1�� �����			
			bool inMap = checkXY(user_x, mapX, user_y, mapY); // �Լ����� ��ȯ�� ���� �����
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y += 1; // ���� false�� �� ������ ��µǰ�, user_y�� +1 �߰���
			}
			else {
				cout << "���� �� ĭ �ö󰩴ϴ�." << endl; // true�� �� ������ ��µ�
				displayMap(map, user_x, user_y); // �� �Լ� ȣ��
				userHP -= 1; // Hp-1�� ����Ͽ� ����
			}
		}
		else if (user_input == "��") {
			// TODO: �Ʒ��� �� ĭ ��������
			user_y += 1; // user_y�� +1�� ��
			bool inMap = checkXY(user_x, mapX, user_y, mapY); // �Լ��� ȣ���Ͽ� ���� ����
			if (inMap == false) { // ���� ���� flase�� 
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y -= 1;
			}
			else {
				cout << "���� �� ĭ �������ϴ�." << endl;
				displayMap(map, user_x, user_y); // �Լ��� ȣ��
				userHP -= 1; // hp-1�� �Ͽ� ����
			}
		}
		else if (user_input == "��") {
			// TODO: �������� �̵��ϱ�
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);

			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x += 1;
			}
			else {
				cout << "�������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
				userHP -= 1;
			}
		}
		else if (user_input == "��") {
			// TODO: ���������� �̵��ϱ�
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x -= 1;
			}
			else {
				cout << "���������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
				userHP -= 1;
			}
		}
		else if (user_input == "����") {
			// TODO: ���� �����ֱ� �Լ� ȣ��
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "����") {
			cout << "�����մϴ�.";
			break;
		}
		else { // �̿ܿ� �ٸ� ���ڸ� �Է½�
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue; // while���� �ٽ� �ݺ���
		}

		// ������� ��ġ ���� üũ
		checkState(map, user_x, user_y); // �� �Լ��� ȣ��

		// �������� �����ߴ��� üũ
		bool finish = checkGoal(map, user_x, user_y); // �Լ��� ȣ���Ͽ� ����
		if (finish == true) { // ture�� 
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
			cout << "������ �����մϴ�." << endl;
			break; // �� ������ ��µǰ� while���� 1�̵Ǿ� ��������
		}

		// ������� HP üũ
		if (userHP <= 0) {
			cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�. " << endl;
			cout << "������ �����մϴ�." << endl;
			break; // �� ������ ��µǰ� while�� ��������
		}

	}
	return 0;
}

// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
// ������ ����� ��ġ ����ϴ� �Լ�
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // �� �� 1ĭ ���� // user y�� userx�� ���� ���ٸ� �� �������

			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6ĭ ����
					break;
				case 1:
					cout << "������|";
					break;
				case 2:
					cout << "  ��  |"; // �� �� 2ĭ ����
					break;
				case 3:
					cout << " ���� |"; // �� �� 1ĭ ����
					break;
				case 4:
					cout << "������|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false; // checkFlag flase�� �ʱ�ȭ
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true; // ���� �� ������ �����ɽ� true �����
	}
	return checkFlag; // ����� ���� ��ȯ��
}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// ������ �����ϸ�
	if (map[user_y][user_x] == 4) {
		return true; // ���� �� ������ ������ true ��ȯ
	}
	return false; // ���� �� ������ �� ������ false ��ȯ
}




// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
// ����ڰ� ��ġ�� ����� ���¸� ����ϴ� �Լ�
void checkState(int map[][mapX], int user_x, int user_y) {

	switch (map[user_y][user_x]) {
	case 1:
		cout << "�������� �ֽ��ϴ�" << endl;
		break; // 1�� ������ �� ���� ��� �ϰ� ����
	case 2:
		cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�." << endl;
		userHP -= 2; // 2�� ������ �� ���� ����ϰ� hp-2 �� ���ǰ� ����
		break;
	case 3:
		cout << "������ �ֽ��ϴ�. HP�� 2 �þ�ϴ�." << endl;
		// 3�� ������ �� ���� ����ϰ� hP +2�� ����
		userHP += 2;
		break;
	}
}