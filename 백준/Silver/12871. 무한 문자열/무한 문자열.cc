#include <stdio.h>
#include <string.h>

size_t lcm(size_t n, size_t m) {

    size_t nm=n,mm=m;
    if(n<m) {
        while(1) {
            if(mm%n==0) {
                break;
            }
            else {
                mm+=m;
            }
        }
        return mm;
    }
    else if(m<n) {
        while(1) {
            if(nm%m==0) {
                break;
            }
            else {
                nm+=n;
            }
        }
        return nm;
    }
    else {
        return n;
    }
}

int main() {
    char s[51];
    char t[51];

    scanf("%s", s);
    scanf("%s", t);

    size_t slen=strlen(s);
    size_t tlen=strlen(t);

    size_t l=lcm(slen, tlen);

    char coms[100001];
    char comt[100001];

    for(size_t i=0; i<l/slen;i++) {
        for(size_t j=0; j<slen;j++) {
            coms[i*slen+j]=s[j];
        }
        coms[l*slen]='\0';
    }
    for(size_t i=0; i<l/tlen;i++) {
        for(size_t j=0; j<tlen;j++) {
            comt[i*tlen+j]=t[j];
        }
        coms[l*tlen]='\0';
    }

    if(strcmp(coms, comt)==0) {
        printf("1");
    }
    else {
        printf("0");
    }

    return 0;
}
