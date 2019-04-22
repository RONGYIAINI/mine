#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_ROW 11
#define MAX_COL 11
#include<time.h>
#define MINE_COUNT 10
//��ʼ����ͼ
void Init(char show_map[MAX_ROW][MAX_COL], char mine_map[MAX_ROW][MAX_COL]) {
	//show_mapÿ��Ԫ�ض����ó�*
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			show_map[row][col] = '*';
		}
	}
	//mine_mapÿ��Ԫ�ض����ó�0
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			mine_map[row][col] = ' ';
		}
	}
	//��mine_map����10��Ԫ����Ϊ����
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
//Game��ʾһ����Ϸ
void Game() {
	//1����������ά������Ϊ��ͼ
	char show_map [MAX_ROW][MAX_COL];
	char mine_map [MAX_ROW][MAX_COL];
	//2�Ե�ͼ���г�ʼ��
	Init(show_map, mine_map);
	int Blank_count = 0;
	while (1) {
		
	//3��ӡ����
	PrintMap(show_map);
	
	//4����������벢����Ч��
	
		printf("������һ������");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row<1 || row>MAX_ROW-1 || col<1 || col>MAX_COL-1) {
			system("cls");
			printf("�����������Ƿ�\n");
			continue;
		}
		if (show_map[row][col] != '*') {
			system("cls");
			printf("��λ���ѷ���\n");
			continue;
		}
		//5�ж��Ƿ����
		if (mine_map[row][col] == '+') {
			system("cls");
			PrintMap(mine_map);
			printf("���ź��������!\n");
			return;
		}
		++Blank_count;
		//6�ж��Ƿ�ʤ��
		if (Blank_count == 71) {
			printf("��ϲ��ȡ��ʤ��\n");
			return;	
		}
		//������ҵ�ǰλ���м�����
		Updateshowmap(row, col, show_map, mine_map);
		system("cls");
	}
	
}



int Meau() {
	printf("--------------\n");
	printf("1.��ʼ��Ϸ\n");
	printf("2.������Ϸ\n");
	printf("--------------\n");
	printf("���������ѡ��:\n");
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
			printf("��������,����������\n");
			continue;
		}
	}
	system("pause");
	return 0;
}