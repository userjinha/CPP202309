// user.h

#include <iostream>
using namespace std;

// 사용자 클래스 정의
class User {
public:
    // 생성자(상태)
    int hp;

    // 멤버 함수(동작)
    void DecreaseHP(int dec_hp); // HP가 감소하는 멤버함수
    int GetHP(); //HP를 반환하는 멤버함수

private:
    // 멤버 변수
    int hp;
};
