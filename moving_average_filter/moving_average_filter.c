#define MASK_LENGTH 	(3)

#include <stdio.h>
#include <stdbool.h>

int raw_array[MASK_LENGTH] = {0,};
int raw_array_index = 0;
float x;
/* Mask 크기만큼 데이터를 평균낸다. */
float movingAverageFilter()
{
    int i = 0;
    int sum = 0;

    for (i = 0; i < MASK_LENGTH; i++) {
    	sum += raw_array[i];
    }
    return ((float)sum / MASK_LENGTH);
}

/* 새로운 데이터를 array에 넣는다. */
void insertIntoRawArray(int value)
{
    raw_array[raw_array_index] = value;

    raw_array_index++;

    if (raw_array_index >= MASK_LENGTH) {
    	raw_array_index = 0;
    }
}

int main(void)
{
	while(true)
	{	
		printf("입력    ");
		scanf("%f",&x);
		insertIntoRawArray(x);
		printf("%f\n", movingAverageFilter());
	}
	
return 0;
}