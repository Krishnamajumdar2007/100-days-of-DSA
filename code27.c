#include <stdio.h>

int main() {
    int n,m;
    scanf("%d", &n);
    scanf("%d", &m);

    int matrix[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int isIdentity = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == j) {
                if(matrix[i][j] != 1) {
                    isIdentity = 0;
                    break;
                }
            } else {
                if(matrix[i][j] != 0) {
                    isIdentity = 0;
                    break;
                }
            }
        }
        if(isIdentity == 0)
            break;
    }

    if(isIdentity)
        printf("Matrix is an Identity Matrix\n");
    else
        printf("Matrix is NOT an Identity Matrix\n");

    return 0;
}