#include <iostream>
using namespace std;
int box[129][129], b = 0, w = 0;

void cut(int x, int y, int size) {
    int stack = 0;
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (box[i][j])
            {
                stack++;
            }
        }
    }

    if (!stack)
    {
        w++;
    }
    else if (stack == size * size)
    {
        b++;
    }
    else {
        cut(x, y, size / 2);
        cut(x + size / 2, y, size / 2);
        cut(x, y + size / 2, size / 2);
        cut(x + size / 2, y + size / 2, size / 2);
    }
    return;
}

int main(void) {
    cin.tie(0); cin.sync_with_stdio(0);
    int num; cin >> num;

    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= num; j++)
            cin >> box[i][j];
    }

    cut(1, 1, num);
    cout << w << "\n"; cout << b << "\n";
    return 0;
}