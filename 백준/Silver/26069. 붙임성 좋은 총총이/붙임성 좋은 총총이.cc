#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[21];
    int dance;
} person;

int findPersonIndex(person people[], int ppllen, char* name) {
    for (int i = 0; i < ppllen; i++) {
        if (strcmp(people[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int a;
    scanf("%d", &a);
    person people[a*2];
    int ppllen = 0;

    for (int i = 0; i < a; i++) {
        char aName[21], bName[21];
        scanf("%s %s", aName, bName);

        int aIndex = findPersonIndex(people, ppllen, aName);
        int bIndex = findPersonIndex(people, ppllen, bName);

        if (aIndex == -1) {
            aIndex = ppllen;
            strcpy(people[ppllen].name, aName);
            people[ppllen].dance = (strcmp(aName, "ChongChong") == 0) ? 1 : 0;
            ppllen++;
        }

        if (bIndex == -1) {
            bIndex = ppllen;
            strcpy(people[ppllen].name, bName);
            people[ppllen].dance = (strcmp(bName, "ChongChong") == 0) ? 1 : 0;
            ppllen++;
        }

        if (people[aIndex].dance == 1 || people[bIndex].dance == 1) {
            people[aIndex].dance = 1;
            people[bIndex].dance = 1;
        }
    }

    int dancenum = 0;
    for (int i = 0; i < ppllen; i++) {
        if (people[i].dance == 1) {
            dancenum++;
        }
    }

    printf("%d\n", dancenum);
    return 0;
}
