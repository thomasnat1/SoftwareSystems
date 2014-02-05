#include <stdio.h>
#include <stdlib.h>

void updateCount(int val, int *count){
	if((val >= 2) && (val < 7)){
		*count = *count + 1;
	}else if(val == 10){
		*count = *count - 1;
	}
}

int readCard(){
	char card_name[3];
	puts("Enter the card_name: ");
	scanf("%2s", card_name);
	switch(card_name[0]){
	case 'K':
	case 'Q':
	case 'J': 
		return 10;
	case 'A':
		return 11;
	case 'X':
		return 0;
	default:
		return atoi(card_name);
	}
}

int main(){
	int count = 0;
	int val = -1;
	while(val != 0){
		val = readCard();
		if(val == 0){
			continue;
		}else if((val < 1) || (val > 11)){
			puts("I don't understand that value!");
			continue;
		}

		updateCount(val, &count);
		printf("current count: %i\n", count);
	}
	return 0;
}