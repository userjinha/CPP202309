#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	int count = 0;

	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	if (s1.length() != s2.length())
		cout << "오류: 길이가 다름" << endl; // 두 문자열 길이가 다르면 오류 출력
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				count += 1; // 두 문자가 서로 다른경우 변수를 1씩 증가
		}
		cout << "해밍 거리는 " << count << endl; // 저장된 값을 해밍거리로 간주하고 메시지 출력
	}

	return 0;

}

