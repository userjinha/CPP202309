#include <iostream>
using namespace std;

const int NUM_USERS = 3;
const int NUM_ITEMS = 3;

int userPreferences[NUM_USERS][NUM_ITEMS];

void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS]) {
	for (int i = 0; i < NUM_USERS; i++) {
		cout << "�����" << (i + 1) << "�� ��ȣ���� �Է��ϼ���(";
		cout << NUM_ITEMS << "���� �׸� ���� ):";
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> userPreferences[i][j];
			
		}
	}
}

void findRecommendedItems(const int preferences[NUM_USERS][NUM_ITEMS]) {

	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0;
		for (int j = 1; j < NUM_ITEMS; ++j) {
			if (preferences[i][j] > preferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}
		}

		cout << "�����" << (i + 1) << "���� ��õ�ϴ� �׸�: ";
		cout << (maxPreferenceIndex + 1) << std::endl;
	}
}


