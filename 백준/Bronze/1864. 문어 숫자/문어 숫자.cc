#include <cstdio>


int main()
{
    char oct[13];

    while(1)
    {
        scanf("%s",oct);
        if(oct[0] == '#')
            break;

        int len=0;
        for(int i=0; oct[i]; i++)
        {
            len++;
        }

        int edou=1, ans=0;
        for(int i=len-1; i>=0; i--)
        {
            if(oct[i]=='-')
                ans+=0;
            else if(oct[i]=='\\')
                ans+=edou;
            else if(oct[i]=='(')
                ans+=edou*2;
            else if(oct[i]=='@')
                ans+=edou*3;
            else if(oct[i]=='?')
                ans+=edou*4;
            else if(oct[i]=='>')
                ans+=edou*5;
            else if(oct[i]=='&')
                ans+=edou*6;
            else if(oct[i]=='%')
                ans+=edou*7;
            else if(oct[i]=='/')
                ans+=edou*-1;

            edou*=8;
        }
        printf("%d\n", ans);
    }

    return 0;
}

