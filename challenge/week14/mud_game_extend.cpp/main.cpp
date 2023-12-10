#include "user.h"
#include <fstream> //���Ͻ�Ʈ���� ���� ���

const int mapX = 5;
const int mapY = 5;

// ����� ���� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][5], int user_x, int user_y, vector<User*>& users,
                int currentPlayer);
bool checkGoal(int map[][5], int user_x, int user_y);
void checkState(int map[][5], int user_x, int user_y, User& currentPlayer);
void readMapFromFile(int map[][mapX], const string& map, txt) 

int main() {
   
int map[mapX][mapY];
  string map = "map.txt";
readMapFromFile(map, map.txt);


cout << "�о�� ��: " << endl;
for (int i = 0; i < mapY; ++i) {
  for (int j = 0; j < mapX; ++j) {
    cout << map[i][j] << "  ";
  }
  cout << endl;
}
    // 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
   
    int user_x = 0;
    int user_y = 0;

    Magician magician;
    Warrior warrior;

    vector<User*> users = {&magician, &warrior};
    users[0]->doAttack();  // Magician�� doAttack() ȣ��
    users[1]->doAttack();  // Warrior�� doAttack() ȣ��
    int currentPlayer = 0;

 


    while (1) {
      User& currentUser = *(users[currentPlayer]);
        std::string user_input = "";

        std::cout << "���� HP: " << currentUser.GetHP() << "  ��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
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
                displayMap(map, user_x, user_y, users, currentPlayer);

                currentUser.DecreaseHP(
                    1);  // DecreaseHP�� ȣ�� ������� ü���� 1��ŭ ����
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
                displayMap(map, user_x, user_y, users, currentPlayer);

                currentUser.DecreaseHP(1);
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
                displayMap(map, user_x, user_y, users, currentPlayer);

                currentUser.DecreaseHP(1);
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
                displayMap(map, user_x, user_y, users, currentPlayer);

                currentUser.DecreaseHP(1);
            }
        }
        else if (user_input == "����") {
            displayMap(map, user_x, user_y, users, currentPlayer);

        }
        else if (user_input == "����") {
            std::cout << "�����մϴ�." << std::endl;
            break;
        }
        else {
            std::cout << "�߸��� �Է��Դϴ�." << std::endl;
            continue;
        }
       

        checkState(map, user_x, user_y, currentUser);
   
        currentPlayer = (currentPlayer + 1) % users.size();
       
        bool finish = checkGoal(map, user_x, user_y);
        if (finish == true) {
            std::cout << "�������� �����߽��ϴ�! �����մϴ�!" << std::endl;
            std::cout << "������ �����մϴ�." << std::endl;
            break;
        }

        if (currentUser.GetHP() <= 0) {  // ������� ü���� 0�����϶� 
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

// displayMap �Լ� ����
void displayMap(int map[][5], int user_x, int user_y, std::vector<User*>& users,
                int currentPlayer) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
                std::cout << " ";
                // ���� ��ġ�� ��, ���� �÷��̾ ���� ������(M)�� ����(W) ���
                if (map[i][j] == 0) {
                  if (currentPlayer == 0) {
                    std::cout << " W ";
                  } else {
                    std::cout << " M ";
                  }
                } else if (map[i][j] == 1) {
                  std::cout << "������";
                } else if (map[i][j] == 2) {
                  std::cout << "  ��  ";
                } else if (map[i][j] == 3) {
                  std::cout << " ���� ";
                } else if (map[i][j] == 4) {
                  std::cout << "������";
                }
                std::cout << "|";
            } else {
                // ���� ��ġ�� �ƴ� ���
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



bool checkGoal(int map[][5], int user_x, int user_y){
   if (map[user_y][user_x] == 4) {
       return true;
  }
   return false;
}

void checkState(int map[][5], int user_x, int user_y, User& currentPlayer) {
    switch (map[user_y][user_x]) { // &�� ����ؼ� user��ü�� ����
    case 1:
        std::cout << "�������� �ֽ��ϴ�" << std::endl;
        break;

    case 2:
        std::cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�." << std::endl;
        currentPlayer.DecreaseHP(2);  // �پ��� +

    case 3:
        std::cout << "������ �ֽ��ϴ�. HP�� 2 �þ�ϴ�." << std::endl;
        currentPlayer.DecreaseHP(-2);  // �þ�� -�ٿ���
        break;
    }
}

// ������ ���� �д� �������� ���� ó��
void readMapFromFile(int map[][mapX], const string& map, txt) { map(map.txt);
   
try {
    ifstream map(map.txt); //������ �б� ���� ifstream��ü ����
    
    if (map.is_open()) {
        throw runtime_error("������ �� �� �����ϴ�. "); //���� ���� ����ó��
    }


    for (int i = 0; i < mapY; ++i) {
        for (int j = 0; j < mapX; ++j) {
                if (!map >> map[i][j]) {
                  map.close(); //���� ����
                  throw runtime_error("���� ���¿� �����Ͽ����ϴ�");
                 
                  
                }
        }
    }
    map.close(); // ������ ����
    } 

catch(const exception&e) {
    cerr << "���� �߻�: " << e.what()<<endl; // ���� ó���� ���� �߰� �۾��� ����
    }
 }