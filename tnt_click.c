#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

INPUT_RECORD rec;
DWORD dwNOER;
HANDLE CIN = 0;

void draw(int tnt_position[30][30], int tnt_pos[30][30])
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (tnt_position[i][j] == 0)//아직 안열림
				printf("□");
			else if (tnt_position[i][j] == 1)//지뢰
				printf("■");
			else if (tnt_position[i][j] == 2)//지뢰표시
				printf("▣");
			else //맞음
				printf("%d|", tnt_pos[i][j]);
		}
		printf("\n");
	}
}
void click(int* c, int* d, int* e) {
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // 콘솔창 입력을 받아들임.
	if (rec.EventType == MOUSE_EVENT) {// 마우스 이벤트일 경우
		if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) { // 좌측 버튼이 클릭되었을 경우
			int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X값 받아옴
			int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y값 받아옴
			*c = mouse_x; //x값을 넘김
			*d = mouse_y; //y값을 넘김
			*e = 0; //마우스 클릭상태를 넘김
		}
		else if (rec.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED) { // 우측 버튼이 클릭되었을 경우
			int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X값 받아옴
			int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y값 받아옴
			*c = mouse_x; //x값을 넘김
			*d = mouse_y; //y값을 넘김
			*e = 2; //마우스 클릭상태를 넘김
		}
	}
}
int main()
{
	int tnt_pos[30][30] = { 0 }, hide[30][30] = { 0 }, tnt_cnt[30][30] = { 0 }; //지뢰위치 깐지안깐지 폭탄개수
	srand((unsigned)time(NULL));
	int a, b, c = 0, d = 0, k, cnt = 0, i, j, e;
	printf("생성할 지뢰개수를 입력해주세요(30*30)"); //지뢰수생성
	scanf_s("%d", &k);

	for (i = 0; i < k; i++)//지뢰생성
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
			if (i == 0 && j == 0)//모서리 처리
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
		SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);//마우스 입력모드로 바꿈
		draw(hide, tnt_cnt);
		click(&c, &d, &e);
		//
		if (c >= 30 || d >= 30 || c < 0 || d < 0)
		{
			printf("범위안의 숫자를 입력해주세요\n");
			Sleep(1000);
		}
		else if (e == 0)
		{
			hide[c][d] = 2;
		}
		else if (e == 2)
		{
			hide[c][d] = 0;
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
			hide[c][d] = 3;
		}
		Sleep(1000);
		system("cls");
	}// while문끝
	system("cls");
	printf("지뢰위치\n");
	for (i = 0; i < 30; i++)
	{
		for (j = 0; j < 30; j++)
		{
			if (tnt_pos[i][j] == 1)
				hide[i][j] = 1;
			else
				hide[i][j] = 3;
		}
	}
	draw(hide, tnt_cnt);//게임 끝난후 지뢰위치 보여주기
}