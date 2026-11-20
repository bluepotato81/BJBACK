#include <iostream>
#include <vector>
#include <string.h>
#include <unordered_set>
#include <cstring>
#include <algorithm>
#include <stdlib.h>

using namespace std;

char names[500][21];
vector<vector<int>> group;

int parent[3000];

int seek(int x) {
    if(parent[x]==x) {
        return x;
    }
    else {
        return parent[x]=seek(parent[x]);
    }
}

void unite(int a, int b) {
    a=seek(a);
    b=seek(b);
    if(a!=b) {
        parent[b]=a;
    }
}

void subswitch(int a, int b) {
    parent[b]=a;
    parent[a]=a;
}


int namefind(char name[], int i) {
    if(!strcmp(name, names[i])) {
        return 1;
    }
    else{
        return 0;
    }
}

int cmpfunc(const void *a, const void *b) {
    const char *s1 = (const char *)a;
    const char *s2=(const char *)b;
    return strcmp(s1,s2);
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    char dummy[8];
    char dummy2[3];
    for(int i=0; i<n;i++) {
        scanf("%s %s %s",dummy, dummy2, names[i]);
        parent[i]=i;
    }

    char in1[21];
    char in2[21];
    int win;
    for(int i=0; i<m;i++) {
        scanf("%s %s %[^,],",dummy, dummy2, in1);
        scanf("%s %s %[^,],",dummy, dummy2, in2);
        scanf("%d", &win);

        int on,tn;
        for(int j=0;j<n;j++) {
            if(namefind(in1, j)) {
                on=j;
                break;
            }
        }
        for(int j=0;j<n;j++) {
            if(namefind(in2, j)) {
                tn=j;
                break;
            }
        }

        if(seek(on)==seek(tn)) {
            if(win==1) {
                subswitch(on, tn);
            }
            else {
                subswitch(tn, on);
            }
        }
        else {
            if(win==1) {
                unite(on,tn);
            }
            else {
                unite(tn, on);
            }
        }
    }


    unordered_set<int> roots;
    for(int i=0; i<n; i++) {
        roots.insert(seek(i));
    }

    printf("%zu\n", roots.size());


    char valnames[500][21];
    int point=0;
    for(int i=0; i<n;i++) {
        if(seek(i)==i) {
            size_t len=strlen(names[i]);
            for(size_t j=0; j<len;j++) {
                valnames[point][j]=names[i][j];
            }
            valnames[point][len]='\0';
            point++;
        }
    }

    qsort(valnames,point, sizeof(names[0]), cmpfunc);

    for (int i = 0; i < point; i++) {
        if(i!=point-1) {
            printf("Kingdom of %s\n", valnames[i]);
        }
        else {
            printf("Kingdom of %s", valnames[i]);
        }
    }

    return 0;
}
