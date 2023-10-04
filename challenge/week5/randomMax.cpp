#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	const int numCell = 10;
	int numList[numCell][numCell];
	
// i, j : elem으로 출력
	for(int i =0; i <= numCell; i++) {
		for (int j = 0; i <= numCell; i++) {
			int elem = rand() % 1000;
			numList[i][j] = elem;
			cout << i << ", " << j << " : " << elem << endl;

			cout << endl;
			// 줄바꿈
		}
			int max; //큰 값을 저장하기 위한 변수
			int maxI; // 큰 값이 있는 i를 저장하기 위한 변수
			int maxJ; // 큰 값이 있는 j를 저장하기 위한 변수

			// 
			for (int i = 0; i <= numCell; i++) {
				int j = 0;
				// i의 값을 저장
				for (auto value : numList[i]){
				
					if (value > max) 
						max = value;
						maxI = i;
						maxJ = j;
					}
				j++;

				cout << "가장 큰 값은 " << max << "이고,";
				cout << "i와 j는 각각 " << maxI << ", " << maxJ << "입니다." << endl;
				cout << "검증 결과: " << numList[maxI][maxJ] << endl;



				}
			}
	



		}
	
