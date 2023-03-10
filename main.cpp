#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <sys/time.h>

using namespace std;

void SortowanieBabelkowe(int arr[], int dlugoscciagu)
{

    int i,j;
    for(int j = 0; j < dlugoscciagu - 1; j++)
    for(int i = 0; i < dlugoscciagu - 1; i++)
    if(arr[i] > arr[i + 1])swap(arr[i], arr[i + 1]);

}

void SortowaniePrzezKopcowanie(int arr[], int dlugoscciagu){

int i,j,k,m,x;
// Tworzymy kopiec

  for(i = 2; i <= dlugoscciagu; i++)
  {
    j = i; k = j / 2;
    x = arr[i];
    while((k > 0) && (arr[k] < x))
    {
      arr[j] = arr[k];
      j = k; k = j / 2;
    }
    arr[j] = x;
  }

// Rozbieramy kopiec

  for(i = dlugoscciagu; i > 1; i--)
  {
    swap(arr[1], arr[i]);
    j = 1; k = 2;
    while(k < i)
    {
      if((k + 1 < i) && (arr[k + 1] > arr[k]))
        m = k + 1;
        else
        m = k;
      if(arr[m] <= arr[j]) break;
      swap(arr[j], arr[m]);
      j = m; k = j + j;
    }
  }

}
int main () {
    int iloscciagow = 6;
    int dlugoscciagu = 30;
    int ciag[dlugoscciagu];
    int ciag2[dlugoscciagu];
    unsigned long long a;
    srand (time (NULL));



    FILE *array1;
    FILE *bubble;
    FILE *heap;
    array1 = fopen("wygenerowaneciagi.txt", "a");
    bubble = fopen("sortowaniebabelkowe.txt", "a");
    heap = fopen("sortowanieprzezkopcowanie.txt", "a");

    for(int i = 0; i < iloscciagow; i++)
    {for(int j = 0; j < dlugoscciagu; j++)
    {
        ciag[j]=rand()%100;
        fprintf(array1, "%d ", ciag[j]);
    }
    fprintf (array1, "%s", "\n");
    }

    fclose(array1);
    array1 = fopen("wygenerowaneciagi.txt", "r");

    for(int k=0; k < iloscciagow; k++)
    {
        for(int j = 0; j < dlugoscciagu; j++)
        {
            fscanf(array1, "%d", &ciag[j]);
             ciag2[j] = ciag[j];
        }

        SortowanieBabelkowe(ciag, dlugoscciagu);
        SortowaniePrzezKopcowanie(ciag2, dlugoscciagu);
        for (int i=0; i < dlugoscciagu; i++)
        {
            fprintf (bubble, "%d ", ciag[i]);
            fprintf (heap, "%d ", ciag2[i]);
        }
            fprintf (bubble,"%s", "\n");
            fprintf (heap, "%s", "\n");
    }
    fclose (bubble);
    fclose (array1);
    fclose (heap); //zamkniecie plikow

    return 0;
}
