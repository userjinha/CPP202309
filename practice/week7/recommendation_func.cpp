
#include <iostream>
using namespace std;

const int NUM_USERS = 3; //상수로 선언한뒤 3으로 초기화
const int NUM_ITEMS = 3; 

int userPreferences[NUM_USERS][NUM_ITEMS]; // 유저 선호도를 2차원 배열로 초기화

// 사용자의 초기 선호도를 입력하는 역할을 하는 함수
void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS]) {
	
	// 사용자 선호도로 2차원 배열 초기화
	for (int i = 0; i < NUM_USERS; i++) {
		cout << "사용자" << (i + 1) << "의 선호도를 입력하세요("; 
		cout << NUM_ITEMS << "개의 항목에 대해 ):";
		for (int j = 0; j < NUM_ITEMS; ++j) {  
			cin >> userPreferences[i][j]; // 입력받은 값을 for문을 돌아서 userPreferences에 저장
		}
	}
}

// 사용자 별로 추천 항목을 찾아서 출력하는 역할을 하는 함수
void findRecommendedItems(const int preferences[NUM_USERS][NUM_ITEMS]) {

	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0; // maxPre 는 0으로 초기화
		for (int j = 1; j < NUM_ITEMS; ++j) {
			if (preferences[i][j] > preferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;  // 만약 [i][j]가 [i][maxPre]보다 크다면  j의 값으로 초기화한다.
			}
		}

		// 사용자에게 추천한는 항목 출력
		cout << "사용자" << (i + 1) << "에게 추천하는 항목: ";
		cout << (maxPreferenceIndex + 1) << std::endl;
	}
}


