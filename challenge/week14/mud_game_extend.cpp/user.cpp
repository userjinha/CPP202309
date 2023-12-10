#include "user.h"

// HP 감소하는 멤버 함수
void User::DecreaseHP(int dec_hp) { hp -= dec_hp; }

// HP를 반환하는 멤버 함수
int User::GetHP() { return hp; }

// 공격 출력 함수
void User::doAttack() { std::cout << "공격합니다!" << endl; }

// 마법사 출력함수
void Magician::doAttack() { std::cout << "마법 사용" << std::endl; }

// 전사 출력 함수
void Warrior::doAttack() { std::cout << "베기 사용" << std::endl; }

