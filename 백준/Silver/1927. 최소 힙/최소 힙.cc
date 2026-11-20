#include <stdio.h>
#include <stdlib.h>


int compare_integers(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}


int main() {
    int t;
    scanf("%d", &t);
    int nums[t];

    for(int i=0; i<t; i++) {
        nums[i]=-1;
    }

    int in;
    int listlen=0;
    for(int i=0; i<t; i++) {
        scanf("%d", &in);
        if(in==0) {
            if(listlen==0) {
                printf("0\n");
            }
            else {
                printf("%d\n", nums[listlen-1]);
                nums[listlen-1]=-1;
                listlen--;
            }
        }
        else {
            int in_spot=listlen;
            while (in_spot > 0 && nums[in_spot - 1] < in) {
                nums[in_spot] = nums[in_spot - 1];
                in_spot--;
            }
            nums[in_spot] = in;
            listlen++;
        }
    }




	return 0;
}
