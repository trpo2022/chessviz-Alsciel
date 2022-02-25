#include <stdio.h>
#define ChessSize 8
void PrintChess()
{
    int i = 0, j = 0;
    char ChessViz[ChessSize][ChessSize]
            = {"rnbqkbnr",
               "pppppppp",
               "        ",
               "        ",
               "        ",
               "        ",
               "PPPPPPPP",
               "RNBQKBNR"};
    printf("\n");
    for (i = 0; i < ChessSize; i++) {
        printf("%d   ", i + 1);
        for (j = 0; j < ChessSize; j++) {
            printf("%c  ", ChessViz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("    a  b  c  d  e  f  g  h \n");
}

int main()
{
    PrintChess();
    return 0;
}
