#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	const int numCell = 10;
	int numList[numCell][numCell];

	// 배열에 랜덤수를 저장하고, 출력한다.
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell;j++) {
			int elem = rand() % 1000;
			numList[i][j] = elem;
			cout << i << ", " << j << " : " << elem << endl;


		}
	}

	cout << endl;
	int max = INT_MIN; //큰 값을 저장하기 위한 변수
	int maxI; // 큰 값이 있는 i를 저장하기 위한 변수
	int maxJ; // 큰 값이 있는 j를 저장하기 위한 변수

	
	for (int i = 0; i <= numCell; i++) {
		int j = 0;
	
		
	// for문 기반을 따라 자동으로 numlist가 value로 된다.
		for (auto value : numList[i]) {
			// value값이 max값보다 크면 max를 value로 초기화한다.
			// 그리고 maxl는 i로, maxJ는 j에서 증감됨
			if (value > max) {
				max = value;
				maxI = i;
				maxJ = j;
			}
			j++;
			
		}
		
	}
	// 다음과 같이 문장이 출력된다.
	cout << "가장 큰 값은 " << max << "이고,";
	cout << "i와 j는 각각 " << maxI << ", " << maxJ << "입니다." << endl;
	cout << "검증 결과: " << numList[maxI][maxJ] << endl;




}
