#include<stdio.h>
#include <locale.h>
#include"Header.h"
#include <time.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, a = 0;
	long int* mas = 0;
	FILE* file = 0;
	int start = 0, end = 0, tim = 0;

	printf_s("������� 1 ��� ���������� ���������, 2 - ��������, 3 - ������, 4 - ���������\n");
	while (a != 4)
	{
		scanf_s("%d", &a);
		if (a == 1)
		{
			ScanFile(&mas, &n);
			start = clock();
			BubbleSort(mas, n);
			end = clock();
			tim = end - start;
			printf_s("��������� �������: %d ��\n", tim);
			printf_s("������� �����\n");
		}
		else if(a == 2)
		{
			ScanFile(&mas, &n);
			start = clock();
			VstavkaSort(mas, n);
			end = clock();
			tim = end - start;
			printf_s("��������� �������: %d ��\n", tim);
			printf_s("������� �����\n");
		}
		
		else if (a == 3)
		{
			ScanFile(&mas, &n);
			start = clock();
			QuickSort(mas, n);
			end = clock();
			tim = end - start;
			printf_s("��������� �������: %d ��\n", tim);
			printf_s("������� �����\n");
		}
		
		else if (a == 4)
		{
			break;
		}
		else
		{
			printf_s("�� ����� ������������ ��������\n");
			printf_s("������� 1 ��� ���������� ���������, 2 - ��������, 3 - ������, 4 - ���������\n");
		}
	}

	free(mas);
	return 0;
}