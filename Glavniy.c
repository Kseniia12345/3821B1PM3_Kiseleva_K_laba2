#include<stdio.h>
#include <locale.h>
#include"Header.h"
#include <time.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n = 0, a = 0;
	long int* mas = 0;
	FILE* file = 0;
	int start = 0, end = 0, tim = 0;

	fopen_s(&file, "..\\mas.txt", "r");
	fscanf_s(file, "n = %d\n", &n);
	fclose(file);
	mas = (long int*)malloc(n * sizeof(long int));
	for (int i = 0; i < n; i++)
	{
		mas[i] = 0;
	}

	printf_s("Команды:\n1 - Печать\n2 - Сортировка\n3 - Заполнить массив\n4 - Очистить массив\n5 - Завершить работу\n");

	while (a != 5)
	{
		scanf_s("%d", &a);
		if (a == 1)
		{
			for (int i = 0; i < n; i++)
			{
				printf_s("mas[%d]  = %ld\n", i, mas[i]);
			}
		}
		else if (a == 2)
		{
			printf_s("Команды:\n1 - Пузырёк\n2 - Вставкой\n3 - Быстрая\n");
			scanf_s("%d", &a);
			if (a == 1)
			{
				start = clock();
				BubbleSort(mas, n);
				end = clock();
				tim = end - start;
				printf_s("Время работы: %d мс\n", tim);
			}
			if (a == 2)
			{
				start = clock();
				VstavkaSort(mas, n);
				end = clock();
				tim = end - start;
				printf_s("Время работы: %d мс\n", tim);
			}
			else if (a == 3)
			{
				start = clock();
				QuickSort(mas, n);
				end = clock();
				tim = end - start;
				printf_s("Время работы: %d мс\n", tim);
			}
		}
		
		else if (a == 3)
		{
			ScanFile(&mas, &n);
		}
		else if (a == 4)
		{
			for (int i = 0; i < n; i++)
			{
				mas[i] = 0;
			}
		}
		else if (a == 5)
		{
			break;
		}
		else
		{
			printf_s("Вы ввели неправильное значение\n");
			printf_s("Команды:\n1 - Печать\n2 - Сортировка\n3 - Заполнить массив\n4 - Очистить массив\n5 - Завершить работу\n");
		}
		printf_s("Введите число\n");
	}

	free(mas);
	return 0;
}