#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_ROW 11
#define MAX_COL 11
#include<time.h>
#define MINE_COUNT 10
//初始化地图
void Init(char show_map[MAX_ROW][MAX_COL], char mine_map[MAX_ROW][MAX_COL]) {
	//show_map每个元素都设置成*
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			show_map[row][col] = '*';
		}
	}
	//mine_map每个元素都设置成0
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			mine_map[row][col] = ' ';
		}
	}
	//在mine_map上找10个元素作为地雷
	int mine_count = MINE_COUNT;
	while (mine_count >0) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (row < 1 || row > 9 || col < 1 || col > 9 || mine_map[row][col] == '+') {
			continue;
		}
		mine_map[row][col] = '+';
		mine_count--;
	}
}
void PrintMap(char map[MAX_ROW][MAX_COL]) {
	printf("  |");
	for (int row = 1; row < MAX_ROW-1; row++) {
		printf("%d ", row);
		
	}
	printf("\n");
	for (int row = 1; row < MAX_ROW-3; row++) {
		printf("---");
	}
	printf("\n");
	for (int row = 1; row < MAX_ROW-1; row++) {
		printf("%d |", row);
		for (int col = 1; col < MAX_COL-1; col++) {
		
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}
void Updateshowmap(int row, int col, char show_map[MAX_ROW][MAX_COL], char mine_map[MAX_ROW][MAX_COL]) {
	int count = 0;
	if (row - 1 > 0 && col - 1 > 0 && mine_map[row-1][col-1] == '+') {
			count++;
	}
	if (row - 1 > 0 && mine_map[row - 1][col] == '+'){
			count++;
		}
	if (row - 1 > 0 && mine_map[row - 1][col + 1] == '+') {
		count++;
	}
	if (col - 1 > 0 && mine_map[row][col - 1] == '+') {
		count++;
	}
	if (mine_map[row][col + 1] == '+') {
		count++;
	}
	if (col - 1 > 0 && mine_map[row + 1][col - 1] == '+') {
		count++;
	}
	if (mine_map[row + 1][col] == '+') {
		count++;
	}
	if (mine_map[row + 1][col + 1] == '+') {
		count++;
	}
	show_map[row][col] = count + '0';
}
//Game表示一句游戏
void Game() {
	//1创建俩个二维数组作为地图
	char show_map [MAX_ROW][MAX_COL];
	char mine_map [MAX_ROW][MAX_COL];
	//2对地图进行初始化
	Init(show_map, mine_map);
	int Blank_count = 0;
	while (1) {
		
	//3打印棋盘
	PrintMap(show_map);
	
	//4提醒玩家输入并进行效验
	
		printf("请输入一个坐标");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row<1 || row>MAX_ROW-1 || col<1 || col>MAX_COL-1) {
			system("cls");
			printf("你输入的坐标非法\n");
			continue;
		}
		if (show_map[row][col] != '*') {
			system("cls");
			printf("该位置已翻开\n");
			continue;
		}
		//5判断是否踩雷
		if (mine_map[row][col] == '+') {
			system("cls");
			PrintMap(mine_map);
			printf("很遗憾你踩雷了!\n");
			return;
		}
		++Blank_count;
		//6判断是否胜利
		if (Blank_count == 71) {
			printf("恭喜你取得胜利\n");
			return;	
		}
		//告诉玩家当前位置有几个雷
		Updateshowmap(row, col, show_map, mine_map);
		system("cls");
	}
	
}



int Meau() {
	printf("--------------\n");
	printf("1.开始游戏\n");
	printf("2.结束游戏\n");
	printf("--------------\n");
	printf("请输入你的选择:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
int main() {
	srand((unsigned int)time(0));
	while (1) {
		int choice = Meau();
		if (choice == 1) {
			Game();
		}
		else if (choice == 2) {
			printf("Good Bye!\n");
			break;
		}
		else {
			printf("输入有误,请重新输入\n");
			continue;
		}
	}
	system("pause");
	return 0;
}