#ifndef INSERTSORT_H
#define INSERTSORT_H

// 直接插入排序
void InsertSort(int A[], int n)
{
    int i, j, temp;
    for (i = 1; i <= n - 1; i++)
    {
        if (A[i] < A[i - 1])
        {
            j = i - 1;
            temp = A[i];
            while (j >= 0 && temp < A[j])
            {
                A[j + 1] = A[j];
                j--;
            }
            A[j + 1] = temp;
        }
    }
}

#endif 