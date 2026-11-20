#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[6];
}person;

int compare_string(const void *a, const void *b) {
    const person *string1 = (const person *)a;
    const person *string2 = (const person *)b;
    return -1*(strcmp(string1->name, string2->name));
}

int main() {
    int n;
    scanf("%d", &n);
    int listlen=0;
    person employee[n];
    for(int i=0; i<n; i++) {
        char k[6], io[6];
        scanf("%s %s", k, io);
        strcpy(employee[i].name, k);
        if(io[0]=='e') {
            listlen++;
        }
        else {
            listlen--;
        }
    }

    qsort(employee, n, sizeof(person), compare_string);

    person cur_in[listlen];

    int ionum=0;
    int cur_listlen=0;
    for (int i = 0; i < n; i++) {
        ionum++;
        if(i==n+1||strcmp(employee[i].name, employee[i+1].name)!=0){
            if(ionum%2==1){
                strcpy(cur_in[cur_listlen].name, employee[i].name);
                cur_listlen++;
            }
            ionum=0;
        }
    }

    for(int i=0; i<listlen; i++) {
        printf("%s\n", cur_in[i].name);
    }


    return 0;
}
