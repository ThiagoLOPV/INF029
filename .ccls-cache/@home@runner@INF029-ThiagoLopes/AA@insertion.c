#include <stdio.h>
#define TAM 6
int main()
{
    int key;
    int vet[TAM] = {5,2,4,6,1,3};
    for(int i =2; i < TAM; i++)
    {
        key = vet[i];
        int j = i - 1;
        while(j>0 && vet[j]>key)
        {
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = key;
    }
}