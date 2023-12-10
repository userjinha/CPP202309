#include "user.h"
#include <fstream> //파일스트림을 위한 헤더

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
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


cout << "읽어온 맵: " << endl;
for (int i = 0; i < mapY; ++i) {
  for (int j = 0; j < mapX; ++j) {
    cout << map[i][j] << "  ";
  }
  cout << endl;
}
    // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
   
    int user_x = 0;
    int user_y = 0;

    Magician magician;
    Warrior warrior;

    vector<User*> users = {&magician, &warrior};
    users[0]->doAttack();  // Magician의 doAttack() 호출
    users[1]->doAttack();  // Warrior의 doAttack() 호출
    int currentPlayer = 0;

 


    while (1) {
      User& currentUser = *(users[currentPlayer]);
        std::string user_input = "";

        std::cout << "현재 HP: " << currentUser.GetHP() << "  명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
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
                displayMap(map, user_x, user_y, users, currentPlayer);

                currentUser.DecreaseHP(
                    1);  // DecreaseHP를 호출 사용자의 체력이 1만큼 감소
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
                displayMap(map, user_x, user_y, users, currentPlayer);

                currentUser.DecreaseHP(1);
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
                displayMap(map, user_x, user_y, users, currentPlayer);

                currentUser.DecreaseHP(1);
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
                displayMap(map, user_x, user_y, users, currentPlayer);

                currentUser.DecreaseHP(1);
            }
        }
        else if (user_input == "지도") {
            displayMap(map, user_x, user_y, users, currentPlayer);

        }
        else if (user_input == "종료") {
            std::cout << "종료합니다." << std::endl;
            break;
        }
        else {
            std::cout << "잘못된 입력입니다." << std::endl;
            continue;
        }
       

        checkState(map, user_x, user_y, currentUser);
   
        currentPlayer = (currentPlayer + 1) % users.size();
       
        bool finish = checkGoal(map, user_x, user_y);
        if (finish == true) {
            std::cout << "목적지에 도착했습니다! 축하합니다!" << std::endl;
            std::cout << "게임을 종료합니다." << std::endl;
            break;
        }

        if (currentUser.GetHP() <= 0) {  // 사용자의 체력이 0이하일때 
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

// displayMap 함수 수정
void displayMap(int map[][5], int user_x, int user_y, std::vector<User*>& users,
                int currentPlayer) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
                std::cout << " ";
                // 유저 위치일 때, 현재 플레이어에 따라 마법사(M)와 전사(W) 출력
                if (map[i][j] == 0) {
                  if (currentPlayer == 0) {
                    std::cout << " W ";
                  } else {
                    std::cout << " M ";
                  }
                } else if (map[i][j] == 1) {
                  std::cout << "아이템";
                } else if (map[i][j] == 2) {
                  std::cout << "  적  ";
                } else if (map[i][j] == 3) {
                  std::cout << " 포션 ";
                } else if (map[i][j] == 4) {
                  std::cout << "목적지";
                }
                std::cout << "|";
            } else {
                // 유저 위치가 아닌 경우
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



bool checkGoal(int map[][5], int user_x, int user_y){
   if (map[user_y][user_x] == 4) {
       return true;
  }
   return false;
}

void checkState(int map[][5], int user_x, int user_y, User& currentPlayer) {
    switch (map[user_y][user_x]) { // &를 사용해서 user객체를 전달
    case 1:
        std::cout << "아이템이 있습니다" << std::endl;
        break;

    case 2:
        std::cout << "적이 있습니다. HP가 2 줄어듭니다." << std::endl;
        currentPlayer.DecreaseHP(2);  // 줄어드니 +

    case 3:
        std::cout << "포션이 있습니다. HP가 2 늘어납니다." << std::endl;
        currentPlayer.DecreaseHP(-2);  // 늘어나니 -붙여줌
        break;
    }
}

// 파일을 열고 읽는 과정에서 예외 처리
void readMapFromFile(int map[][mapX], const string& map, txt) { map(map.txt);
   
try {
    ifstream map(map.txt); //파일을 읽기 위한 ifstream객체 생성
    
    if (map.is_open()) {
        throw runtime_error("파일을 열 수 없습니다. "); //파일 열기 예외처리
    }


    for (int i = 0; i < mapY; ++i) {
        for (int j = 0; j < mapX; ++j) {
                if (!map >> map[i][j]) {
                  map.close(); //파일 다음
                  throw runtime_error("파일 오픈에 실패하였습니다");
                 
                  
                }
        }
    }
    map.close(); // 파일을 닫음
    } 

catch(const exception&e) {
    cerr << "오류 발생: " << e.what()<<endl; // 예외 처리에 따른 추가 작업을 수행
    }
 }