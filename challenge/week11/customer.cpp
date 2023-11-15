#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int maxPeople;
	cout << "총 고객의 수를 입력하라: ";
	cin >> maxPeople;

	vector<string> names;
	vector <int> ages;
	for (int i = 0; i < maxPeople; i++) {
		string name;
		int age;

		cout << "사람 " << i + 1 << "의 이름: ";
		cin >> name;
		names.push_back(name); // push_back함수를 사용하여 동적 배열의 크기를 자동으로 조정

		cout << "사람 " << i + 1 << "의 나이: ";
		cin >> age;
		ages.push_back(age); 
	}

	int ageThreshold;
	cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요:";
	cin >> ageThreshold;
	cout << ageThreshold << "세 이상인 고객들:\n";
	int detectedPeople = 0;

	
	for (int j = 0; j < ages.size(); j++) // ages.size()는 벡터의 현재 크기를 반환하는 함수
	{
		// ageThreshold를 age보다 작거나 크게된다면 출력된다.
		//if (ageThreshold <= ages[j])
		if (j < names.size() && ageThreshold <= ages[j]) {
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
