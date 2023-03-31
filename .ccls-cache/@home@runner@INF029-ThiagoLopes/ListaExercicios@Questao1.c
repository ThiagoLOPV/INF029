//Crie um programa que leia um número N de unidades, e imprima todas idades maior que a média delas
#include <stdio.h>

void main()
{
  int n;
  int media = 0;
  int i = 0;
  int soma = 0;
  printf("Quantas idades?");
  scanf("%i", &n);
  int vet[n];
  
  for(int i=0; i < n;i++)
  {
    printf("Digite a idade %i\n", i+1);
    scanf("%i", &vet[i]);
    soma += vet[i];
  }

  media = soma/n;
  
  for(i=0; i < n;i++)
  {
    if(vet[i]>media)
    {
      printf("%i \n", vet[i]);
    }
  }
}