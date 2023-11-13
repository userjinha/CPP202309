// 사용자 클래스 내 함수
#include "user.h"

// 생성자: hp를 20으로 초기화
User::User() : hp(20) {
  
}

// HP가 감소하는 멤버 함수
void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

// HP가 증가하는 멤버함수
void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

// HP를 반환하는 멤버 함수
int User::GetHP() {
    return hp;
}

// hp에 따라 true 또는 false를 반환하는 함수
bool CheckUser(User user) {
    if (user.GetHP() <= 0) {
        return false;
    }
    else {
        return true;
    }
}