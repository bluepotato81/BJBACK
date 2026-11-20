#include <cstdio>

int main()
{
    char str[55];

    scanf("%s", str);

    int a,b=2,l=0;
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i]=='(')
        {
            a=0;
        }
        else if(str[i]==')')
        {
            a=1;
        }

        if(a==b)
        {
            l+=5;
        }
        else
        {
            l+=10;
        }
        b=a;
    }

    printf("%d", l);

    return 0;

}
