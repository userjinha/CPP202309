#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User {
 public:
  int hp;
  int x;
  int y;

  void SetPosition(int pos_x, int pos_y) { x = pos_x;
    y = pos_y;
  }

  void DecreaseHP(int dec_hp);
  int GetHP();
  virtual void
  doAttack();  // �����Լ��� �����Ͽ� ��ӹ޴� Ŭ�������� ������ �� �� �ֵ���
};

class Magician : public User {
 public:
  Magician() { hp = 20; }
  void doAttack() override;  // Magician Ŭ�������� doAttack �Լ��� ������
};

class Warrior : public User {
 public:
  Warrior() { hp = 25; }
  void doAttack() override;  // Warrior Ŭ�������� doAttack�Լ��� ������
};

#endif  // USER_H