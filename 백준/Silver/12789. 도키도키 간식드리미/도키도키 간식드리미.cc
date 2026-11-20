#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int student[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &student[i]);
    }

    int sidespace[n];
    int sidelen=0, mainlen=n;

    int curnum=1;

    while(1) {
        if(sidelen==0) {
            if(student[n-mainlen]==curnum) {
                mainlen--;
                curnum++;
            }
            else{
                sidespace[sidelen]=student[n-mainlen];
                sidelen++;
                mainlen--;
            }
        }
        else if(mainlen==0) {
            if(sidespace[sidelen-1]==curnum) {
                sidelen--;
                curnum++;
            }
            else {
                printf("Sad");
                return 0;
            }
        }
        else {
            if(student[n-mainlen]==curnum) {
                mainlen--;
                curnum++;
            }
            else if(sidespace[sidelen-1]==curnum) {
                sidelen--;
                curnum++;
            }
            else{
                sidespace[sidelen]=student[n-mainlen];
                sidelen++;
                mainlen--;
            }
        }
        if(curnum==n+1 && mainlen==0 && sidelen==0) {
            printf("Nice");
            break;
        }
        else if(curnum==n+1) {
            printf("Sad");
            break;
        }

        /*for(int i=mainlen; i>0;i--) {
            printf("%d ", student[n-i]);
        }
        printf("\n");
        for(int i=0; i<sidelen; i++) {
            printf("%d ", sidespace[i]);
        }
        printf("\n");*/
    }



    return 0;
}
