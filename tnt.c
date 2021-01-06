#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
void draw(int tnt_pos[30][30], int tnt_cnt[30][30])
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (tnt_pos[i][j] == 0)		//아직 안열림
				printf("□");
			else if (tnt_pos[i][j] == 1)	//지뢰
				printf("■");
			else if (tnt_pos[i][j] == 2)	//지뢰표시
				printf("▣");
			else	//맞음
				printf("%d|", tnt_cnt[i][j]);	//지뢰수
		}
		printf("\n");
	}
}
int main()
{
	int tnt_pos[30][30] = { 0 }, hide[30][30] = { 0 }, tnt_cnt[30][30] = { 0 };		//지뢰위치 깐지안깐지 폭탄개수
	srand((unsigned)time(NULL));
	int a, b,c=0, d=0, k, cnt = 0, i, j,e;		//a,b지뢰생성 c,d입력좌표 k지뢰개수 cnt지뢰수 i,j반복 e지뢰표시
	printf("생성할 지뢰개수를 입력해주세요(30*30)");	//지뢰수생성
	scanf_s("%d", &k);
	
	for (i = 0; i < k; i++)		//지뢰생성
	{
		while (1)
		{
			a = rand() % 30;
			b = rand() % 30;
			if (tnt_pos[a][b] == 1)
				;
			else
			{
				tnt_pos[a][b] = 1;
				break;
			}
		}
		tnt_pos[a][b] = 1;
	}
	for (i = 0; i < 30; i++)
	{
		for (j = 0; j < 30; j++)
		{
			cnt = 0;
			if (i == 0 && j == 0)		//모서리 처리 - 지뢰수 생성
			{
				if (tnt_pos[i][j + 1] == 1)
					cnt++;
				if (tnt_pos[i + 1][j] == 1)
					cnt++;
				if (tnt_pos[i + 1][j + 1] == 1)
					cnt++;
				tnt_cnt[i][j] = cnt;
			}
			else if (i == 0 && j == 29)
			{
				if (tnt_pos[i][j - 1] == 1)
					cnt++;
				if (tnt_pos[i + 1][j - 1] == 1)
					cnt++;
				if (tnt_pos[i + 1][j] == 1)
					cnt++;
				tnt_cnt[i][j] = cnt;
			}
			else if (i == 29 && j == 0)
			{
				if (tnt_pos[i - 1][j] == 1)
					cnt++;
				else if (tnt_pos[i - 1][j + 1] == 1)
					cnt++;
				else if (tnt_pos[i][j + 1] == 1)
					cnt++;
				tnt_cnt[i][j] = cnt;
			}
			else if (i == 29 && j == 29)
			{
				if (tnt_pos[i - 1][j - 1] == 1)
					cnt++;
				if (tnt_pos[i - 1][j] == 1)
					cnt++;
				if (tnt_pos[i][j - 1] == 1)
					cnt++;
				tnt_cnt[i][j] = cnt;
			}
			else if (i == 0)
			{
				if (tnt_pos[i][j - 1] == 1)
					cnt++;
				if (tnt_pos[i][j + 1] == 1)
					cnt++;
				if (tnt_pos[i + 1][j - 1] == 1)
					cnt++;
				if (tnt_pos[i + 1][j] == 1)
					cnt++;
				if (tnt_pos[i + 1][j + 1] == 1)
					cnt++;
				tnt_cnt[i][j] = cnt;
			}
			else if (i == 29)
			{
				if (tnt_pos[i - 1][j - 1] == 1)
					cnt++;
				if (tnt_pos[i - 1][j] == 1)
					cnt++;
				if (tnt_pos[i - 1][j + 1] == 1)
					cnt++;
				if (tnt_pos[i][j - 1] == 1)
					cnt++;
				if (tnt_pos[i][j + 1] == 1)
					cnt++;
				tnt_cnt[i][j] = cnt;
			}
			else if (j == 0)
			{
				if (tnt_pos[i - 1][j] == 1)
					cnt++;
				if (tnt_pos[i - 1][j + 1] == 1)
					cnt++;
				if (tnt_pos[i][j + 1] == 1)
					cnt++;
				if (tnt_pos[i + 1][j] == 1)
					cnt++;
				if (tnt_pos[i + 1][j + 1] == 1)
					cnt++;
				tnt_cnt[i][j] = cnt;
			}
			else if (j == 29)
			{
				if (tnt_pos[i - 1][j - 1] == 1)
					cnt++;
				if (tnt_pos[i - 1][j] == 1)
					cnt++;
				if (tnt_pos[i][j - 1] == 1)
					cnt++;
				if (tnt_pos[i + 1][j - 1] == 1)
					cnt++;
				if (tnt_pos[i + 1][j] == 1)
					cnt++;
				tnt_cnt[i][j] = cnt;
			}
			else
			{
				if (tnt_pos[i - 1][j - 1] == 1)
					cnt++;
				if (tnt_pos[i - 1][j] == 1)
					cnt++;
				if (tnt_pos[i - 1][j + 1] == 1)
					cnt++;
				if (tnt_pos[i][j - 1] == 1)
					cnt++;
				if (tnt_pos[i][j + 1] == 1)
					cnt++;
				if (tnt_pos[i + 1][j - 1] == 1)
					cnt++;
				if (tnt_pos[i + 1][j] == 1)
					cnt++;
				if (tnt_pos[i + 1][j + 1] == 1)
					cnt++;
				tnt_cnt[i][j] = cnt;
			}
		}
	}

	while (1)
	{
		draw(hide, tnt_cnt);
		printf("x좌표입력 : ");
		scanf_s("%d", &d);
		printf("y좌표입력 : ");
		scanf_s("%d", &c);
		c--; d--;
		printf("지뢰표시? 0(yes)/1(no)/2(cancel) : ");
		scanf_s("%d", &e);
		//
		if (c >= 30 || d >= 30 || c < 0 || d < 0)
		{
			printf("범위안의 숫자를 입력해주세요\n");
			Sleep(1000);
		}
		else if (e == 0)
		{
			hide[c][d] = 2;		//지뢰표시
		}
		else if (e == 2)
		{
			hide[c][d] = 0;		//지뢰 잘못 표시한경우 되돌리기
		}
		else if (tnt_pos[c][d] == 1)
		{
			hide[c][d] = 1;
			system("cls");
			printf("꽝\n");
			Sleep(2000);
			break;
		}
		else if (hide[c][d] == 3)
			printf("이미방문했습니다\n");
		else if (tnt_pos[c][d] == 0)
		{
			printf("맞았습니다.\n");
			hide[c][d] = 3;		//주변 지뢰수 보여주기
		}
		Sleep(1000);
		system("cls");
	}		// while문끝
	system("cls");
	printf("지뢰위치\n");
	for (i = 0; i < 30; i++)
	{
		for (j = 0; j < 30; j++)
		{
			if (tnt_pos[i][j] == 1)
				hide[i][j] = 1;		//지뢰위치
			else
				hide[i][j] = 3;		//지뢰수
		}
	}
	draw(hide, tnt_cnt);	//게임 끝난후 지뢰위치 보여주기
}