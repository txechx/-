#include <stdio.h>

void generate_magic_square(int n, int square[15][15]) {
    int i = 0, j = n / 2;
    for (int num = 1; num <= n * n; num++) {
        square[i][j] = num;
        int new_i = (i - 1 + n) % n;
        int new_j = (j + 1) % n;
        if (square[new_i][new_j]) {
            i = (i + 1) % n;
        } else {
            i = new_i;
            j = new_j;
        }
    }
}

int main() {
    int n;
    printf("홀수 차수 n 입력 (3~15): ");
    scanf("%d", &n);

    if (n % 2 == 0 || n < 3 || n > 15) {
        printf("홀수 차수만 지원합니다.\n");
        return 1;
    }

    int square[15][15] = {0};
    generate_magic_square(n, square);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", square[i][j]);
        }
        printf("\n");
    }

    return 0;
}