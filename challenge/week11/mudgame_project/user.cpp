// ����� Ŭ���� �� �Լ�
#include "user.h"

// ������: hp�� 20���� �ʱ�ȭ
User::User() : hp(20) {
  
}

// HP�� �����ϴ� ��� �Լ�
void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

// HP�� �����ϴ� ����Լ�
void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

// HP�� ��ȯ�ϴ� ��� �Լ�
int User::GetHP() {
    return hp;
}

// hp�� ���� true �Ǵ� false�� ��ȯ�ϴ� �Լ�
bool CheckUser(User user) {
    if (user.GetHP() <= 0) {
        return false;
    }
    else {
        return true;
    }
}