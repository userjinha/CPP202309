#include "user.h"

// HP �����ϴ� ��� �Լ�
void User::DecreaseHP(int dec_hp) { hp -= dec_hp; }

// HP�� ��ȯ�ϴ� ��� �Լ�
int User::GetHP() { return hp; }

// ���� ��� �Լ�
void User::doAttack() { std::cout << "�����մϴ�!" << endl; }

// ������ ����Լ�
void Magician::doAttack() { std::cout << "���� ���" << std::endl; }

// ���� ��� �Լ�
void Warrior::doAttack() { std::cout << "���� ���" << std::endl; }

