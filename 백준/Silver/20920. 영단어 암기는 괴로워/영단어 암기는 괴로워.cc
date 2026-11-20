#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char word[11];
    size_t len;
    int fre;

}memory;

int compare_string(const void *a, const void *b) {
    const memory *word1 = (const memory *)a;
    const memory *word2 = (const memory *)b;

    if(word1->len > word2->len) {
        return -1;
    }
    else if(word1->len < word2->len) {
        return 1;
    }
    else {
        return strcmp(word1->word, word2->word);
    }
}

int compare_frequency(const void *a, const void *b) {
    const memory *word1 = (const memory *)a;
    const memory *word2 = (const memory *)b;

    if(word1->fre > word2->fre) {
        return -1;
    }
    else if(word1->fre < word2->fre) {
        return 1;
    }
    else {
        if(word1->len > word2->len) {
            return -1;
        }
        else if(word1->len < word2->len) {
            return 1;
        }
        else {
            return strcmp(word1->word, word2->word);
        }
    }

}

int main() {
    int n;
    size_t m;
    scanf("%d %d", &n, &m);

    memory words[n];

    int memlen=0;
    for(int i=0; i<n; i++) {
        char w[11];
        scanf("%s", w);
        size_t le=strlen(w);
        if(le>=m) {
            strcpy(words[memlen].word, w);
            words[memlen].len = le;
            memlen++;
        }
    }

    qsort(words, memlen, sizeof(memory), compare_string);

    for(int i=0; i<memlen; i++) {
        int fr=1;
        int mark=i;
        while(1) {
            if(i+1<memlen) {
                if(strcmp(words[i].word, words[i+1].word)==0) {
                    fr++;
                    i+=1;
                }
                else {
                    break;
                }
            }
            else {
                break;
            }
        }
        for(int j=mark+1; j<mark+fr; j++) {
            strcpy(words[j].word, "1");
            words[j].len=1;
            words[j].fre=1;
        }
        words[mark].fre = fr;
    }

    qsort(words, memlen, sizeof(memory), compare_frequency);

    for(int i=0; i<memlen; i++) {
        if(strcmp(words[i].word, "1")!=0) {
            printf("%s\n", words[i].word);
        }


    }

    return 0;
}
