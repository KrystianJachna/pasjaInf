#include <iostream>
#include <list>
#include <cstdio>
#include <windows.h>
#include <conio.h>

#define SNAKE 'o'
#define FRUIT 'x'
#define EMPTY ' '

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

void ClearScreen()
{
    // Function which cleans the screen without flickering
    COORD cursorPosition;   cursorPosition.X = 0;   cursorPosition.Y = 0;   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}


enum Direction {
    UP = 1,
    DOWN = 2,
    LEFT = 3,
    RIGHT = 4
};

class Map {
private:
    char **map;
    int width;
    int height;

public:
    void drawMap() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hConsole, &cursorInfo);
        cursorInfo.bVisible = false;
        SetConsoleCursorInfo(hConsole, &cursorInfo);

        ClearScreen();
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j)
                cout << map[i][j];
            cout << endl;
        }

        cursorInfo.bVisible = true;
        SetConsoleCursorInfo(hConsole, &cursorInfo);
    }

    void setTile(int r, int c, char ch) { map[r][c] = ch; }

    char getTile(int r, int c) { return map[r][c]; }

    int mapWidth() { return width; }

    int mapHeight() { return height; }

    void spawnFruit() {
        int c, r;

        do {
        srand(time(NULL));

        c = rand() % (height - 1) + 1;
        r = rand() % (width - 1) + 1;
        } while(map[c][r] != EMPTY);

        map[c][r] = FRUIT;
    }

    bool isFruit(int r, int c) {
        return map[r][c] == FRUIT;
    }

    bool collisions(int r, int c) {return r == 0 || r == height - 1 || c == 0 || c == width - 1 || map[r][c] == SNAKE; }

    void gameOver(int snakeLength) {
        system("cls");

    cout << "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼\n";
    cout << "███▀▀▀██┼███▀▀▀███┼███▀█▄█▀███┼██▀▀▀\n";
    cout << "██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼█┼┼┼██┼██┼┼┼\n";
    cout << "██┼┼┼▄▄▄┼██▄▄▄▄▄██┼██┼┼┼▀┼┼┼██┼██▀▀▀\n";
    cout << "██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██┼┼┼\n";
    cout << "███▄▄▄██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██▄▄▄\n";
    cout << "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼\n";
    cout << "███▀▀▀███┼▀███┼┼██▀┼██▀▀▀┼██▀▀▀▀██▄┼\n";
    cout << "██┼┼┼┼┼██┼┼┼██┼┼██┼┼██┼┼┼┼██┼┼┼┼┼██┼\n";
    cout << "██┼┼┼┼┼██┼┼┼██┼┼██┼┼██▀▀▀┼██▄▄▄▄▄▀▀┼\n";
    cout << "██┼┼┼┼┼██┼┼┼██┼┼█▀┼┼██┼┼┼┼██┼┼┼┼┼██┼\n";
    cout << "███▄▄▄███┼┼┼─▀█▀┼┼─┼██▄▄▄┼██┼┼┼┼┼██▄\n";
    Sleep(2000);
    system("cls");
    cout << "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼\n";
    cout << "┼┼┼┼┼┼┼┼██┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼██┼┼┼┼┼┼┼┼┼\n";
    cout << "┼┼┼┼┼┼████▄┼┼┼▄▄▄▄▄▄▄┼┼┼▄████┼┼┼┼┼┼┼\n";
    cout << "┼┼┼┼┼┼┼┼┼▀▀█▄█████████▄█▀▀┼┼┼┼┼┼┼┼┼┼\n";
    cout << "┼┼┼┼┼┼┼┼┼┼┼█████████████┼┼┼┼┼┼┼┼┼┼┼┼\n";
    cout << "┼┼┼┼┼┼┼┼┼┼┼██▀▀▀███▀▀▀██┼┼┼┼┼┼┼┼┼┼┼┼\n";
    cout << "┼┼┼┼┼┼┼┼┼┼┼██┼┼┼███┼┼┼██┼┼┼┼┼┼┼┼┼┼┼┼\n";
    cout << "┼┼┼┼┼┼┼┼┼┼┼█████▀▄▀█████┼┼┼┼┼┼┼┼┼┼┼┼\n";
    cout << "┼┼┼┼┼┼┼┼┼┼┼┼███████████┼┼┼┼┼┼┼┼┼┼┼┼┼\n";
    cout << "┼┼┼┼┼┼┼┼▄▄▄██┼┼█▀█▀█┼┼██▄▄▄┼┼┼┼┼┼┼┼┼\n";
    cout << "┼┼┼┼┼┼┼┼▀▀██┼┼┼┼┼┼┼┼┼┼┼██▀▀┼┼┼┼┼┼┼┼┼\n";
    cout << "┼┼┼┼┼┼┼┼┼┼▀▀┼┼┼┼┼┼┼┼┼┼┼▀▀┼┼┼┼┼┼┼┼┼┼┼\n";
    cout << "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼\n";
    cout << endl << endl;
    cout << ">>>>>>>>>>     " << snakeLength - 2 << "     <<<<<<<<<<";
    }

    Map(int width = 50, int height = 20) : width(width), height(height) {
        map = new char *[height];

        for (int i = 0; i < height; ++i)
            map[i] = new char[width];

        for (int i = 0; i < height; ++i)
            for (int j = 0; j < width; ++j)
                if (i == 0 || i == height - 1)
                    map[i][j] = '-';
                else if (j == 0 || j == width - 1)
                    map[i][j] = '|';
                else
                    map[i][j] = EMPTY;

        spawnFruit();
    }

    ~Map(){
        for (int i = 0; i < height; ++i)
            delete [] map[i];
        delete [] map;
    }
};

class Snake{
private:
    int legth;
    int speed;
    list<pair<int,int>> body;
    Direction direction;

public:
    Snake(Map &m, int speed = 10) : speed(speed), legth(2) {
        body.push_front(make_pair(m.mapHeight()/2, m.mapWidth()/2));
        body.push_back(make_pair(m.mapHeight()/2 - 1, m.mapWidth()/2));

        m.setTile(body.front().first, body.front().second, SNAKE);
        m.setTile(body.back().first, body.back().second, SNAKE);
        direction = RIGHT;
    }

    bool move(Map &m) {
        int c = body.front().first;
        int r = body.front().second;

        switch (direction) {
            case UP:
                if (m.collisions(c - 1, r))
                    return false;
                if (m.isFruit(c - 1, r)) {
                    body.push_front(make_pair(c - 1, r));
                    m.setTile(body.front().first, body.front().second, SNAKE);
                    m.spawnFruit();
                    break;
                }

                body.push_front(make_pair(c - 1, r));
                m.setTile(body.front().first, body.front().second, SNAKE);
                m.setTile(body.back().first, body.back().second, EMPTY);
                body.pop_back();
                break;
            case DOWN:
                if (m.collisions(c + 1, r))
                    return false;
                if (m.isFruit(c + 1, r)) {
                    body.push_front(make_pair(c + 1, r));
                    m.setTile(body.front().first, body.front().second, SNAKE);
                    m.spawnFruit();
                    break;
                }

                body.push_front(make_pair(c + 1, r));
                m.setTile(body.front().first, body.front().second, SNAKE);
                m.setTile(body.back().first, body.back().second, EMPTY);
                body.pop_back();
                break;
            case RIGHT:
                if (m.collisions(c, r + 1))
                    return false;
                if (m.isFruit(c, r + 1)) {
                    body.push_front(make_pair(c, r + 1));
                    m.setTile(body.front().first, body.front().second, SNAKE);
                    m.spawnFruit();
                    break;
                }

                body.push_front(make_pair(c, r + 1));
                m.setTile(body.front().first, body.front().second, SNAKE);
                m.setTile(body.back().first, body.back().second, EMPTY);
                body.pop_back();
                break;
            case LEFT:
                if (m.collisions(c, r - 1))
                    return false;
                if (m.isFruit(c, r - 1)) {
                    body.push_front(make_pair(c, r - 1));
                    m.setTile(body.front().first, body.front().second, SNAKE);
                    m.spawnFruit();
                    break;
                }

                body.push_front(make_pair(c, r - 1));
                m.setTile(body.front().first, body.front().second, SNAKE);
                m.setTile(body.back().first, body.back().second, EMPTY);
                body.pop_back();
                break;
        }
        return true;
    }

    void changeDirection(Direction d) {
        direction = d;
    }
};


int main() {
    Map m;
    Snake s(m);
    m.drawMap();
    int key;

    while(s.move(m)) {
        m.drawMap();
        if(kbhit()) {
            key = getch();
            switch (key) {
                case KEY_UP:
                    s.changeDirection(UP);
                    break;
                case KEY_DOWN:
                    s.changeDirection(DOWN);
                    break;
                case KEY_LEFT:
                    s.changeDirection(LEFT);
                    break;
                case KEY_RIGHT:
                    s.changeDirection(RIGHT);
                    break;
                default:
                    break;
            }
        }
        Sleep(100);
    }

   return 0;


}
