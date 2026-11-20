#include <stdio.h>
#include <string.h>

char letters[50][51];
size_t len[50];
int addval[36][51] = {0,};

char watchchar[36];

void addin36(int *result, int pos, int value) {
    result[pos] +=value;
    while(result[pos]>=36) {
        result[pos]-=36;
        result[pos+1]++;
        pos++;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int max=0;
    for(int i=0; i<n; i++) {
        scanf("%s", letters[i]);
        len[i]=strlen(letters[i]);
        if(len[i]>max) {
            max=len[i];
        }
    }

    for(int i=0; i<10; i++) {
        watchchar[i]='0'+i;
    }
    for(int i=0; i<26; i++) {
        watchchar[i+10]='A'+i;
    }

    int k;
    scanf("%d", &k);

    for(int i=0; i<36; i++) {
        int repadd=35-i;
        for(int j=0; j<n; j++) {
            int see=len[j];
            for(int l=0; l<see; l++) {
                if(letters[j][l]==watchchar[i]) {
                    int p=see-l-1;
                    addin36(addval[i], p, repadd);
                }
            }
        }
    }

    int order[36];
    for(int i=0; i<36; i++) {
        order[i]=i;
    }

    for(int i=0; i<36; i++) {
        for (int j=i+1; j<36; j++) {
            int x=max;
            while (x >= 0 && addval[order[i]][x]==addval[order[j]][x]) {
                x--;
            }
            if (x >= 0 && addval[order[i]][x] < addval[order[j]][x]) {
                int temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }

    for(int i=0; i<k; i++) {
        char target=watchchar[order[i]];
        for (int j=0; j<n;j++) {
            for (int l=0; l<len[j]; l++) {
                if (letters[j][l]==target) {
                    letters[j][l]='Z';
                }
            }
        }
    }

    int finsum[55]={0};
    for(int i=0; i<n; i++) {
        for(int j=0; j<len[i]; j++) {
            int val = (letters[i][j]<='9') ? letters[i][j]-'0' : letters[i][j]-'A'+10;
            addin36(finsum, len[i]-j-1, val);
        }
    }

    int start=54;
    while (start>0 && finsum[start] == 0) {
        start--;
    }

    for(int i=start; i>=0; i--) {
        if(finsum[i]<10) {
            printf("%d", finsum[i]);
        }
        else {
            printf("%c", 'A'+finsum[i]-10);
        }
    }

    return 0;
}
