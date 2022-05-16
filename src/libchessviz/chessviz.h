#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define boardsize 8

void CreateBoard(char board[boardsize][boardsize]);
void PrintBoard(char c[boardsize][boardsize]);
void Error();
void ErrorCode(int n);
int ParseX(char n);
int ParseY(char n);
int CheckWhite(char board[boardsize][boardsize]);
int CheckBlack(char board[boardsize][boardsize]);
void WhitePawn(char board[boardsize][boardsize], char w[7]);
void BlackPawn(char board[boardsize][boardsize], char w[7]);
void WhiteKing(char board[boardsize][boardsize], char w[7]);
void BlackKing(char board[boardsize][boardsize], char w[7]);
void WhiteRook(char board[boardsize][boardsize], char w[7]);
void BlackRook(char board[boardsize][boardsize], char w[7]);
void WhiteBishop(char board[boardsize][boardsize], char w[7]);
void BlackBishop(char board[boardsize][boardsize], char w[7]);
void WhiteKnight(char board[boardsize][boardsize], char w[7]);
void BlackKnight(char board[boardsize][boardsize], char w[7]);
void WhiteQueen(char board[boardsize][boardsize], char w[7]);
void BlackQueen(char board[boardsize][boardsize], char w[7]);
void White(char board[boardsize][boardsize], char w[7]);
void Black(char board[boardsize][boardsize], char b[7]);
int WinWhite(char board[boardsize][boardsize], char w[7], int n);
int WinBlack(char board[boardsize][boardsize], char w[7], char b[7], int n);
