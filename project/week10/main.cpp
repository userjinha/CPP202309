#include "user.h"

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][5], int user_x, int user_y, const User& user);
bool checkGoal(int map[][5], int user_x, int user_y);
void checkState(int map[][5], int user_x, int user_y, User& user);

int main() {
    // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    int map[mapY][5] = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    int user_x = 0;
    int user_y = 0;

    // 1. 단일 유저 객체 생성 후 hp 세팅
    User my_user;
    my_user.hp=20;

    while (1) {
        std::string user_input = "";

        std::cout << "현재 HP: " << my_user.GetHP() << "  명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
        std::cin >> user_input;

        if (user_input == "상") {
            user_y -= 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);
            if (inMap == false) {
                std::cout << "맵을 벗어났습니다. 다시 돌아갑니다." << std::endl;
                user_y += 1;
            }
            else {
                std::cout << "위로 한 칸 올라갑니다." << std::endl;
                displayMap(map, user_x, user_y);
                user.DecreaseHP(1); // DecreaseHP를 호출 사용자의 체력이 1만큼 감소
            }
        }
        else if (user_input == "하") {
            user_y += 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);
            if (inMap == false) {
                std::cout << "맵을 벗어났습니다. 다시 돌아갑니다." << std::endl;
                user_y -= 1;
            }
            else {
                std::cout << "아래로 한 칸 내려갑니다." << std::endl;
                displayMap(map, user_x, user_y);
                user.DecreaseHP(1);
            }
        }
        else if (user_input == "좌") {
            user_x -= 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);

            if (inMap == false) {
                std::cout << "맵을 벗어났습니다. 다시 돌아갑니다." << std::endl;
                user_x += 1;
            }
            else {
                std::cout << "왼쪽으로 이동합니다." << std::endl;
                displayMap(map, user_x, user_y);
                user.DecreaseHP(1);
            }
        }
        else if (user_input == "우") {
            user_x += 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);
            if (inMap == false) {
                std::cout << "맵을 벗어났습니다. 다시 돌아갑니다." << std::endl;
                user_x -= 1;
            }
            else {
                std::cout << "오른쪽으로 이동합니다." << std::endl;
                displayMap(map, user_x, user_y);
                user.DecreaseHP(1);
            }
        }
        else if (user_input == "지도") {
            displayMap(map, user_x, user_y);
        }
        else if (user_input == "종료") {
            std::cout << "종료합니다." << std::endl;
            break;
        }
        else {
            std::cout << "잘못된 입력입니다." << std::endl;
            continue;
        }

        checkState(map, user_x, user_y, user);

        bool finish = checkGoal(map, user_x, user_y);
        if (finish == true) {
            std::cout << "목적지에 도착했습니다! 축하합니다!" << std::endl;
            std::cout << "게임을 종료합니다." << std::endl;
            break;
        }

        if (user.GetHP() <= 0) { // 사용자의 체력이 0이하일때 
            std::cout << "HP가 0 이하가 되었습니다. 실패했습니다. " << std::endl;
            std::cout << "게임을 종료합니다." << std::endl;
            break;
        }
    }
    return 0;
}

bool checkXY(int user_x, int mapX, int user_y, int mapY) {
    bool checkFlag = false;
    if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
        checkFlag = true;
    }
    return checkFlag;
}
// 매개변수에 User& user 
void displayMap(int map[][5], int user_x, int user_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
                std::cout << " USER |";
            }
            else {
                int posState = map[i][j];
                switch (posState) {
                case 0:
                    std::cout << "      |";
                    break;
                case 1:
                    std::cout << "아이템|";
                    break;
                case 2:
                    std::cout << "  적  |";
                    break;
                case 3:
                    std::cout << " 포션 |";
                    break;
                case 4:
                    std::cout << "목적지|";
                    break;
                }
            }
        }
        std::cout << std::endl;
        std::cout << " -------------------------------- " << std::endl;
    }
}

bool checkGoal(int map[][5], int user_x, int user_y) {
    if (map[user_y][user_x] == 4) {
        return true;
    }
    return false;
}

void checkState(int map[][5], int user_x, int user_y, User& user) {
    switch (map[user_y][user_x]) { // &를 사용해서 user객체를 전달
    case 1:
        std::cout << "아이템이 있습니다" << std::endl;
        break;

    case 2:
        std::cout << "적이 있습니다. HP가 2 줄어듭니다." << std::endl;
        user.DecreaseHP(2); // 줄어드니 +

    case 3:
        std::cout << "포션이 있습니다. HP가 2 늘어납니다." << std::endl;
        user.DecreaseHP(-2); // 늘어나니 -붙여줌
        break;
    }
}

