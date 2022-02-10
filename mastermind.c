#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#define no_of_swaps 100
#define no_of_digits 3
int read_int(int *intp)
{
	char buf[16];
	char *retp;
	char *endptr;
	long input;

	retp = fgets(buf, sizeof(buf), stdin);
	if (retp == NULL)
		return -1;
	input = strtol(retp, &endptr, 10);

	if (*endptr != '\n')
		return -2;
	if (input > INT_MAX)
		return -2;
	if (input < INT_MIN)
		return -2;
	return 0;
}
void swap_array(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int main(void)
{
	srand(time(NULL));
	int no_of_chances = 8, randindex1, randindex2;
	int i, guess_num, input_num, bull, cows, temp;

	for (i = 0; i < no_of_swaps; i++) {
		randindex1 = rand()%10;
		randindex2 = rand()%10;
		swap_array(digits, randindex1, randindex2);
	}
	if (digits[0] == 0) {
		randindex1 = 0;
		randindex2 = rand()%10;
		swap_array(digits, randindex1, randindex2);
	}
	guess_num = digits[0]*1000 + digits[1]*100 + digits[2]*10 + digits[3]*1;
	printf("guess number = %d\n", guess_num);
	while (no_of_chances != 0) {
		bull = 0;
		cows = 0;
		printf("Enter your guess: ");
		scanf("%d", &input_num);
		temp = read_int(&input_num);
		if (temp == 0) {
			for (i = no_of_digits; i >= 0; i--) {
				if (digits[i] == input_num%10)
					bull++;
				else
					cows++;
				input_num = input_num/10;
			}
			printf("%d bulls, %d cows\n", bull, cows);
			if (bull == 4)
				break;
			no_of_chances--;
			printf("remaining chances = %d\n", no_of_chances);
		} else
			printf("enter integer\n");
	}
}

