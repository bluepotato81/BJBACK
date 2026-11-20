#include <cstdio>

int main()
{
    char name[35];
    int alph[30]={};
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%s", name);
        alph[name[0]-'a']++;
    }

    int check=0;
    for(int i=0; i<26; i++)
    {
        if(alph[i]>=5)
        {
            printf("%c", i+'a');
            check++;
        }
    }

    if(check==0)
        printf("PREDAJA");


    return 0;

}

