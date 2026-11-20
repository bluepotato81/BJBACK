#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    int sti[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&sti[i]);
    }

    int cou=0;
    int max_=0;
    for(int i=n-1; i>=0; i--)
    {
        if(sti[i]>max_)
        {
            cou++;
            max_=sti[i];
        }
    }
    printf("%d", cou);




    return 0;
}
