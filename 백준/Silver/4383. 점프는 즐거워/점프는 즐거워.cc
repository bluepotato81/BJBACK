#include <stdio.h>
#include <stdlib.h>

char in[5000];
int n,next,prev,jolly;

int main(){

   while (1 == scanf("%d",&n)){

      jolly = 1;

      for (int i=1;i<n;i++) in[i] = 0;
      scanf("%d",&prev);
      for (int i=1;i<n;i++) {
         scanf("%d",&next);
         int j = abs(next-prev);
         if (j < 1 || j >= n || in[j]++) jolly = 0;
         prev = next;
      }
      if (jolly) printf("Jolly\n");
      else printf("Not jolly\n");
   }
}
