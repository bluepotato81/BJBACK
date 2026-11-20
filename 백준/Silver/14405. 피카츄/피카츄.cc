#include <stdio.h>

int main() {
    char pika[5001];
    scanf("%s", pika);
    
    int index=0;
    while(1) {
        if(pika[index]=='\0') {
            printf("YES");
            break;
        }
        
        if(pika[index]=='p' && pika[index+1]=='i') {
            index+=2;
        }
        else if(pika[index]=='k' && pika[index+1]=='a') {
            index+=2;
        }
        else if(pika[index]=='c' && pika[index+1]=='h' && pika[index+2]=='u') {
            index+=3;
        }
        else{
            printf("NO");
            break;
        }
    }
    
    return 0;
}