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
    #define easyV 12
    #define easyH 70
    #define midV 3
    #define midH 20
    #define hardV 1
    #define hardH 5


    using namespace std;

    void ClearScreen()
    {
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
            ClearScreen();
            system("cls");

            cout << "            KONIEC GRY!               ";
            cout << endl << endl;
            cout << ">>>>>>>>>>     pkt: " << snakeLength - 2 << "     <<<<<<<<<<";
            cout << endl << endl;
        }

        Map(int width = 100, int height = 20) : width(width), height(height) {
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
        int speed;
        list<pair<int,int>> body;
        Direction direction;

    public:
        Snake(Map &m, int speed = 10) : speed(speed) {
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
            if (direction == UP and d == DOWN ||
            direction == DOWN and d == UP ||
            direction == RIGHT and d == LEFT ||
            direction == LEFT and d == RIGHT)
                return;
            direction = d;
        }

        int getLength() { return body.size(); }
    };

    int main() {
        int sleepTimeV;
        int sleepTimeH;
        string lvl = "easy";


        while (true){
            system("cls");

            int wybor;
            cout << "MENU: " << endl;
            cout << "1. Zagraj POZIOM: " << lvl << endl;
            cout << "2. Zmiana poziomu trudnosci" << endl;
            cout << "3. Wyjscie z gry..." << endl;
            cout << endl << "Wybor: ";  cin >> wybor;

            switch(wybor) {
                case 1:
                    break;
                case 2:
                    system("cls");
                    cout << "aktualnie: " << lvl << endl << endl;
                    cout << "1. EASY" << endl;
                    cout << "2. MEDIUM" << endl;
                    cout << "3. HARD" << endl;
                    cout << "endl" << "Wybor: "; cin >> wybor;

                    if (wybor == 1) {
                        lvl = "EASY";
                        sleepTimeH = easyH;
                        sleepTimeV = easyV;
                    } else if (wybor == 2) {
                        lvl = "MEDIUM";
                        sleepTimeV = midV;
                        sleepTimeH = midH;
                    } else if (wybor == 3) {
                        lvl = "HARD";
                        sleepTimeH = hardH;
                        sleepTimeV = hardV;
                    }
                    continue;
                default:
                    return 0;
            }


            Map m;
            Snake s(m);
            m.drawMap();
            int sleepTime;
            int key;

            while (s.move(m)) {
                m.drawMap();
                if (kbhit()) {
                    key = getch();
                    switch (key) {
                        case KEY_UP:
                            s.changeDirection(UP);
                            sleepTime = sleepTimeH;
                            break;
                        case KEY_DOWN:
                            s.changeDirection(DOWN);
                            sleepTime = sleepTimeH;
                            break;
                        case KEY_LEFT:
                            s.changeDirection(LEFT);
                            sleepTime = sleepTimeV;
                            break;
                        case KEY_RIGHT:
                            s.changeDirection(RIGHT);
                            sleepTime = sleepTimeV;
                            break;
                        default:
                            break;
                    }
                }
                Sleep(sleepTime);
            }

            m.gameOver(s.getLength());
            Sleep(3000);
            system("cls");
        }
    }
