#include <cstdio>

int main()
{
    char board[8][10];

    /*for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            scanf(" %c", &board[i][j]);
        }
    }*/

    for(int i=0; i<8; i++)
    {
        scanf("%s", board[i]);
    }

    int c=0;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if((i+j)%2==0)
            {
                if(board[i][j]=='F')
                c++;
            }
        }
    }

    printf("%d", c);


    return 0;

}
