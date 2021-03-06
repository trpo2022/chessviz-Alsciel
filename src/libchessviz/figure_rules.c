#include <libchessviz/chessviz.h>

extern int w_pass;
extern int w_x;
extern int b_pass;
extern int b_x;

int CheckWhite(char board[boardsize][boardsize])
{
    int k1 = -1;
    int k2 = -1;
    for (int i = 0; i < boardsize; i++) {
        for (int j = 0; j < boardsize; j++) {
            if (board[i][j] == 'K') {
                k1 = i;
                k2 = j;
                break;
            }
        }
    }
    for (int i = 0; i < boardsize; i++) {
        for (int j = 0; j < boardsize; j++) {
            int x;
            int y;
            int q1;
            int q2;
            int flag = 0;
            switch (board[i][j]) {
            case 'q':
                x = 0;
                y = 0;
                q1 = i;
                q2 = j;
                if (abs(q1 - k1) == abs(q2 - k2)) {
                    x = (k1 - q1) / abs(q1 - k1);
                    y = (k2 - q2) / abs(q2 - k2);
                }
                if (i == k1) {
                    y = (k2 - q2) / abs(q2 - k2);
                }
                if (j == k2) {
                    x = (k1 - q1) / abs(q1 - k1);
                }
                while ((q1 != k1 || q2 != k2)
                       && ((x != 0 && q2 == k2) || (y != 0 && q1 == k1)
                           || (y != 0 && x != 0))) {
                    q1 += x;
                    q2 += y;
                    if (board[q1][q2] != ' ') {
                        flag++;
                    }
                }
                if (flag == 1) {
                    return 1;
                }
                break;
            case 'b':
                x = 0;
                y = 0;
                q1 = i;
                q2 = j;
                if (abs(q1 - k1) == abs(q2 - k2)) {
                    x = (k1 - q1) / abs(q1 - k1);
                    y = (k2 - q2) / abs(q2 - k2);
                }
                while ((q1 != k1 && q2 != k2) && (y != 0 && x != 0)) {
                    q1 += x;
                    q2 += y;
                    if (board[q1][q2] != ' ') {
                        flag++;
                    }
                }
                if (flag == 1) {
                    return 1;
                }
                break;
            case 'r':
                x = 0;
                y = 0;
                q1 = i;
                q2 = j;
                if (i == k1) {
                    y = (k2 - q2) / abs(q2 - k2);
                }
                if (j == k2) {
                    x = (k1 - q1) / abs(q1 - k1);
                }
                while ((q1 != k1 || q2 != k2)
                       && ((x != 0 && q2 == k2) || (y != 0 && q1 == k1))) {
                    q1 += x;
                    q2 += y;
                    if (board[q1][q2] != ' ') {
                        flag++;
                    }
                }
                if (flag == 1) {
                    return 1;
                }
                break;
            case 'n':
                x = 0;
                y = 0;
                x = abs(k1 - i);
                y = abs(k2 - j);
                if ((x == 2 && y == 1) || (x == 1 && y == 2)) {
                    return 1;
                }
                break;
            case 'p':
                x = 0;
                y = 0;
                x = i - k1;
                y = abs(j - k2);
                if (y == 1 && x == 1) {
                    return 1;
                }
                break;
            }
        }
    }
    return 0;
}

int CheckBlack(char board[boardsize][boardsize])
{
    int k1 = -1;
    int k2 = -1;
    for (int i = 0; i < boardsize; i++) {
        for (int j = 0; j < boardsize; j++) {
            if (board[i][j] == 'k') {
                k1 = i;
                k2 = j;
                break;
            }
        }
    }
    for (int i = 0; i < boardsize; i++) {
        for (int j = 0; j < boardsize; j++) {
            int x;
            int y;
            int q1;
            int q2;
            int flag = 0;
            switch (board[i][j]) {
            case 'Q':
                x = 0;
                y = 0;
                q1 = i;
                q2 = j;
                if (abs(q1 - k1) == abs(q2 - k2)) {
                    x = (k1 - q1) / abs(q1 - k1);
                    y = (k2 - q2) / abs(q2 - k2);
                }
                if (i == k1) {
                    y = (k2 - q2) / abs(q2 - k2);
                }
                if (j == k2) {
                    x = (k1 - q1) / abs(q1 - k1);
                }
                while ((q1 != k1 || q2 != k2)
                       && ((x != 0 && q2 == k2) || (y != 0 && q1 == k1)
                           || (y != 0 && x != 0))) {
                    q1 += x;
                    q2 += y;
                    if (board[q1][q2] != ' ') {
                        flag++;
                    }
                }
                if (flag == 1) {
                    return 1;
                }
                break;
            case 'B':
                x = 0;
                y = 0;
                q1 = i;
                q2 = j;
                if (abs(q1 - k1) == abs(q2 - k2)) {
                    x = (k1 - q1) / abs(q1 - k1);
                    y = (k2 - q2) / abs(q2 - k2);
                }
                while ((q1 != k1 && q2 != k2) && (y != 0 && x != 0)) {
                    q1 += x;
                    q2 += y;
                    if (board[q1][q2] != ' ') {
                        flag++;
                    }
                }
                if (flag == 1) {
                    return 1;
                }
                break;
            case 'R':
                x = 0;
                y = 0;
                q1 = i;
                q2 = j;
                if (i == k1) {
                    y = (k2 - q2) / abs(q2 - k2);
                }
                if (j == k2) {
                    x = (k1 - q1) / abs(q1 - k1);
                }
                while ((q1 != k1 || q2 != k2)
                       && ((x != 0 && q2 == k2) || (y != 0 && q1 == k1))) {
                    q1 += x;
                    q2 += y;
                    if (board[q1][q2] != ' ') {
                        flag++;
                    }
                }
                if (flag == 1) {
                    return 1;
                }
                break;
            case 'N':
                x = 0;
                y = 0;
                x = abs(k1 - i);
                y = abs(k2 - j);
                if ((x == 2 && y == 1) || (x == 1 && y == 2)) {
                    return 1;
                }
                break;
            case 'P':
                x = 0;
                y = 0;
                x = k1 - i;
                y = abs(j - k2);
                if (y == 1 && x == 1) {
                    return 1;
                }
                break;
            }
        }
    }
    return 0;
}

void WhitePawn(char board[boardsize][boardsize], char w[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (w[1] >= '1' && w[1] <= '8' && w[2] == '-' && w[3] >= 'a' && w[3] <= 'h'
        && w[4] >= '1' && w[4] <= '8' && (w[5] == '\0' || w[5] == '#')) {
        x1 = ParseX(w[0]);
        y1 = ParseY(w[1]);
        x2 = ParseX(w[3]);
        y2 = ParseY(w[4]);
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'P' && flag == 0) {
        flag = 1;
    }
    if ((x1 == x2 && y1 + 1 == y2) || (x1 == x2 && y1 == 1 && y2 == 3)
        || (board[y2][x2] == 'p' && y1 + 1 == y2
            && (x1 + 1 == x2 || x1 - 1 == x2))
        || (board[y2 - 1][x2] == 'p' && y1 + 1 == y2
            && (x1 + 1 == x2 || x1 - 1 == x2) && w_pass == 1 && w_x == x2)) {
        //(Move||Move from 6 to 4 line||Take||En passant)
        if (flag == 0) {
            board[y1][x1] = ' ';
            board[y2][x2] = 'P';
            if (board[y2 - 1][x2] == 'p' && y1 + 1 == y2
                && (x1 + 1 == x2 || x1 - 1 == x2) && w_pass == 1 && w_x == x2) {
                board[y2 - 1][x2] = ' ';
            }
            PrintBoard(board);
        }
    } else {
        flag = 1;
    }
    if (flag != 0) {
        ErrorCode(3);
    } else {
        if (x1 == x2 && y1 == 1 && y2 == 3) {
            b_pass = 1;
            b_x = x2;
        }
    }
}

void BlackPawn(char board[boardsize][boardsize], char b[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (b[1] >= '1' && b[1] <= '8' && b[2] == '-' && b[3] >= 'a' && b[3] <= 'h'
        && b[4] >= '1' && b[4] <= '8' && (b[5] == '\0' || b[5] == '#')) {
        x1 = ParseX(b[0]);
        y1 = ParseY(b[1]);
        x2 = ParseX(b[3]);
        y2 = ParseY(b[4]);

    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'p' && flag == 0) {
        flag = 1;
    }
    if ((x1 == x2 && y1 - 1 == y2) || (x1 == x2 && y1 == 6 && y2 == 4)
        || (board[y2][x2] == 'P' && y1 - 1 == y2
            && (x1 + 1 == x2 || x1 - 1 == x2))
        || (board[y2 + 1][x2] == 'P' && y1 - 1 == y2
            && (x1 + 1 == x2 || x1 - 1 == x2) && b_pass == 1 && b_x == x2)) {
        if (flag == 0) {
            board[y1][x1] = ' ';
            board[y2][x2] = 'p';
            if (board[y2 + 1][x2] == 'P' && y1 - 1 == y2
                && (x1 + 1 == x2 || x1 - 1 == x2) && b_pass == 1 && b_x == x2) {
                board[y2 + 1][x2] = ' ';
            }
            PrintBoard(board);
        }
    } else {
        flag = 1;
    }
    if (flag != 0) {
        ErrorCode(3);
    } else {
        if (x1 == x2 && y1 == 6 && y2 == 4) {
            w_pass = 1;
            w_x = x2;
        }
    }
}

void WhiteKing(char board[boardsize][boardsize], char w[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (w[1] >= 'a' && w[1] <= 'h' && w[2] >= '1' && w[2] <= '8' && w[3] == '-'
        && w[4] >= 'a' && w[4] <= 'h' && w[5] >= '1' && w[5] <= '8'
        && (w[6] == '\0' || w[6] == '#')) {
        x1 = ParseX(w[1]);
        y1 = ParseY(w[2]);
        x2 = ParseX(w[4]);
        y2 = ParseY(w[5]);
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'K') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if ((xs == 1 && ys == 1) || (xs == 0 && ys == 1)
            || (xs == 1 && ys == 1)) {
            char mas[boardsize][boardsize];
            for (int i = 0; i < boardsize; i++) {
                for (int j = 0; j < boardsize; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'K';
            if (!CheckWhite(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'K';
        PrintBoard(board);
    } else {
        ErrorCode(3);
    }
}
void BlackKing(char board[boardsize][boardsize], char b[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (b[1] >= 'a' && b[1] <= 'h' && b[2] >= '1' && b[2] <= '8' && b[3] == '-'
        && b[4] >= 'a' && b[4] <= 'h' && b[5] >= '1' && b[5] <= '8'
        && (b[6] == '\0' || b[6] == '#')) {
        x1 = ParseX(b[1]);
        y1 = ParseY(b[2]);
        x2 = ParseX(b[4]);
        y2 = ParseY(b[5]);
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'k') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if ((xs == 1 && ys == 1) || (xs == 0 && ys == 1)
            || (xs == 1 && ys == 1)) {
            char mas[boardsize][boardsize];
            for (int i = 0; i < boardsize; i++) {
                for (int j = 0; j < boardsize; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'K';
            if (!CheckBlack(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'k';
        PrintBoard(board);
    } else {
        ErrorCode(3);
    }
}

void WhiteRook(char board[boardsize][boardsize], char w[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (w[1] >= 'a' && w[1] <= 'h' && w[2] >= '1' && w[2] <= '8' && w[3] == '-'
        && w[4] >= 'a' && w[4] <= 'h' && w[5] >= '1' && w[5] <= '8'
        && (w[6] == '\0' || w[6] == '#')) {
        x1 = ParseX(w[1]);
        y1 = ParseY(w[2]);
        x2 = ParseX(w[4]);
        y2 = ParseY(w[5]);
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'R') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if (xs == 0 || ys == 0) {
            char mas[boardsize][boardsize];
            for (int i = 0; i < boardsize; i++) {
                for (int j = 0; j < boardsize; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'R';
            if (!CheckWhite(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'R';
        PrintBoard(board);
    } else {
        ErrorCode(3);
    }
}
void BlackRook(char board[boardsize][boardsize], char b[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (b[1] >= 'a' && b[1] <= 'h' && b[2] >= '1' && b[2] <= '8' && b[3] == '-'
        && b[4] >= 'a' && b[4] <= 'h' && b[5] >= '1' && b[5] <= '8'
        && (b[6] == '\0' || b[6] == '#')) {
        x1 = ParseX(b[1]);
        y1 = ParseY(b[2]);
        x2 = ParseX(b[4]);
        y2 = ParseY(b[5]);
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'r') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if (xs == 0 || ys == 0) {
            char mas[boardsize][boardsize];
            for (int i = 0; i < boardsize; i++) {
                for (int j = 0; j < boardsize; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'r';
            if (!CheckBlack(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'r';
        PrintBoard(board);
    } else {
        ErrorCode(3);
    }
}

void WhiteBishop(char board[boardsize][boardsize], char w[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (w[1] >= 'a' && w[1] <= 'h' && w[2] >= '1' && w[2] <= '8' && w[3] == '-'
        && w[4] >= 'a' && w[4] <= 'h' && w[5] >= '1' && w[5] <= '8'
        && (w[6] == '\0' || w[6] == '#')) {
        x1 = ParseX(w[1]);
        y1 = ParseY(w[2]);
        x2 = ParseX(w[4]);
        y2 = ParseY(w[5]);
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'B') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if (xs == ys) {
            char mas[boardsize][boardsize];
            for (int i = 0; i < boardsize; i++) {
                for (int j = 0; j < boardsize; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'B';
            if (!CheckWhite(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'B';
        PrintBoard(board);
    } else {
        ErrorCode(3);
    }
}
void BlackBishop(char board[boardsize][boardsize], char b[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (b[1] >= 'a' && b[1] <= 'h' && b[2] >= '1' && b[2] <= '8' && b[3] == '-'
        && b[4] >= 'a' && b[4] <= 'h' && b[5] >= '1' && b[5] <= '8'
        && (b[6] == '\0' || b[6] == '#')) {
        x1 = ParseX(b[1]);
        y1 = ParseY(b[2]);
        x2 = ParseX(b[4]);
        y2 = ParseY(b[5]);
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'b') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if (xs == ys) {
            char mas[boardsize][boardsize];
            for (int i = 0; i < boardsize; i++) {
                for (int j = 0; j < boardsize; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'b';
            if (!CheckBlack(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'b';
        PrintBoard(board);
    } else {
        ErrorCode(3);
    }
}

void WhiteKnight(char board[boardsize][boardsize], char w[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (w[1] >= 'a' && w[1] <= 'h' && w[2] >= '1' && w[2] <= '8' && w[3] == '-'
        && w[4] >= 'a' && w[4] <= 'h' && w[5] >= '1' && w[5] <= '8'
        && (w[6] == '\0' || w[6] == '#')) {
        x1 = ParseX(w[1]);
        y1 = ParseY(w[2]);
        x2 = ParseX(w[4]);
        y2 = ParseY(w[5]);
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'N') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if ((xs == 1 && ys == 2) || (xs == 2 && ys == 1)) {
            char mas[boardsize][boardsize];
            for (int i = 0; i < boardsize; i++) {
                for (int j = 0; j < boardsize; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'N';
            if (!CheckWhite(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'N';
        PrintBoard(board);
    } else {
        Error();
    }
}
void BlackKnight(char board[boardsize][boardsize], char b[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (b[1] >= 'a' && b[1] <= 'h' && b[2] >= '1' && b[2] <= '8' && b[3] == '-'
        && b[4] >= 'a' && b[4] <= 'h' && b[5] >= '1' && b[5] <= '8'
        && (b[6] == '\0' || b[6] == '#')) {
        x1 = ParseX(b[1]);
        y1 = ParseY(b[2]);
        x2 = ParseX(b[4]);
        y2 = ParseY(b[5]);
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'n') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if ((xs == 1 && ys == 2) || (xs == 2 && ys == 1)) {
            char mas[boardsize][boardsize];
            for (int i = 0; i < boardsize; i++) {
                for (int j = 0; j < boardsize; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'n';
            if (!CheckBlack(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'n';
        PrintBoard(board);
    } else {
        Error();
    }
}

void WhiteQueen(char board[boardsize][boardsize], char w[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (w[1] >= 'a' && w[1] <= 'h' && w[2] >= '1' && w[2] <= '8' && w[3] == '-'
        && w[4] >= 'a' && w[4] <= 'h' && w[5] >= '1' && w[5] <= '8'
        && (w[6] == '\0' || w[6] == '#')) {
        x1 = ParseX(w[1]);
        y1 = ParseY(w[2]);
        x2 = ParseX(w[4]);
        y2 = ParseY(w[5]);
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'Q') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if (xs == 0 || ys == 0 || xs == ys) {
            char mas[boardsize][boardsize];
            for (int i = 0; i < boardsize; i++) {
                for (int j = 0; j < boardsize; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'Q';
            if (!CheckWhite(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'Q';
        PrintBoard(board);
    } else {
        Error();
    }
}
void BlackQueen(char board[boardsize][boardsize], char b[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (b[1] >= 'a' && b[1] <= 'h' && b[2] >= '1' && b[2] <= '8' && b[3] == '-'
        && b[4] >= 'a' && b[4] <= 'h' && b[5] >= '1' && b[5] <= '8'
        && (b[6] == '\0' || b[6] == '#')) {
        x1 = ParseX(b[1]);
        y1 = ParseY(b[2]);
        x2 = ParseX(b[4]);
        y2 = ParseY(b[5]);
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'q') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if (xs == 0 || ys == 0 || xs == ys) {
            char mas[boardsize][boardsize];
            for (int i = 0; i < boardsize; i++) {
                for (int j = 0; j < boardsize; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'q';
            if (!CheckBlack(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'q';
        PrintBoard(board);
    } else {
        Error();
    }
}

void White(char board[boardsize][boardsize], char w[7])
{
    switch (w[0]) {
    case 'Q':
        WhiteQueen(board, w);
        break;
    case 'B':
        WhiteBishop(board, w);
        break;
    case 'N':
        WhiteKnight(board, w);
        break;
    case 'R':
        WhiteRook(board, w);
        break;
    case 'K':
        WhiteKing(board, w);
        break;
    default:
        if (w[0] >= 'a' && w[0] <= 'h') {
            WhitePawn(board, w);

        } else {
            ErrorCode(1);
            break;
        }
    }
}

void Black(char board[boardsize][boardsize], char b[7])
{
    switch (b[0]) {
    case 'Q':
        BlackQueen(board, b);
        break;
    case 'B':
        BlackBishop(board, b);
        break;
    case 'N':
        BlackKnight(board, b);
        break;
    case 'R':
        BlackRook(board, b);
        break;
    case 'K':
        BlackKing(board, b);
        break;
    default:
        if (b[0] >= 'a' && b[0] <= 'h') {
            BlackPawn(board, b);
        } else {
            ErrorCode(1);
            break;
        }
    }
}

int WinWhite(char board[boardsize][boardsize], char w[7], int n)
{
    for (int i = 0; i < 7; i++) {
        if (w[i] == '#') {
            printf("\n%d. %s\n", n, w);
            White(board, w);
            w_pass = 0;

            printf("\n END \n");
            return 1;
        }
    }
    return 0;
}

int WinBlack(char board[boardsize][boardsize], char w[7], char b[7], int n)
{
    for (int i = 0; i < 7; i++) {
        if (b[i] == '#') {
            printf("\n%d. %s %s \n", n, w, b);
            White(board, w);
            w_pass = 0;
            Black(board, b);
            b_pass = 0;

            printf("\n END \n");
            return 1;
        }
    }
    return 0;
}
