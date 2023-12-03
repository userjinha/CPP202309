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
  doAttack();  // 가상함수로 정의하여 상속받는 클래스에서 재정의 할 수 있도록
};

class Magician : public User {
 public:
  Magician() { hp = 20; }
  void doAttack() override;  // Magician 클래스에서 doAttack 함수를 재정의
};

class Warrior : public User {
 public:
  Warrior() { hp = 25; }
  void doAttack() override;  // Warrior 클래스에서 doAttack함수를 재정의
};

#endif  // USER_H