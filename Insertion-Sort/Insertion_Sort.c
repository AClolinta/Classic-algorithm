#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define loop(s,n) for (int i = s; i < (n); i++) //From S to N power by [i]
void Insertion_Sort(int *a, int n);
int main()
{
	int *a,n;
	printf("Please input the N:");
	scanf("%d", &n);
	a = ( int * ) malloc (n * sizeof(int) );
	if (a != NULL)
	{
		srand( (time_t) time(NULL) );
		loop(0,n)
		{
			*(a+i) = rand() % n;
		}
		loop(0,n)
		{
			printf("%5d" , *(a + i));
			if ((i + 1) % 10 == 0)
				printf("\n");
		}
		printf("\n");
		Insertion_Sort(a, n);
		loop(0, n)
		{
			printf("%5d", *(a + i));
			if ((i + 1) % 10 == 0)
				printf("\n");
		}
	}
	system("pause");
	return 0;
}
void Insertion_Sort(int *a, int n)
{
	int key,i,j;
	for ( i = 1; i < n; i++ )
	{
		key = *(a +i);													//Pick the [i]th card
		for (j = i; j > 0 && *(a + j - 1) > key; j--)			//Compare left side. If left card larger than the [i]th card, exchange them
		{
			*(a + j) = *(a + j - 1);									//RUSH RUSH RUSH
		}
		*(a + j) = key;													//Send the [i]th card to the border
	}
}