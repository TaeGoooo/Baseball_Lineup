#pragma warning(disable:4996)
#include <stdio.h>
#include <Windows.h>

void WriteLineup();
void ShowLineup();
void gotoxy();

char TeamType[2][5] = { "Home", "Away" };
char TeamName[2][21];
char Batter[2][9][21];
char Pitcher[2][10][21];
int n[2] = { 0, 40 };

void main()
{
	WriteLineup();
	ShowLineup();
}

void WriteLineup()
{
	for (int j = 0; j < 2; j++) {
		printf("\t%s Team : ", TeamType[j]);
		scanf("%s", TeamName[j]);

		printf("\t\tBatter\n");
		for (int i = 0; i < 9; i++) {
			printf("%d : ", i + 1);
			scanf("%s", Batter[j][i]);
		}
		printf("\t\tPicther\n");
		printf("P : ");
		scanf("%s", Pitcher[j][1]);

		system("cls");
	}
}

void ShowLineup()
{
	for (int j = 0; j < 2; j++) {
		gotoxy(n[j], 0);
		printf("%s\n", TeamName[j]);
		for (int i = 1; i < 10; i++) {
			gotoxy(n[j], i + 1);
			printf("%d. %s\n", i, Batter[j][i - 1]);
		}
	}
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
