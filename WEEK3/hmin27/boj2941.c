#include <stdio.h>
#include <string.h>

int main()
{
	char *croAlp[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	char stack[101];  //stack ó���� ���� $ �߰�
	char topElem, nextElem;
	char str[10];
	int top = 1;
	int temp, cnt = 0, flag = 0;

	stack[0] = '$';

	while (1) {

		temp = getchar();
		if (temp == '\n') {
			--top;
			break;
		}
		else {
			stack[top] = temp;
			top++;
		}
	}

	while (1) {
		topElem = stack[top--];
		//stack�� ����� ���
		if (topElem == '$') break;

		//ũ�ξ�Ƽ�� ���ĺ��� ���
		else if (topElem == '=' || topElem == '-' || (topElem == 'j' && (stack[top] == 'n' || stack[top] == 'l'))) {

			nextElem = stack[top--];
			sprintf_s(str, sizeof(str), "%c%c", nextElem, topElem); 

			for (int i = 0; i < 8; i++) {
				if (!strcmp(croAlp[i], str)) {
					if (i == 7) {
						if (stack[top] == 'd') top--;  //dz=�� z= ����
					}
					++cnt;
					++flag;
					break;
				}
			}

			if (!flag) {
				sprintf_s(str, sizeof(str), "%s%c", str, topElem);

				for (int i = 0; i < 8; i++) {
					if (!strcmp(croAlp[i], str)) {
						++cnt;
						break;
					}
				}
			}

			flag == 0;

		}
		//ũ�ξ�Ƽ�� ���ĺ��� �ƴ� ���ĺ��� ���
		else cnt++;
	}


	printf("%d", cnt);
}
