#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cuttingMinutes (int * hours, int * minutes);

int main(int argc, char *argv[]){
  int hours,minutes;
  printf("Please enter the number of hours :\n");
  scanf("%d",&hours);
  printf("Please enter the number of minutes :\n");
  scanf("%d",&minutes);
  cuttingMinutes (&hours, &minutes) ;
  printf("%d hours and %d minutes\n", hours, minutes);
  return 0;
}

void cuttingMinutes (int * hours, int * minutes){
  *hours = *hours + (*minutes/60);
  *minutes = *minutes%60;
}
