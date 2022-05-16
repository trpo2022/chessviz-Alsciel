#include <libchessviz/chessviz.h>

extern int w_pass;
extern int w_x;
extern int b_pass;
extern int b_x;

void CreateBoard(char board[boardsize][boardsize])
{
    char mas[boardsize][boardsize] = {
            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    };
    for (int i = 0; i < boardsize; i++) {
        for (int j = 0; j < boardsize; j++) {
            board[i][j] = mas[i][j];
        }
    }
}

void PrintBoard(char c[boardsize][boardsize])
{
    printf("\n");
    for (int i = 0; i < boardsize; i++) {
        printf("%d | ", boardsize - i);
        for (int j = 0; j < boardsize; j++)
            printf("%c ", c[i][j]);
        printf("\n");
    }
    printf("  +-----------------\n");
    printf("    a b c d e f g h\n");
}

void Error()
{
    printf("\n Invalid input \n");
}
void ErrorCode(int n)
{
    printf("\n Invalid input, code: %d \n", n);
}

int ParseX(char n)
{
    int x = n - 97;
    return x;
}
int ParseY(char n)
{
    int y = n - 49;
    return y;
}
