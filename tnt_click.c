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
			if (tnt_position[i][j] == 0)//���� �ȿ���
				printf("��");
			else if (tnt_position[i][j] == 1)//����
				printf("��");
			else if (tnt_position[i][j] == 2)//����ǥ��
				printf("��");
			else //����
				printf("%d|", tnt_pos[i][j]);
		}
		printf("\n");
	}
}
void click(int* c, int* d, int* e) {
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // �ܼ�â �Է��� �޾Ƶ���.
	if (rec.EventType == MOUSE_EVENT) {// ���콺 �̺�Ʈ�� ���
		if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) { // ���� ��ư�� Ŭ���Ǿ��� ���
			int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X�� �޾ƿ�
			int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y�� �޾ƿ�
			*c = mouse_x; //x���� �ѱ�
			*d = mouse_y; //y���� �ѱ�
			*e = 0; //���콺 Ŭ�����¸� �ѱ�
		}
		else if (rec.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED) { // ���� ��ư�� Ŭ���Ǿ��� ���
			int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X�� �޾ƿ�
			int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y�� �޾ƿ�
			*c = mouse_x; //x���� �ѱ�
			*d = mouse_y; //y���� �ѱ�
			*e = 2; //���콺 Ŭ�����¸� �ѱ�
		}
	}
}
int main()
{
	int tnt_pos[30][30] = { 0 }, hide[30][30] = { 0 }, tnt_cnt[30][30] = { 0 }; //������ġ �����ȱ��� ��ź����
	srand((unsigned)time(NULL));
	int a, b, c = 0, d = 0, k, cnt = 0, i, j, e;
	printf("������ ���ڰ����� �Է����ּ���(30*30)"); //���ڼ�����
	scanf_s("%d", &k);

	for (i = 0; i < k; i++)//���ڻ���
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
			if (i == 0 && j == 0)//�𼭸� ó��
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
		SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);//���콺 �Է¸��� �ٲ�
		draw(hide, tnt_cnt);
		click(&c, &d, &e);
		//
		if (c >= 30 || d >= 30 || c < 0 || d < 0)
		{
			printf("�������� ���ڸ� �Է����ּ���\n");
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
			printf("��\n");
			Sleep(2000);
			break;
		}
		else if (hide[c][d] == 3)
			printf("�̹̹湮�߽��ϴ�\n");
		else if (tnt_pos[c][d] == 0)
		{
			printf("�¾ҽ��ϴ�.\n");
			hide[c][d] = 3;
		}
		Sleep(1000);
		system("cls");
	}// while����
	system("cls");
	printf("������ġ\n");
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
	draw(hide, tnt_cnt);//���� ������ ������ġ �����ֱ�
}