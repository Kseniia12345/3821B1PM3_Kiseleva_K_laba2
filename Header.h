#ifndef __HEADER_H__
#define __HEADER_H__

void PrintMas(long* mas, int n);

void CreateMas(long** mas, int n);

void ScanN(FILE* file, int* n);

void ScanMas(FILE* file, long int* mas, int n);

void ScanFile(long int** mas, int* n);

void BubbleSort(long int* mas, int n);

void VstavkaSort(long int* mas, int n);

void QuickSort(long int* mas, int n);

void quick(long int* mas, int n);

#endif