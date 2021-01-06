#include <windows.h>
#include <stdio.h>

INPUT_RECORD rec;
DWORD dwNOER;
HANDLE CIN = 0;

void click(int* xx, int* yy, int* lr) {
    while (1)
    {
        ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // �ܼ�â �Է��� �޾Ƶ���.
        if (rec.EventType == MOUSE_EVENT) {// ���콺 �̺�Ʈ�� ���

            if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) { // ���� ��ư�� Ŭ���Ǿ��� ���
                int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X�� �޾ƿ�
                int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y�� �޾ƿ�

                *xx = mouse_x; //x���� �ѱ�
                *yy = mouse_y; //y���� �ѱ�
                *lr = 1; //���콺 Ŭ�����¸� �ѱ�

                break;
            }
            else if (rec.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED) { // ���� ��ư�� Ŭ���Ǿ��� ���
                int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X�� �޾ƿ�
                int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y�� �޾ƿ�

                *xx = mouse_x; //x���� �ѱ�
                *yy = mouse_y; //y���� �ѱ�
                *lr = 2; //���콺 Ŭ�����¸� �ѱ�

                break;
            }
        }
    }
}

int main() {
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
    //���콺 �Է¸��� �ٲ�

    int xx, yy, lr;
    while (1) {

        click(&xx, &yy, &lr);
        printf("%2d %2d %2d\n", xx, yy, lr);

    }

}