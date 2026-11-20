#include <cstdio>

int main()
{
    char word[105];
    scanf("%s",word);


    for(int i=0; word[i]!='\0'; i++)
    {
        if(word[i]>='A' && word[i]<= 'Z')
            word[i]=word[i]+'a'-'A';
        else if(word[i]>='a' && word[i]<= 'z')
            word[i]=word[i]-'a'+'A';
    }

    printf("%s", word);


    return 0;

}
