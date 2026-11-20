#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int weight;
	int height;
}big;

int main() {
	int n; 
	scanf("%d", &n);
	big persons[n];
	for(int i=0; i<n; i++) {
		scanf("%d %d", &persons[i].weight, &persons[i].height);
	}
	
	for(int i=0; i<n; i++) {
		int rank=1;
		for(int j=0; j<n; j++) {
			if(persons[i].height<persons[j].height && persons[i].weight<persons[j].weight) {
				rank++;
			}
		}
		printf("%d ", rank);
	}
	

	
	return 0;
}