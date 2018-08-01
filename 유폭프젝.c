#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

#define MAPSIZE_cols 40
#define MAPSIZE_lines 20
#define WALL1 1
#define WALL2 2
#define SPACE 0
#define TELPO_UP 5
#define TELPO_DOWN 6
#define TELPO_LEFT 7
#define TELPO_RIGHT 8
#define PLAYER 9
#define PLAYER_BODY 3
#define MONSTER_BODY 10
#define shop_point 11
#define up 12
int count = 0;
int flag = 1;
int money = 1000;
int player_hp = 100;
int monster_hp = 50;
int monster_damage;
int attack_flag = 1;
int attackX = 12;
int attackY = 15;
char playerInput;
int boss_hp;
int up_flag = 1;
int startmap[MAPSIZE_lines][MAPSIZE_cols] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};
int map_one[MAPSIZE_lines][MAPSIZE_cols] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,5,5,5,5,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8 },
{ 7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8 },
{ 7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8 },
{ 7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,6,6,6,6,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
};
int map_hunting[MAPSIZE_lines][MAPSIZE_cols] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,10,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,3,0,3,3,3,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,10,10,10,0,0,0,0,0,0,2 },
{ 2,0,0,3,0,0,3,3,3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,10,10,10,10,10,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,10,10,10,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,3,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,10,10,10,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,3,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};
int map_shop[MAPSIZE_lines][MAPSIZE_cols] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,5,5,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,11,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};
int map_boss[MAPSIZE_lines][MAPSIZE_cols] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,0,10,10,0,10,10,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,0,10,10,0,10,10,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,10,10,10,10,10,10,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,10,10,10,10,10,10,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,10,10,10,10,10,10,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,10,10,10,10,10,10,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,10,10,10,10,10,10,0,0,0,0,0,2 },
{ 2,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,10,10,10,10,10,10,0,0,0,0,0,2 },
{ 2,0,0,0,3,0,3,3,3,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,10,10,10,10,10,10,0,0,0,0,0,2 },
{ 2,0,0,3,0,0,3,3,3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,10,10,10,10,10,10,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,10,10,10,10,10,10,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,3,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,10,10,10,10,10,10,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,3,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};
int map_up[MAPSIZE_lines][MAPSIZE_cols] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};
int i, j;
int playerX, playerY;
char playerch[] = "★";
char attackch[] = ">";
char wallch[] = "■";
int damage = 3;
int shopX = 14;
int shopY = 19;
int flag_c = 0;
int flag_game = 1;
void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x * 2;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void MAPprint_startmap() {
	for (i = 0; i < MAPSIZE_lines; i++) {
		for (j = 0; j < MAPSIZE_cols; j++) {
			if (startmap[i][j] == WALL1)printf("==");
			else if (startmap[i][j] == WALL2)printf("||");
			else if (startmap[i][j] == SPACE)printf("  ");
		}
	}
}

void printxy(int x, int y, char c[])
{
	gotoxy(x, y);
	printf("%s", c);
}
void printhp(int x, int y, int c) {
	gotoxy(x, y);
	printf("%d", c);
}
void clearxy(int x, int y)
{
	gotoxy(x, y);
	printf("  ");
}
void MAPprint(int n) {
	if (n == 1) {
		system("cls");
		for (i = 0; i < MAPSIZE_lines; i++) {
			for (j = 0; j < MAPSIZE_cols; j++) {
				if (map_one[i][j] == SPACE)printf("  ");
				else if (map_one[i][j] == WALL1)printf("==");
				else if (map_one[i][j] == WALL2)printf("||");
				else if (map_one[i][j] == PLAYER)printf("★");
				else printf("  ");
			}
		}
	}
	else if (n == TELPO_UP) {
		system("cls");
		for (i = 0; i < MAPSIZE_lines; i++) {
			for (j = 0; j < MAPSIZE_cols; j++) {
				if (map_hunting[i][j] == SPACE)printf("  ");
				else if (map_hunting[i][j] == WALL1)printf("==");
				else if (map_hunting[i][j] == WALL2)printf("||");
				else if (map_hunting[i][j] == PLAYER_BODY)printf("■");
				else if (map_hunting[i][j] == MONSTER_BODY)printf("■");
			}
		}
	}
	else if (n == TELPO_DOWN) {
		system("cls");
		for (i = 0; i < MAPSIZE_lines; i++) {
			for (j = 0; j < MAPSIZE_cols; j++) {
				if (map_shop[i][j] == SPACE)printf("  ");
				else if (map_shop[i][j] == WALL1)printf("==");
				else if (map_shop[i][j] == WALL2)printf("||");
				else if (map_shop[i][j] == PLAYER_BODY)printf("■");
				else if (map_shop[i][j] == MONSTER_BODY)printf("■");
				else if (map_shop[i][j] == PLAYER)printf("★");
				else if (map_shop[i][j] == shop_point)printf("■");
				else printf("  ");
			}
		}
	}
	else if (n == TELPO_RIGHT) {
		system("cls");
		for (i = 0; i < MAPSIZE_lines; i++) {
			for (j = 0; j < MAPSIZE_cols; j++) {
				if (map_boss[i][j] == SPACE)printf("  ");
				else if (map_boss[i][j] == WALL1)printf("==");
				else if (map_boss[i][j] == WALL2)printf("||");
				else if (map_boss[i][j] == PLAYER_BODY)printf("■");
				else if (map_boss[i][j] == MONSTER_BODY)printf("■");
			}
		}
	}
	else if (n == TELPO_LEFT) {
		system("cls");
		for (i = 0; i < MAPSIZE_lines; i++) {
			for (j = 0; j < MAPSIZE_cols; j++) {
				if (map_up[i][j] == SPACE)printf("  ");
				else if (map_up[i][j] == WALL1)printf("■");
				else if (map_up[i][j] == WALL2)printf("■");
				else if (map_up[i][j] == PLAYER)printf("★");
				else if (map_up[i][j] == 12)printf("■");
				else printf("  ");
			}
		}
	}
}
void movePlayer(int dx, int dy) {
	if (map_one[playerY + dy][playerX + dx] == SPACE && flag == 1) {
		clearxy(playerX, playerY);
		map_one[playerY][playerX] = SPACE;
		playerY += dy;
		playerX += dx;
		printxy(playerX, playerY, playerch);
		map_one[playerY][playerX] = PLAYER;
	}
	else if (map_one[playerY + dy][playerX + dx] == TELPO_UP && flag == 1) {
		flag = TELPO_UP;
		clearxy(playerX, playerY);
		MAPprint(flag);
	}
	else if (playerInput == 'a'&&flag == TELPO_UP) {
		attackX = 12;
		attackY = 15;
		attack_flag = 1;
		printhp(30, 11, monster_hp);
		while (attack_flag) {
			printxy(attackX, attackY, attackch);
			Sleep(100);
			clearxy(attackX, attackY);
			attackX += dx;
			attackY += dy;
			if (map_hunting[attackY + dy][attackX + dx] == MONSTER_BODY)attack_flag = 0;
		}
		monster_hp -= damage;
		system("cls");
		MAPprint(flag);
		if (monster_hp <= 0) {
			money += 500;
			flag = 1;
			monster_hp = 50;
			MAPprint(flag);
		}
	}
	else if (playerInput == 'e'&&flag == TELPO_UP) {
		flag = 1;
		MAPprint(flag);
		printxy(playerX, playerY, playerch);
	}
	else if (map_one[playerY + dy][playerX + dx] == TELPO_DOWN && flag == 1) {
		flag = TELPO_DOWN;
		system("cls");
		clearxy(playerX, playerY);
		map_one[playerY][playerX] = SPACE;
		playerY = 1;
		map_shop[playerY][playerX] = PLAYER;
		MAPprint(TELPO_DOWN);
		printxy(playerX, playerY, playerch);
	}
	else if (map_shop[playerY + dy][playerX + dx] == SPACE && flag == TELPO_DOWN) {
		clearxy(playerX, playerY);
		map_shop[playerY][playerX] = SPACE;
		playerY += dy;
		playerX += dx;
		printxy(playerX, playerY, playerch);
		map_shop[playerY][playerX] = PLAYER;
	}
	else if (map_shop[playerY + 1][playerX] == shop_point && flag == TELPO_DOWN && playerInput == 'u'&&money > count * 100 + 500) {
		damage += 1;
		money -= count * 100 + 500;
		printxy(20, 10, "업그레이드완료");
		Sleep(1000);
		MAPprint(flag);
	}
	else if (playerInput == 'm') {
		printhp(20, 10, money);
		Sleep(1000);
		system("cls");
		MAPprint(flag);
	}
	else if (map_shop[playerY + dy][playerX + dx] == TELPO_UP && flag == TELPO_DOWN) {
		flag = 1;
		clearxy(playerX, playerY);
		map_shop[playerY][playerX] = SPACE;
		playerY = 18;
		map_one[playerY][playerX] = PLAYER;
		MAPprint(flag);
	}
	else if (map_one[playerY + dy][playerX + dx] == TELPO_RIGHT && flag == 1) {
		if (damage >= 300) {
			boss_hp = 10000;
			flag = TELPO_RIGHT;
			clearxy(playerX, playerY);
			MAPprint(flag);
		}
		else {
			printxy(16, 9, "데미지부족");
			Sleep(1000);
			MAPprint(flag);
		}
	}
	else if (playerInput == 'a'&&flag == TELPO_RIGHT) {
		attackX = 12;
		attackY = 15;
		attack_flag = 1;
		printhp(29, 4, boss_hp);
		while (attack_flag) {
			printxy(attackX, attackY, attackch);
			Sleep(100);
			clearxy(attackX, attackY);
			attackX += dx;
			attackY += dy;
			if (map_boss[attackY + dy][attackX + dx] == MONSTER_BODY)attack_flag = 0;
		}
		boss_hp -= damage;
		system("cls");
		MAPprint(flag);
		if (boss_hp <= 0) {
			system("cls");
			MAPprint_startmap();
			printxy(16, 9, "축하합니다");
			flag_game = 0;
		}
	}
	else if (playerInput == 'e'&&flag == TELPO_RIGHT) {
		flag = 1;
		MAPprint(flag);
		printxy(playerX, playerY, playerch);
	}
	else if (playerInput == 'd') {
		printhp(20, 10, damage);
		Sleep(1000);
		system("cls");
		MAPprint(flag);
	}
	else if (playerInput == 'c'&&flag == TELPO_DOWN && flag_c == 0) {
		damage += 500;
		flag_c = 1;
	}
	else if (map_one[playerY + dy][playerX + dx] == TELPO_LEFT && flag == 1) {
		flag = TELPO_LEFT;
		map_one[playerY][playerX] = SPACE;
		playerX = 38;
		map_up[playerY][playerX] = PLAYER;
		MAPprint(flag);
	}
	else if (map_up[playerY + dy][playerX + dx] == SPACE && flag == TELPO_LEFT) {
		map_up[playerY][playerX] = SPACE;
		clearxy(playerX, playerY);
		playerX += dx;
		playerY += dy;
		map_up[playerY][playerX] = PLAYER;
		printxy(playerX, playerY, playerch);
	}
	else if (map_up[playerY + 2 * dy][playerX + 2 * dx] == up && flag == TELPO_LEFT) {
		if (damage >= 10 && up_flag == 1) {
			map_up[playerY][playerX] = WALL1;
			clearxy(playerX, playerY);
			printxy(playerX, playerY, wallch);
			playerX += dx;
			playerY += dy;
			map_up[playerY][playerX] = PLAYER;
			printxy(playerX, playerY, playerch);
		}
		else {
			printxy(16, 9, "데미지부족");
			Sleep(1000);
			system("cls");
			MAPprint(flag);
		}
	}
	else if (playerInput == 't'&&map_up[playerY][playerX - 1] == up && flag == TELPO_LEFT) {
		damage += 50;
		printxy(16, 9, "축하합니다");
		Sleep(1000);
		up_flag = 0;
		map_up[playerY][playerX] = SPACE;
		map_up[playerY][playerX + 1] = PLAYER;
		playerX += 1;
		MAPprint(flag);
	}
	else if (map_up[playerY + dy][playerX + dx] == TELPO_RIGHT && flag == TELPO_LEFT) {
		flag = 1;
		map_up[playerY][playerX] = SPACE;
		playerX = 1;
		map_one[playerY][playerX] = PLAYER;
		MAPprint(flag);
	}
}

void cursor(int n) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

int main() {
	system("mode con cols=80 lines=20");
	cursor(0);
	MAPprint_startmap();
	printxy(14, 5, "press enter-> game start");
	printxy(8, 7, "위포탈 -> 기본사냥터,아래포탈 -> 업그레이드 상점");
	printxy(9, 8, "오른쪽 포탈 -> 보스사냥터(잡으면 게임클리어)");
	printxy(17, 9, "명령어 모음");
	printxy(3, 10, "a : 사냥터에서 사용시 공격, e : 사냥터에서 나가기");
	printxy(3, 11, "u : 상점 앞에서 사용시 업그레이드(업그레이드 비용 : 기본 500+횟수*100)");
	printxy(3, 12, "m : 내 돈 확인, d : 내 공격력 확인");
	getchar();
	MAPprint(flag);
	for (i = 0; i < MAPSIZE_lines; i++) {
		for (j = 0; j < MAPSIZE_cols; j++) {
			if (map_one[i][j] == PLAYER) {
				playerY = i;
				playerX = j;
			}
		}
	}
	while (flag_game)
	{

		playerInput = getch();
		if (playerInput == 75)//left
			movePlayer(-1, 0);
		else if (playerInput == 77)//right
			movePlayer(1, 0);
		else if (playerInput == 72)//up
			movePlayer(0, -1);
		else if (playerInput == 80)//down
			movePlayer(0, 1);
		else if (playerInput == 'a')
			movePlayer(1, 0);
		else if (playerInput == 'e')
			movePlayer(0, 0);
		else if (playerInput == 'u')
			movePlayer(0, 0);
		else if (playerInput == 'm')
			movePlayer(0, 0);
		else if (playerInput == 'd')
			movePlayer(0, 0);
		else if (playerInput == 'c')
			movePlayer(0, 0);
		else if (playerInput == 't')
			movePlayer(0, 0);
	}

	getchar();

}