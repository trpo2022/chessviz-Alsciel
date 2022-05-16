#include <libchessviz/chessviz.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define boardsize 8

int w_pass = 0;
int w_x = -1;
int b_pass = 0;
int b_x = -1;

int main()
{
    char board[boardsize][boardsize];
    int MoveNum = 0;
    CreateBoard(board);
    PrintBoard(board);
    int n = 0;
    char w[7];
    char b[7];
    while (n == MoveNum) {
        MoveNum += 1;
	printf("Enter step number: ");
        scanf("%d. ", &n);
        if (MoveNum == n) {
            scanf("%s", w);
            if (WinWhite(board, w, n)) {
                break;
            }
            scanf("%s", b);
            if (WinBlack(board, w, b, n)) {
                break;
            }
            printf("\n%d. %s %s \n", n, w, b);
            White(board, w);
            if (CheckWhite(board)) {
                ErrorCode(2);
                break;
            }
            w_pass = 0;
            Black(board, b);
            if (CheckBlack(board)) {
                ErrorCode(2);
                break;
            }
            b_pass = 0;
        } else {
            ErrorCode(1);
            break;
        }
    }

    return 0;
}
