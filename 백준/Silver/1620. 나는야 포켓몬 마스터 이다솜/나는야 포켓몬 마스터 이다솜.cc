#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[21];
    int num;
}pokemon;

int compare(const void* first, const void* second) {
    pokemon *a = (pokemon*)first;
    pokemon *b = (pokemon*)second;
    if(strcmp(a->name,b->name)>0) {
        return 1;
    }
    else {
        return -1;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    pokemon poke[n];
    pokemon sortpoke[n];
    for(int i=0; i<n; i++) {
    	scanf("%s", poke[i].name);
    	poke[i].num=i+1;
    	sortpoke[i]=poke[i];
    }
    char see[21];
    qsort(sortpoke,n,sizeof(sortpoke[0]),compare);
    for(int i=0; i<m; i++) {
    	scanf("%s", see);
    	if(see[0]<='9'&&see[0]>='0') {
    		int a;
    		sscanf(see, "%d", &a);
    		printf("%s\n", poke[a-1].name);
    	}
    	else {
    		int l,r,m;
    		l=0,r=n-1;

    		while(l<=r) {
    			m=(l+r)/2;

    			if(strcmp(sortpoke[m].name,see)==0) {
                    printf("%d\n", sortpoke[m].num);
                    break;
    			}
    			else if(strcmp(sortpoke[m].name,see)>0) {
                    r=m-1;
    			}
    			else {
                    l=m+1;
    			}
    		}
    	}
    }

    return 0;
}

