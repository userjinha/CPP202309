#include <iostream>
#include <string>
using namespace std;

int main() {
	const int maxPeople = 3;
	cout << " ~~ ";
	// cin >> maxPeople;
	string names [maxPeople];
	int ages [maxPeople];

	for (int i = 0; i < 3; i++
		) {
		cout << "��� " << i <<"�� �̸� : ";
		cin >> names[i];

		cout << "���"<< i<<"�� ���� : ";
		cin >> ages[i];

	
	} 
	
	int ageThreshold;
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���:";
	cin >> ageThreshold;
	cout << ageThreshold << "�� �̻��� ����:\n";
	int detectedPeople = 0;

	for (int j = 0; j < 3; j++)
	{
		if (ageThreshold <= ages[j]) {
			cout << names[j] << " ("<<ages[j]<<"��)\n";
			detectedPeople ++;
		}

	}
	if (detectedPeople == 0) {
		cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�";

	}
	return 0;

	

	

}