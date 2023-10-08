#include <iostream>
#include <string>
using namespace std;

int main() {
	// 배열을 5와 3으로 초기화
	const int STUDENT = 5;
	const int SUBJECT = 3;
	int scores[STUDENT][SUBJECT];
	// 배열을 초기화
	string studentNames[STUDENT] =
	{ "영수", "영희","철수","미미", "쥬쥬" };
	// 배열을 초기화
	string subjectNames[STUDENT]
		= { "수학", "영어", "CPP" };

	
	for (int i = 0; i < STUDENT; i++) {
	// 영수의 성적을 하나씩 입력하세요가 출력된다.
		cout << studentNames[i]
			<< "의 성적을 하나씩 입력하세요." << endl;
		
		// 영수의 점수가 입력된다.
		for (int j = 0; j < SUBJECT; j++) {
			cout << subjectNames[j] << ":";
			cin >> scores[i][j];
		}
	}

	
	for (int i = 0; i < STUDENT; i++) {
		// 영수의 평균점수는 출력됨
		cout << studentNames[i] << "의 평균 점수는 ";

		double sum = 0;
		double average = 0;
		// for문에 따라 점수가 더해짐
		for (int j = 0; j < SUBJECT; j++) {
			sum += scores[i][j];
		}
		// 최종적으로 평균이 초기화되고
		average = sum / SUBJECT;
		// 평균이 출력된다.
		cout << average << "입니다" << endl;
	}
	return 0;
}