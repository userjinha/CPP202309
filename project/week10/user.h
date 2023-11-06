// user.h

#include <iostream>
using namespace std;

class User {
public:
    // 생성자(상태)
    User(int initialHP);

    // 멤버 함수(동작)
    void DecreaseHP(int dec_hp);
    int GetHP();

private:
    // 멤버 변수
    int hp;
};
