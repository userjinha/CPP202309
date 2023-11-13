// 사용자 클래스 정의
#include <iostream>
using namespace std;


class User {
private:
    int hp;// 멤버변수 접근 지정자는 private


public:
    // 생성자: hp=20으로 초기화
    User();

    // 멤버 함수(동작)
    void DecreaseHP(int dec_hp); // HP가 감소하는 멤버함수
    void IncreaseHP(int inc_hp); // HP가 증가하는 멤버함수
    int GetHP(); // HP를 반환하는 멤버함수

};