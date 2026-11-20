#include <stdio.h>

int main() {
    char board[51];
    scanf("%s",board);

    char res[51];

    int index=0;
    int resindex=0;
    int len=0;
    while(1) {
        while(board[index]=='X') {
            len++;
            index++;
        }
        if(len%2==1) {
            printf("-1");
            return 0;
        }
        else {
            while(len/4!=0) {
                for(int i=0;i<4;i++) {
                    res[resindex]='A';
                    resindex++;
                }
                len-=4;
            }
            if(len==2) {
                res[resindex++]='B';
                res[resindex++]='B';
                len-=2;
            }
        }
        if(board[index]=='\0'){
            break;
        }
        else {
            while(board[index]=='.') {
                res[resindex++]='.';
                index++;
            }
        }


    }

    res[resindex]='\0';

    printf("%s", res);

    return 0;
}
