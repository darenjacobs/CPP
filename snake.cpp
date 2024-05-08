#include <deque>
#include <vector>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <iostream>
#include <unistd.h>     // for sleep()
#include <termios.h>    // for terminal settings
#include <thread>       // for std::this_thread::sleep_for
#include <chrono>       // for std::chrono::milliseconds
#include <fcntl.h>

class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

class Snake {
private:
    std::deque<Point> body;
    Point direction;

public:
    Snake(const Point& initPos) {
        body.push_back(initPos);
        direction = {1, 0}; // Initially moving right
    }

    void setDirection(const Point& newDirection) {
        // Prevent reverse movement
        if (direction.x + newDirection.x != 0 || direction.y + newDirection.y != 0) {
            direction = newDirection;
        }
    }

    void move() {
        Point newHead = body.front();
        newHead.x += direction.x;
        newHead.y += direction.y;
        body.push_front(newHead);
        body.pop_back();  // Remove tail piece
    }

    void grow() {
        Point newHead = body.front();
        newHead.x += direction.x;
        newHead.y += direction.y;
        body.push_front(newHead);
    }

    bool checkCollision(int width, int height) {
        Point head = body.front();
        // Check wall collision
        if (head.x < 0 || head.x >= width || head.y < 0 || head.y >= height) {
            return true;
        }
        // Check self collision
        for (auto it = body.begin() + 1; it != body.end(); ++it) {
            if (it->x == head.x && it->y == head.y) return true;
        }
        return false;
    }

    const std::deque<Point>& getBody() const {
        return body;
    }
};

class Board {
private:
    int width, height;
    Point food;
    std::vector<std::vector<bool>> matrix;

public:
    Board(int width, int height) : width(width), height(height), matrix(height, std::vector<bool>(width, false)) {
        srand(time(NULL));
        placeFood();
    }

    void placeFood() {
        do {
            food.x = rand() % width;
            food.y = rand() % height;
        } while (matrix[food.y][food.x]);
        matrix[food.y][food.x] = true;
    }

    bool isFood(const Point& pos) {
        return pos.x == food.x && pos.y == food.y;
    }

    void clearFood() {
        matrix[food.y][food.x] = false;
    }

    int getWidth() const { return width; }
    int getHeight() const { return height; }
};

class Game {
private:
    Board board;
    Snake snake;
    bool gameOver;

public:
    Game() : board(20, 20), snake({10, 10}), gameOver(false) {}

    void printBoard() {
    // Clears the console screen and move cursor to home position
    std::cout << "\033[2J\033[1;1H";
    for (int y = 0; y < board.getHeight(); ++y) {
        for (int x = 0; x < board.getWidth(); ++x) {
            Point p(x, y);
            bool isSnakePart = false;
            for (const Point& part : snake.getBody()) {
                if (part.x == x && part.y == y) {
                    isSnakePart = true;
                    break;
                }
            }
            if (isSnakePart)
                std::cout << 'S';
            else if (board.isFood(p))
                std::cout << 'F';
            else
                std::cout << '.';
        }
        std::cout << std::endl;
    }
    std::cout << "Score: " << snake.getBody().size() - 1 << std::endl;
}

    char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
            perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
            perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
            perror("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
            perror("tcsetattr ~ICANON");
        return buf;
    }

    bool kbhit() {
        struct termios oldt, newt;
        int ch;
        int oldf;

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

        ch = getchar();

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);

        if (ch != EOF) {
            ungetc(ch, stdin);
            return true;
        }

        return false;
    }

    void run() {
        system("stty raw -echo"); // Set terminal to raw mode
        while (!gameOver) {
            if (kbhit()) {
                char input = getch();
                switch (input) {
                    case 'w': snake.setDirection({0, -1}); break;
                    case 's': snake.setDirection({0, 1}); break;
                    case 'a': snake.setDirection({-1, 0}); break;
                    case 'd': snake.setDirection({1, 0}); break;
                }
            }
            snake.move();
            if (board.isFood(snake.getBody().front())) {
                snake.grow();
                board.clearFood();
                board.placeFood();
            }
            if (snake.checkCollision(board.getWidth(), board.getHeight())) {
                gameOver = true;
            }
            printBoard();
            std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Sleep for 200 milliseconds
        }
        system("stty cooked echo"); // Reset terminal to normal mode
        std::cout << "Game Over! Your final score is: " << snake.getBody().size() - 1 << std::endl;
    }
};

int main() {
    Game game;
    game.run();
    return 0;
}
