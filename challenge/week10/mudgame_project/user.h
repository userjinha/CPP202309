// user.h

#include <iostream>
using namespace std;

// ����� Ŭ���� ����
class User {
public:
    // ������(����)
    int hp;

    // ��� �Լ�(����)
    void DecreaseHP(int dec_hp); // HP�� �����ϴ� ����Լ�
    int GetHP(); //HP�� ��ȯ�ϴ� ����Լ�

private:
    // ��� ����
    int hp;
};
