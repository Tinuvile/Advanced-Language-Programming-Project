/* 2352495 ��16 ����� */
/*2354259  ����ϣ  2352852  ����  2352048  �ĺƲ�  2352050  ����  2353119  ������*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define row  10
#define column  26

int main()
{
    char landmine[row][column] = { '0' };
    char input[row][column] = { '0' };
    char input_char;

    //��������
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            //���������ַ�
            for (int n = 0;; n++) {
                scanf(" %c", &input_char);
                if (((input_char >= '0') && (input_char <= '8')) || (input_char = '*')) {
                    input[i][j] = input_char;
                    if (input_char == '*')
                        landmine[i][j] = input_char;
                    break;
                }
            }

        }
    }

    //������Χ����
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (landmine[i][j] != '*') {
                int count = 0;
                for (int m = -1; m <= 1; m++) {
                    for (int n = -1; n <= 1; n++) {
                        int near_x = i + m;
                        int near_y = j + n;
                        if (near_x >= 0 && near_x < row && near_y >= 0 && near_y < column && landmine[near_x][near_y] == '*') {
                            count++;
                        }
                    }
                }
                landmine[i][j] = count + '0';
            }
        }
    }

    //����Ǻ�����������
    int count = 0;
    int judge = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (input[i][j] == '*')
                count++;
            if (input[i][j] != landmine[i][j])
                judge = 1;
        }
    }

    //���
    if (count != 50)
        printf("����1\n");
    else if (judge == 1)
        printf("����2\n");
    else if (judge == 0)
        printf("��ȷ\n");

    return 0;
}

/*
0 1 * 1 0 0 1 2 2 1 1 1 1 2 * 3 1 1 * 2 1 0 1 1 2 1
0 1 1 1 0 0 1 * * 3 2 * 1 2 * * 1 2 3 * 2 1 1 * 2 *
0 0 0 1 1 1 1 3 * * 3 2 2 2 3 3 2 3 * 6 * 2 1 1 2 1
1 1 0 1 * 1 0 1 3 4 * 1 1 * 1 1 * 3 * * * 3 1 1 0 0
* 1 0 1 2 2 1 0 1 * 2 1 2 3 3 2 1 2 2 3 3 3 * 1 0 0
3 3 1 1 2 * 1 0 1 1 1 1 2 * * 2 1 0 0 0 1 * 2 1 0 0
* * 2 3 * 3 1 1 1 1 0 1 * 3 4 * 3 1 1 0 1 2 3 3 3 2
2 3 * 3 * 2 0 1 * 1 0 1 1 1 2 * 4 * 2 0 0 2 * * * *
1 2 2 2 1 1 0 1 2 2 1 0 0 1 2 2 3 * 3 1 1 2 * * 4 2
1 * 1 0 0 0 0 0 1 * 1 0 0 1 * 1 1 1 2 * 1 1 2 2 1 0
*/