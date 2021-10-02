#include <stdio.h>
#include <string.h>

int main()
{
	char *croAlp[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	char stack[101];  //stack 처음과 끝에 $ 추가
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
		//stack이 비었을 경우
		if (topElem == '$') break;

		//크로아티아 알파벳인 경우
		else if (topElem == '=' || topElem == '-' || (topElem == 'j' && (stack[top] == 'n' || stack[top] == 'l'))) {

			nextElem = stack[top--];
			sprintf_s(str, sizeof(str), "%c%c", nextElem, topElem); 

			for (int i = 0; i < 8; i++) {
				if (!strcmp(croAlp[i], str)) {
					if (i == 7) {
						if (stack[top] == 'd') top--;  //dz=과 z= 구분
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
		//크로아티아 알파벳이 아닌 알파벳인 경우
		else cnt++;
	}


	printf("%d", cnt);
}
