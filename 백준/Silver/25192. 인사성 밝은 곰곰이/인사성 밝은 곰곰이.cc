#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[21];
} person;

int compare_string(const void *a, const void *b) {
    return strcmp(((person *)a)->name, ((person *)b)->name);
}

int main() {
    int a;
    scanf("%d", &a);

    person hellos[a + 3];
    int total_unique_names = 0;
    int listlen = 0;

    int k;

    for (int i = 0; i < a; i++) {
        char input[21];
        scanf("%s", input);

        if (strcmp(input, "ENTER") == 0 && listlen!=0) {
            qsort(hellos, listlen, sizeof(person), compare_string);
            k=1;
            for(int i=0; i<listlen-1; i++) {
                if(strcmp(hellos[i].name, hellos[i+1].name)!=0) {
                    k++;
                }
            }
            total_unique_names+=k;
            listlen=0;
        }
        else if(strcmp(input, "ENTER")!=0) {
            strcpy(hellos[listlen].name, input);
            listlen++;
        }

    }

    qsort(hellos, listlen, sizeof(person), compare_string);
    if(listlen!=0) {
        k=1;
        for(int i=0; i<listlen-1; i++) {
            if(strcmp(hellos[i].name, hellos[i+1].name)!=0) {
                k++;
            }
        }
        total_unique_names+=k;
    }



    printf("%d\n", total_unique_names);
    return 0;
}
