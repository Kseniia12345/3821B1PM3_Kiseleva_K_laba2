#include<stdio.h>
#include"Header.h"

void PrintMas(long int* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf_s("mas[%d] = %ld\n", i, mas[i]);
	}
}

void CreateMas(long int** mas, int n)
{
	*mas = (long int*)malloc(n * sizeof(long int));
	for (int i = 0; i < n; i++)
	{
		(*mas)[i] = 0;
	}
}

void ScanN(FILE* file, int* n)
{
	fscanf_s(file, "n = %d\n", n);
}

void ScanMas(FILE* file, long int* mas, int n)
{
	for (int i = 0; i < n; i++)
		fscanf_s(file, "%ld\n", &(mas[i]));
}

void ScanFile(long int** mas, int* n)
{
	FILE* file = 0;

	fopen_s(&file, "..\\mas.txt", "r");

	ScanN(file, n);

	CreateMas(mas, *n);

	ScanMas(file, *mas, *n);

	fclose(file);
}

void BubbleSort(long int* mas, int n)
{
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
			if (mas[j] > mas[j + 1])
			{
				tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
	}
}

void VstavkaSort(long int* mas, int n)
{
	int tmp = 0;
	for (int i = 1; i < n; i++)
	{
		tmp = mas[i];
		for (int j = i - 1; j > 0; j--)
		{
			if (mas[j] > tmp)
			{
				mas[j + 1] = mas[j];
				mas[j] = tmp;
			}
		}
	}
}

void QuickSort(long int* mas, int n)
{
	int i = 0;
	int j = n - 1;
	int mid = mas[n / 2];

	do
	{
		while (mas[i] < mid) i++;
		while (mas[j] > mid) j--;

		if (i <= j)
		{
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) quick(mas, j + 1);
	if (i < n) quick(&mas[i], n - i);
}

void quick(long int* mas, int n)
{
	int i = 0;
	int j = n - 1;
	int mid = mas[n / 2];

	do
	{
		while (mas[i] < mid) i++;
		while (mas[j] > mid) j--;

		if (i <= j)
		{
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) quick(mas, j + 1);
	if (i < n) quick(&mas[i], n - i);
}