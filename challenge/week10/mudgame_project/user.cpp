#include "user.h"


// HP 감소하는 멤버 함수
void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

// HP를 반환하는 멤버 함수
int User::GetHP() {
    return hp;
}
