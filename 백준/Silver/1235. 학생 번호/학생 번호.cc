#include <cstdio>

char stu_num[1005][105];

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%s", stu_num[i]);
    }

    int len = 0;
    for(; stu_num[0][len]; len++);

    int st=1;
    for(; st<=len; st++)
    {
        int same=1;

        for(int j=0; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                same=1;
                for(int p=len-1; p>len-1-st; p--)
                {
                    if(stu_num[j][p]!=stu_num[k][p])
                    {
                        same=0;
                        break;
                    }
                }
                if(same==1)
                    break;
            }
            if(same==1)
                break;
        }
        if(same==0)
            break;

    }

    printf("%d", st);
    return 0;
}

