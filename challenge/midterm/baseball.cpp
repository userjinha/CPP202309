#include <iostream>
#include <string>
using namespace std;

bool checkNumber(int randomNum);
bool checkNumber2(int userNumber);
int main() {
	int randomNum; // ����� �ϴ� 3�ڸ����� ���� ���� ����


	while (1) {
		randomNum = rand() % 900 + 100; // ������ 3�ڸ��� ����

		bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����

		// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
		if (checkNumber(randomNum) == true) {
			break;
		}
		else {
			continue;
		}
	}

	int turn = 0;
	while (1) {
		cout << turn + 1 << "��° �õ��Դϴ�. " << endl;

		int userNumber; // ����ڰ� �Է��� ���ڸ��� ���� ����



		// ����ڿ��� ���ڸ� ���� �Է¹޴� �ڵ� ���
		while (1) {
			cout << "���ڸ� ���� �Է����ּ���: ";
			cin >> userNumber;

			bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����
			// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
			if (checkNumber2(userNumber) == true) {
				break;
			}
			else {
				continue;
			}
		}

		int strike = 0; // ��Ʈ����ũ ������ �����ϴ� ����
		int ball = 0; // �� ������ �����ϴ� ����

		// TODO 2: ����� ������ ������ �ڸ����� ���ڸ� ���ϸ� ��Ʈ�� �ֱ� ���� �ڵ��� �ۼ�
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



		cout << userNumber << "�� ��� : " << strike << " ��Ʈ����ũ, " << ball << "�� �Դϴ�." << endl;

		if (strike == 3) {

			cout << "������ ������ϴ�. �����մϴ�.";
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
	bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����
	// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
	string numSt = to_string(userNumber);
	if (numSt[0] == numSt[1] || numSt[1] == numSt[2] || numSt[3] == numSt[0]) {
		cout << "�Է��� ���ڿ� �ߺ��� ���ڰ� �ֽ��ϴ�. �ٽ� �Է��ϼ���";
		return false;
	}

	if (to_string(userNumber).length() != 3) {
		cout << "�Էµ� ���ڰ� 3�ڸ� ���� �ƴմϴ�. �ٽ� �Է��ϼ���." << endl;
		return false;
	}
	else {
		return true;
	}
}