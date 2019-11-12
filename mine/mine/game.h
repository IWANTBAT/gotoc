#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#pragma warning(disable:4996)

#define row 12
#define col 12
#define NUM 20


void game();
void setboard(char Mine[][col], int ROW, int COL,int *x_p,int *y_p);
void showboard(char Player[][col], int ROW, int COL);
int getcount(char Mine[][col], int x,int y);


#endif