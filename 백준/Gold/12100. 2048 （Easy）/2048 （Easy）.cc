#include <stdio.h>
#include <stdlib.h>

long long max = 0;
int n;

typedef struct {
    long long val;
    int touched;
} tile;

void solve(long long **arr, int n, int curstep, int directions) {
    if (curstep == 5) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] > max) {
                    max = arr[i][j];
                    /*printf("%d\n", directions);
                    for(int k=0; k<n; k++) {
                        for(int l=0; l<n; l++) {
                            printf("%lld ",arr[k][l]);
                        }
                        printf("\n");
                    }*/

                }
            }
        }
        return;
    }

    long long **up = (long long **)malloc(n * sizeof(long long *));
    long long **down = (long long **)malloc(n * sizeof(long long *));
    long long **left = (long long **)malloc(n * sizeof(long long *));
    long long **right = (long long **)malloc(n * sizeof(long long *));

    int uptile[n][n];
    int downtile[n][n];
    int lefttile[n][n];
    int righttile[n][n];

    for (int i = 0; i < n; i++) {
        up[i] = (long long *)malloc(n * sizeof(long long));
        down[i] = (long long *)malloc(n * sizeof(long long));
        left[i] = (long long *)malloc(n * sizeof(long long));
        right[i] = (long long *)malloc(n * sizeof(long long));

        for (int j = 0; j < n; j++) {
            up[i][j] = arr[i][j];
            down[i][j] = arr[i][j];
            left[i][j] = arr[i][j];
            right[i][j] = arr[i][j];
            uptile[i][j]=0;
            downtile[i][j]=0;
            lefttile[i][j]=0;
            righttile[i][j]=0;
        }
    }

    for (int j = 0; j < n; j++) {
        int target = 0;
        for (int i = 0; i < n; i++) {
            if (up[i][j] != 0) {
                if (target > 0 && up[target - 1][j] == up[i][j] && uptile[target-1][j]!=1) {
                    up[target - 1][j] *= 2;
                    uptile[target-1][j]=1;
                    up[i][j] = 0;
                } else {
                    long long temp = up[i][j];
                    up[i][j] = 0;
                    up[target][j] = temp;
                    target++;
                }
            }
        }
    }
    solve(up, n, curstep + 1, directions*10+1);

    for (int j = 0; j < n; j++) {
        int target = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (down[i][j] != 0) {
                if (target < n - 1 && down[target + 1][j] == down[i][j] && downtile[target+1][j]!=1) {
                    down[target + 1][j] *= 2;
                    downtile[target+1][j]=1;
                    down[i][j] = 0;
                } else {
                    long long temp = down[i][j];
                    down[i][j] = 0;
                    down[target][j] = temp;
                    target--;
                }
            }
        }
    }
    solve(down, n, curstep + 1, directions*10+2);

    for (int i = 0; i < n; i++) {
        int target = 0;
        for (int j = 0; j < n; j++) {
            if (left[i][j] != 0) {
                if (target > 0 && left[i][target - 1] == left[i][j] && lefttile[i][target-1]!=1) {
                    left[i][target - 1] *= 2;
                    lefttile[i][target-1]=1;
                    left[i][j] = 0;
                } else {
                    long long temp = left[i][j];
                    left[i][j] = 0;
                    left[i][target] = temp;
                    target++;
                }
            }
        }
    }
    solve(left, n, curstep + 1, directions*10+3);

    for (int i = 0; i < n; i++) {
        int target = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            if (right[i][j] != 0) {
                if (target < n - 1 && right[i][target + 1] == right[i][j] && righttile[i][target+1]!=1) {
                    right[i][target + 1] *= 2;
                    righttile[i][target+1]=1;
                    right[i][j] = 0;
                } else {
                    long long temp = right[i][j];
                    right[i][j] = 0;
                    right[i][target] = temp;
                    target--;
                }
            }
        }
    }
    solve(right, n, curstep + 1, directions*10+4);

    for (int i = 0; i < n; i++) {
        free(up[i]);
        free(down[i]);
        free(left[i]);
        free(right[i]);
    }
    free(up);
    free(down);
    free(left);
    free(right);
}

int main() {
    scanf("%d", &n);

    long long **board = (long long **)malloc(n * sizeof(long long *));
    for (int i = 0; i < n; i++) {
        board[i] = (long long *)malloc(n * sizeof(long long));
        for (int j = 0; j < n; j++) {
            scanf("%lld", &board[i][j]);
        }
    }

    solve(board, n, 0,0);

    printf("%lld\n", max);

    for (int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}
