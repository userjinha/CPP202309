#include "user.h"

const int mapX = 5;
const int mapY = 5;

// ����� ���� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][5], int user_x, int user_y, const User& user);
bool checkGoal(int map[][5], int user_x, int user_y);
void checkState(int map[][5], int user_x, int user_y, User& user);

int main() {
    // 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
    int map[mapY][5] = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    int user_x = 0;
    int user_y = 0;

    // 1. ���� ���� ��ü ���� �� hp ����
    User my_user;
    my_user.hp=20;

    while (1) {
        std::string user_input = "";

        std::cout << "���� HP: " << my_user.GetHP() << "  ��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
        std::cin >> user_input;

        if (user_input == "��") {
            user_y -= 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);
            if (inMap == false) {
                std::cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << std::endl;
                user_y += 1;
            }
            else {
                std::cout << "���� �� ĭ �ö󰩴ϴ�." << std::endl;
                displayMap(map, user_x, user_y);
                user.DecreaseHP(1); // DecreaseHP�� ȣ�� ������� ü���� 1��ŭ ����
            }
        }
        else if (user_input == "��") {
            user_y += 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);
            if (inMap == false) {
                std::cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << std::endl;
                user_y -= 1;
            }
            else {
                std::cout << "�Ʒ��� �� ĭ �������ϴ�." << std::endl;
                displayMap(map, user_x, user_y);
                user.DecreaseHP(1);
            }
        }
        else if (user_input == "��") {
            user_x -= 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);

            if (inMap == false) {
                std::cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << std::endl;
                user_x += 1;
            }
            else {
                std::cout << "�������� �̵��մϴ�." << std::endl;
                displayMap(map, user_x, user_y);
                user.DecreaseHP(1);
            }
        }
        else if (user_input == "��") {
            user_x += 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);
            if (inMap == false) {
                std::cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << std::endl;
                user_x -= 1;
            }
            else {
                std::cout << "���������� �̵��մϴ�." << std::endl;
                displayMap(map, user_x, user_y);
                user.DecreaseHP(1);
            }
        }
        else if (user_input == "����") {
            displayMap(map, user_x, user_y);
        }
        else if (user_input == "����") {
            std::cout << "�����մϴ�." << std::endl;
            break;
        }
        else {
            std::cout << "�߸��� �Է��Դϴ�." << std::endl;
            continue;
        }

        checkState(map, user_x, user_y, user);

        bool finish = checkGoal(map, user_x, user_y);
        if (finish == true) {
            std::cout << "�������� �����߽��ϴ�! �����մϴ�!" << std::endl;
            std::cout << "������ �����մϴ�." << std::endl;
            break;
        }

        if (user.GetHP() <= 0) { // ������� ü���� 0�����϶� 
            std::cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�. " << std::endl;
            std::cout << "������ �����մϴ�." << std::endl;
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
// �Ű������� User& user 
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
                    std::cout << "������|";
                    break;
                case 2:
                    std::cout << "  ��  |";
                    break;
                case 3:
                    std::cout << " ���� |";
                    break;
                case 4:
                    std::cout << "������|";
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
    switch (map[user_y][user_x]) { // &�� ����ؼ� user��ü�� ����
    case 1:
        std::cout << "�������� �ֽ��ϴ�" << std::endl;
        break;

    case 2:
        std::cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�." << std::endl;
        user.DecreaseHP(2); // �پ��� +

    case 3:
        std::cout << "������ �ֽ��ϴ�. HP�� 2 �þ�ϴ�." << std::endl;
        user.DecreaseHP(-2); // �þ�� -�ٿ���
        break;
    }
}
