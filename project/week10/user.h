// user.h

#include <iostream>
using namespace std;

class User {
public:
    // ������(����)
    User(int initialHP);

    // ��� �Լ�(����)
    void DecreaseHP(int dec_hp);
    int GetHP();

private:
    // ��� ����
    int hp;
};
