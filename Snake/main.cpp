#include <iostream>
#include <list>
#include <cstdio>
#include <windows.h>
#include <conio.h>
#define SNAKE 'o'
#define FRUIT 'x'
#define EMPTY '\0'

using namespace std;

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
    Map(int width = 50, int height = 20) : width(width), height(height){
        map = new char *[height];

        for (int i = 0; i < height; ++i)
            map[i] = new char [width];

        for (int i = 0; i < height; ++i)
            for (int j = 0; j < width; ++j)
                if (i == 0 || i == height - 1)
                    map[i][j] = '-';
                else if (j == 0 || j == width - 1)
                    map[i][j] = '|';
                else
                    map[i][j] = EMPTY;
    }

    void drawMap() {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j)
                cout << map[i][j];
            cout << endl;
        }
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
                body.pop_back();
                m.setTile(body.back().first, body.back().second, EMPTY);
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
                body.pop_back();
                m.setTile(body.back().first, body.back().second, EMPTY);
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
                body.pop_back();
                m.setTile(body.back().first, body.back().second, EMPTY);
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
                body.pop_back();
                m.setTile(body.back().first, body.back().second, EMPTY);
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
    clrscr();
    m.drawMap();
    m.drawMap();
/*
    while(s.move(m)) {
        m.drawMap();
        if (_kbhit()) {
            int key = _getch();
            if (key == 224) {
                key = _getch();
                if (key == 75)
                    s.changeDirection(LEFT);
                else if (key == 77)
                    s.changeDirection(RIGHT);
                else if (key == 72)
                    s.changeDirection(UP);
                else if (key == 80)
                    s.changeDirection(DOWN);

            }
        }
        Sleep(1000);
    }

   return 0;

   */
}
