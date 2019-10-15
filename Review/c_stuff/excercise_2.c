#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float verify(int dices[6], int results[6])
{
  for (int i = 0; i < 6; i++) {
    results[dices[i]]++;
    if(results[dices[i]]==4)
    {
      return 1;
    }
  }
  for (size_t i = 0; i < 6; i++) {
    results[i]=0;
  }
  return 0;
}

int main(void){
 time_t t;
printf("Dice \n\n");

int i = 0;
int dices[6] = {6,1,2,3,4,5};
int results[6] = {0,0,0,0,0,0};

while(!verify(dices, results))
{
  srand ((unsigned) time(&t));
  for(i=0; i<5; i++){
  	dices[i] = rand()%(6-1) +1;
  	printf("%d ",dices[i]);
  }
  printf("\n");
}
	return 0;
}
