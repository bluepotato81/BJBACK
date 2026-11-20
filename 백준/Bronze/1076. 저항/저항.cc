#include <stdio.h>
#include <string.h>

int main() {
    char color[7];
    long long tot=0;
    for(int i=0; i<2; i++) {
        scanf("%s", color);
        if(color[0]=='b') {
            if(color[1]=='l') {
                if(color[2]=='u') {
                    tot+=6;
                }
            }
            if(color[1]=='r') {
                tot+=1;
            }
        }
        if(color[0]=='r') {
            tot+=2;
        }
        if(color[0]=='o') {
            tot+=3;
        }
        if(color[0]=='y') {
            tot+=4;
        }
        if(color[0]=='g') {
            if(color[3]=='e') {
                tot+=5;
            }
            else {
                tot+=8;
            }
        }
        if(color[0]=='v') {
            tot+=7;
        }
        if(color[0]=='w') {
            tot+=9;
        }
        tot*=10;
    }
    tot/=10;

    scanf("%s", color);
    if(color[0]=='b') {
        if(color[1]=='l') {
            if(color[2]=='u') {
                tot*=1000000;
            }
        }
        if(color[1]=='r') {
            tot*=10;
        }
    }
    if(color[0]=='r') {
        tot*=100;
    }
    if(color[0]=='o') {
        tot*=1000;
    }
    if(color[0]=='y') {
        tot*=10000;
    }
    if(color[0]=='g') {
        if(color[3]=='e') {
            tot*=100000;
        }
        else {
            tot*=100000000;
        }
    }
    if(color[0]=='v') {
        tot*=10000000;
    }
    if(color[0]=='w') {
        tot*=1000000000;
    }
    printf("%lld", tot);

    return 0;
}
