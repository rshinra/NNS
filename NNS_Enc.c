#include<stdio.h>
#include<stdlib.h>

int main()
{
  char line[64];
  long cur;
  short ones = -1;
  short tens = 0;
  long hund = -1;

  while(fgets(line,sizeof(line),stdin))
  {
    cur = atoi(line);
    //printf("%ld %ld\n",(cur/10)%10, cur %10);
    if(hund < cur/100)
    {
      while(hund < cur/100)
        hund++;
      if(hund)
        printf("\n%02ld ", hund);
      else
        printf("%02ld ", hund);
      tens = 0;
      ones = -1;
    }
    if((cur/10)%10 - tens > 1)
    {
      ones = 9;
      while((cur/10)%10 - tens > 1)
      {
        tens++;
        printf("-");
      }
    }
    else if((cur/10)%10 - tens)
    {
      tens++;
      if(cur%10 > ones)
        printf(".%d", ones=cur%10);
      else
        printf("%d", ones=cur%10);
    }
    else
      printf("%d", ones=cur%10);
  }
  printf("\n");
  return 0;
}
