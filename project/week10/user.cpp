#include "user.h"

// ������
User::User(int initialHP) {
    hp = initialHP;
}

// HP �����ϴ� ��� �Լ�
void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

// HP�� ��ȯ�ϴ� ��� �Լ�
int User::GetHP() {
    return hp;
}