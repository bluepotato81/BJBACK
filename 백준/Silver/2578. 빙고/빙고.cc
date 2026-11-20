#include <cstdio>

int main()
{
    int word[5][5];

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            scanf("%d", &word[i][j]);
        }
    }

    int cur, all=0;
    for(int i=0; i<25; i++)
    {
        scanf("%d", &cur);
        if(all > 0)
            continue;

        for(int j=0; j<5; j++)
        {
            for(int k=0; k<5; k++)
            {
                if(cur==word[j][k])
                {
                    word[j][k]=0;
                }
            }
        }

        int bin=0;
        for(int j=0; j<5; j++)
        {
            int tem=0;
            for(int k=0; k<5; k++)
            {
                if(word[j][k]==0)
                    tem++;
            }
            if(tem==5)
                bin++;
        }

        for(int j=0; j<5; j++)
        {
            int tem=0;
            for(int k=0; k<5; k++)
            {
                if(word[k][j]==0)
                    tem++;
            }
            if(tem==5)
                bin++;
        }

        int so=0;
        for(int j=0; j<5; j++)
        {
            if(word[j][j]==0)
                so++;
        }
        if(so==5)
            bin++;

        so=0;
        for(int j=4; j>=0; j--)
        {
            if(word[j][4-j]==0)
                so++;
        }
        if(so==5)
            bin++;

        if(bin>=3)
        {
            all = i+1;
        }

    }

    printf("%d", all);

    return 0;

}

