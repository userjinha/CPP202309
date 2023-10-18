#include <iostream>
#include <string>
using namespace std;

// 문자열을 소문자로 변환하는 함수
string toLowerStr(string str) {
	string newStr = str; 
	for (char& c : newStr) {
		c = tolower(c); // 모든 문자를 소문자로 변환
	}
	return newStr; // 변환된 newStr을 반환
}

// 문자열을 대문자로 변환하는 함
string toUpperStr(string str) {
	string newStr = str;
	for (char& c : newStr) {
		c = toupper(c); // 모든 문자를 대문자로 변환
	}
	return newStr; // 변환된 newStr을 반환
}

// 두 문자열 s1과 s2를 입력으로 받아 해밍거리를 계산하는 함수 
int calcHammingDist(string s1, string s2) {
	s1 = toLowerStr(s1);
	s2 = toLowerStr(s2);
	int count = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i])
			count += 1; // 다른 문자가 나타나면 변수를 1씩 증가시킴
	}
	return count; // 해밍거리로 간주하고 반환함
}

int main() {
	string s1, s2;

	while (1) {

		cout << "DNA1: ";
		cin >> s1;
		cout << "DNA2: ";
		cin >> s2;


		if (s1.length() != s2.length()) {
			cout << "오류: 길이가 다름" << endl; // 만약 두 문자열의 길이가 다르면 메세지를 출력하고 다시시작
			continue;
		}
	
		else {
			int count = calcHammingDist(s1, s2); // 두문자열의 길이가 같은 경우 이 함수를 사용하여 해밍거리를 계산하고 count 변수에 저장
			
			cout << "해밍 거리는 " << count << endl;
			break;
		}
	}
	return 0;

}
