#include <cstdio>

char map_[1005][1005];

int main()
{
    int map_s;
    scanf("%d", &map_s);

    for(int i=0; i<map_s; i++)
    {
        scanf("%s", map_[i]);
        /*for(int j=0; j<map_s; j++)
        {
            scanf(" %c", &map_[i][j]);
        }*/
    }

    for(int i=0; i<map_s; i++)
    {
        for(int j=0; j<map_s; j++)
        {
            if(map_[i][j]!='.')
            {
                printf("*");
                continue;
            }

            /*int n=0;
            for(int k=0; k<map_s; k++)
            {
                for(int l=0; l<map_s; l++)
                {
                    int m=k, n=l, q=i, o=j, spc;
                    if(q>m)
                    {
                        spc=m;
                        m=q;
                        q=spc;
                    }
                    if(o>n)
                    {
                        spc=n;
                        n=o;
                        o=spc;
                    }
                    if((m-q<=1 && n-o<=1) && map_[k][l]!= '.')
                    {
                        n+=map_[k][l]-'0';
                    }
                }
            }*/

            int n = 0;
            for(int k = -1; k <= 1; k++)
            {
                for(int l = -1; l <= 1; l++)
                {
                    int y = i+k, x = j + l;
                    if(y < 0 || x < 0 || y >= map_s || x >= map_s)
                        continue;
                    if(map_[y][x]!= '.')
                    {
                        n+=map_[y][x]-'0';
                    }
                }
            }


           if(n>9)
                printf("M");
            else
                printf("%d",n);


        }
        printf("\n");
    }


    return 0;

}

