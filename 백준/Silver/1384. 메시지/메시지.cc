#include <cstdio>
int main()
{
    char name[25][65];
    char msg[25][25];


    int group_num=1;
    while(1)
    {

        int nas_num=0;
        int n;
        scanf("%d", &n);
        if(n == 0)
            break;
        printf("Group %d\n", group_num);
        for(int i=0; i<n; i++)
        {
            scanf("%s", name[i]);
            for(int j=0; j<n-1; j++)
                scanf(" %c", &msg[i][j]);
        }

        for(int i=0; i<n; i++)
        {
            int per=0;
            for(int j=0; j<n-1; j++)
            {
                per=i-j-1;
                if(per<0)
                    per+=n;
                if(msg[i][j]=='N')
                {
                    printf("%s was nasty about %s\n", name[per], name[i]);
                    nas_num++;
                }
            }
        }

        if(nas_num==0)
        {
            printf("Nobody was nasty\n");
        }
        group_num++;

        printf("\n");
    }
    return 0;

}

