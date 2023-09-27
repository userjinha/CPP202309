#include <iostream>
#include <string>
using namespace std;

int main() {
	const int maxPeople = 3;
	// maXPeople을 3으로 선언한다.
	cout << " ~~ ";
	// cin >> maxPeople;

	string names [maxPeople];
	int ages [maxPeople];

	// i를 0으로 초기화 하고, i는 3보다 작게한다.
	for (int i = 0; i < 3; i++
		) {
		cout << "사람 " << i <<"의 이름 : ";
		cin >> names[i];

		cout << "사람"<< i<<"의 나이 : ";
		cin >> ages[i];

	
	} 

	
	int ageThreshold;
	cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요:";
	cin >> ageThreshold;
	cout << ageThreshold << "세 이상인 고객들:\n";
	int detectedPeople = 0;

	// j를 0으로 초기화 하고, j는 3보다 작게하고, j는 증감된다.
	for (int j = 0; j < 3; j++)
	{
		// ageThreshold를 age보다 작거나 크게된다면 출력된다.
		if (ageThreshold <= ages[j]) {
			cout << names[j] << " ("<<ages[j]<<"세)\n";
			detectedPeople ++;
		}

	}
	// 만약 detectedPeople이 0과 같다면 출력된다.
	if (detectedPeople == 0) {
		cout << ageThreshold << "이상의 나이를 가진 고객이 없습니다";

	}
	return 0;

	

	

}
