#include <cstdio>
int main()
{
    int stu[1005][5];

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<5; j++)
        {
            scanf("%d", &stu[i][j]);
        }
    }


    int max_=0, pre;
    for(int i=0; i<n; i++)
    {
        int same_c=0;
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<5; k++)
            {
                if(stu[i][k]==stu[j][k])
                {
                    same_c++;
                    break;
                }
            }
        }
        if(same_c>max_)
        {
            max_=same_c;
            pre=i+1;
        }
    }

    printf("%d", pre);

    return 0;

}

