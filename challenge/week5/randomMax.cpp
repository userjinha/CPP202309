#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	const int numCell = 10;
	int numList[numCell][numCell];
	

	
	for (int i = 0; i <= numCell; i++) {
		for (int j = 0; i <= numCell; i++) {
			int elem = rand() % 1000;
			numList[i][j] = elem;
			cout << i << ", " << j << " : " << elem << endl;

			cout << endl;
		}
			int max; //ū ���� �����ϱ� ���� ����
			int maxI; // ū ���� �ִ� i�� �����ϱ� ���� ����
			int maxJ; // ū ���� �ִ� j�� �����ϱ� ���� ����

			
			for (int i = 0; i <= numCell; i++) {
				int j = 0;
				for (auto value : numList[i]){
				
					if (value > max) 
						max = value;
						maxI = i;
						maxJ = j;
					}
				j++;

				cout << "���� ū ���� " << max << "�̰�,";
				cout << "i�� j�� ���� " << maxI << ", " << maxJ << "�Դϴ�." << endl;
				cout << "���� ���: " << numList[maxI][maxJ] << endl;



				}
			}
	



		}
	