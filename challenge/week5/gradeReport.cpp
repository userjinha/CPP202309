#include <iostream>
#include <string>
using namespace std;

int main() {
	// �迭�� 5�� 3���� �ʱ�ȭ
	const int STUDENT = 5;
	const int SUBJECT = 3;
	int scores[STUDENT][SUBJECT];
	// �迭�� �ʱ�ȭ
	string studentNames[STUDENT] =
	{ "����", "����","ö��","�̹�", "����" };
	// �迭�� �ʱ�ȭ
	string subjectNames[STUDENT]
		= { "����", "����", "CPP" };

	
	for (int i = 0; i < STUDENT; i++) {
	// ������ ������ �ϳ��� �Է��ϼ��䰡 ��µȴ�.
		cout << studentNames[i]
			<< "�� ������ �ϳ��� �Է��ϼ���." << endl;
		
		// ������ ������ �Էµȴ�.
		for (int j = 0; j < SUBJECT; j++) {
			cout << subjectNames[j] << ":";
			cin >> scores[i][j];
		}
	}

	
	for (int i = 0; i < STUDENT; i++) {
		// ������ ��������� ��µ�
		cout << studentNames[i] << "�� ��� ������ ";

		double sum = 0;
		double average = 0;
		// for���� ���� ������ ������
		for (int j = 0; j < SUBJECT; j++) {
			sum += scores[i][j];
		}
		// ���������� ����� �ʱ�ȭ�ǰ�
		average = sum / SUBJECT;
		// ����� ��µȴ�.
		cout << average << "�Դϴ�" << endl;
	}
	return 0;
}