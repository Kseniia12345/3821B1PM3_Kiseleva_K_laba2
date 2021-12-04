#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	long int min, max;
	long int* mas;
	FILE* file = 0;

	printf_s("¬ведите количество значений ");
	scanf_s("%d", &n);

	if (n <= 0) //проверка n
	{
		printf_s("ќшибка! Kоличество значений <=0");
		return 0;
	}
	mas = (long int*)malloc(n * sizeof(long int));
	if (mas == 0) //проверка создалс€ ли массив
	{
		printf_s("ќшибка! Hе удалось создать массив \n");
		return 0;
	}

	printf_s("¬ведите значение min ");
	scanf_s("%ld", &min);
	printf_s("¬ведите значение max ");
	scanf_s("%ld", &max);

	if (min > max) //проверка max и min
	{
		printf_s("ќшибка! min>max \n");
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		mas[i] = (((double)rand()) / RAND_MAX) * (max - min) + min;
		//printf_s("%lf \n", mas[i]);
	}

	fopen_s(&file, "..\\mas.txt", "w");

	fprintf(file, "n = %d\n", n);

	for (int i = 0; i < n; i++)
	{
		fprintf(file, "%ld\n", mas[i]);
	}

	fclose(file);
	free(mas);
	return 0;
}