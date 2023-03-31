#include <stdio.h>


int Soma(int x,int y)
{
  return x+y;
}

void main()
{
  int x,y,s;
  scanf("%d", &x); 
  scanf("%d", &y); 

  s = Soma(x,y);
  printf("%i", s);
}

