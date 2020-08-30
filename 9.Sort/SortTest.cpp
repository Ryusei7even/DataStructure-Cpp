#include <iostream>
#include <algorithm>
#include "BinaryInsertSort.h"
#include "InsertSort.h"
#include "BubbleSort.h"
#include "SelectSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include <time.h>
#define maxSize 10000
using namespace std;


void ReArrange( int *a){
    for (int i = 0; i < maxSize; i++)
    {
        a[i] = rand();
    }
    
}

int temp[maxSize]; //归并排序需要的temp数组
int arr[maxSize];
int main()
{

    srand((unsigned int)time(NULL)); //随机数种子

    ReArrange(arr);

    clock_t start_time = clock();
    InsertSort(arr, maxSize);
    clock_t end_time = clock();

    cout << "InsertSort running time: " << end_time - start_time << " ms" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    ReArrange(arr);

    clock_t start_time2 = clock();
    MergeSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, temp);
    clock_t end_time2 = clock();

    cout << endl;
    cout << "MergeSort running time: " << end_time2 - start_time2 << " ms" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    ReArrange(arr);

    clock_t start_time3 = clock();
    QuickSort(arr, 0,  maxSize-1);
    clock_t end_time3 = clock();


    cout << endl;
    cout << "QuickSort running time: " << end_time3 - start_time3 << " ms" << endl;

     for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}