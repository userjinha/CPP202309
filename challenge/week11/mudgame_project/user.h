// ����� Ŭ���� ����
#include <iostream>
using namespace std;


class User {
private:
    int hp;// ������� ���� �����ڴ� private


public:
    // ������: hp=20���� �ʱ�ȭ
    User();

    // ��� �Լ�(����)
    void DecreaseHP(int dec_hp); // HP�� �����ϴ� ����Լ�
    void IncreaseHP(int inc_hp); // HP�� �����ϴ� ����Լ�
    int GetHP(); // HP�� ��ȯ�ϴ� ����Լ�

};