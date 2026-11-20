#include <stdio.h>
#include <string.h>

char word[51];

void swap(size_t a, size_t b) {
    char temp = word[a];
    word[a]=word[b];
    word[b]=temp;

}

void reverse(size_t start, size_t end) {
    while (start < end) {
        swap(start, end);
        start++;
        end--;
    }
}

int main() {

    scanf("%s", word);

    int min = 'z'+1;

    size_t len = strlen(word);

    char ans[len+1];
    for(size_t i=0; i<len; i++) {
        ans[i]='z';
    }
    ans[len]='\0';

    int cnt=0;
    for(size_t i=0; i<len-2; i++) {
        for(size_t j= i + 1; j< len-1; j++){
			char tmp[len+1];
			int chloc=0;
			for (int p = i;p >= 0; p--) {
				tmp[chloc] = word[p];
				chloc++;
			}
			for (int p = j; p > i; p--) {
				tmp[chloc] = word[p];
				chloc++;
			}
			for (size_t p = len - 1; p > j; p--) {
				tmp[chloc] = word[p];
				chloc++;
			}

			tmp[len]='\0';

			if(strcmp(ans,tmp)>0){
				strcpy(ans,tmp);
			}
		}
    }

    printf("%s", ans);


    return 0;
}
