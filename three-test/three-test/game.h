#ifndef __GAME_H__
#define  __GAME_H__

#include<stdio.h>
#include<time.h>
#include<windows.h>

#pragma warning(disable:4996)

#define row 3
#define col 3
#define K ' '

void initboard(char board[][col], int ROW, int COL);
void showboard(char board[][col], int ROW, int COL);
void game();
void computer(char board[][col], int ROW,int COL);
char judgeboard(char board[][col],int ROW,int COL);
#endif
