#include <stdio.h>
int main() {
	int notes[9];
	for(int i=0;i<8;i++) {
		scanf("%d", &notes[i]);
	}

	int upcheck=0;
	int downcheck=0;
	for(int i=0;i<8;i++) {
		if(notes[i]==i+1) {
			upcheck++;
		}
		else if(notes[i]==9-(i+1)) {
			downcheck++;
		}
	}

	if(upcheck==8) {
		printf("ascending");
		return 0;
	}

	if(downcheck==8) {
		printf("descending");
		return 0;
	}
	printf("mixed");



	return 0;
}
