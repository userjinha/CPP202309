#include <iostream>
using namespace std;

int main() {
	int vowel = 0;
	int consonant = 0;
	cout << "�����ڸ� �Է��ϰ� ctrl +z�� ġ����" << endl;

	char ch;

	while (cin >> ch) {
		switch (ch) {
		case 'a': case 'e': case'i': case 'o': case 'u':
			vowel++;
			break;
		default:
			consonant++;
	}
	}



	cout << "����: " << vowel << endl;
	cout << "����: " << consonant << endl;
	return 0;


