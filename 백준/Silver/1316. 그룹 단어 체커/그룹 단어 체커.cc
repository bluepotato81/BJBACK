#include <cstdio>


int main()
{
    int n;
    scanf("%d", &n);

    char wor[105];
    int cou=n;
    for(int i=0; i<n; i++)
    {
        scanf("%s", wor);
        int al[26]={};
        for(int j=0; wor[j]; j++)
        {
            if(al[wor[j]-'a'] == 1)
            {
                if(wor[j]!=wor[j-1])
                {
                    cou--;
                    break;
                }
            }
            al[wor[j]-'a']=1;
        }
    }
    printf("%d",cou);



    return 0;
}

