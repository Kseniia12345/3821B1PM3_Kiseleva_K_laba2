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

	printf_s("������� ���������� �������� ");
	scanf_s("%d", &n);

	if (n <= 0) //�������� n
	{
		printf_s("������! K��������� �������� <=0");
		return 0;
	}
	mas = (long int*)malloc(n * sizeof(long int));
	if (mas == 0) //�������� �������� �� ������
	{
		printf_s("������! H� ������� ������� ������ \n");
		return 0;
	}

	printf_s("������� �������� min ");
	scanf_s("%ld", &min);
	printf_s("������� �������� max ");
	scanf_s("%ld", &max);

	if (min > max) //�������� max � min
	{
		printf_s("������! min>max \n");
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