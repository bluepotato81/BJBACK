#include <stdio.h>
#include <string.h>


int main() {
    char in[51];

    int am[26]={0,};

    scanf("%s", in);

    size_t len=strlen(in);

    for(size_t i=0; i<len;i++){
        am[in[i]-'A']++;
    }

    int odd=0;
    int oddlet;
    for(int i=0; i<26;i++){
        if(am[i]%2==1) {
            odd++;
            if(odd>1) {
                printf("I'm Sorry Hansoo");
                return 0;
            }
            oddlet=i;
        }
    }

    for(int i=0; i<26;i++){
        for(int j=0; j<am[i]/2;j++) {
            printf("%c", i+'A');
        }
    }

    if(odd==1) {
        printf("%c", oddlet+'A');
    }

    for(int i=25; i>=0;i--){
        for(int j=0; j<am[i]/2;j++) {
            printf("%c", i+'A');
        }
    }


    return 0;
}
