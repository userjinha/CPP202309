# include <iostream>
using namespace std;

int main() {

	int userInput;
	cout << " ������ 10�� �Է��ϼ��� (0�� �Է��ϸ� ����):";
	// ȭ�鿡 ������ 10�� �Է��ϼ��並 ����. 
	for (int i = 0 ; i < 10; i++) 
	// i�� ������ �����ϰ� 0���� �ʱ�ȭ �Ѵ�, i�� 10�̸��̿��� �ϰ�, i++�� �����������̴�.
	{
	
			cin >> userInput;
		// �Է¹��� ���� userInput�� �����Ѵ�.
			if (userInput == 0)
			{
				break;
		}
			// userinput ���� 0�̸� ����ȴ�.
			cout << "�Է°� :" << userInput << " Ƚ�� :" << i <<  endl;
			// �Է°� : ����� ���� ����, Ƚ���� i�� ���������ڸ� �����Ѵ�. 


	
	}

	cout << "���� �Ǿ����ϴ�";
	// 10���� �Ǹ� ����ȴ�.
		
	return 0;

}
    