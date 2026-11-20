#include <stdio.h>

int valid(int board[9][9], int y, int x, int num) {
    for(int i=0; i<9; i++) {
        if(board[y][i]==num || board[i][x]==num) {
            return 0;
        }
        if(board[y/3*3+i/3][x/3*3+i%3]==num) {
            return 0;
        }
    }
    return 1;
}

int sudoku(int board[9][9], int num, int z_num, int z_pos[81]) {
    if(num== z_num) {
        return 1;
    }

    int z_y=z_pos[num]/10;
    int z_x=z_pos[num]%10;

    for(int i=1; i<=9; i++) {
        if(valid(board, z_y, z_x, i)) {
            board[z_y][z_x]=i;
            if(sudoku(board,num+1, z_num, z_pos)) {
                return 1;
            }
            board[z_y][z_x]=0;
        }
    }

    return 0;

}

int main() {
    int board[9][9];
    int z_num=0;
    int z_pos[81];
    
    char input;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            scanf("%c", &input);
            board[i][j]=input-'0';
            if(board[i][j]==0) {
                z_pos[z_num++]=10*i+j;
            }
        }
        getchar();
    }

    if(sudoku(board,0, z_num, z_pos)) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                printf("%d", board[i][j]);
            }
            printf("\n");
        }
    }




    return 0;
}
