#ifndef SELECTSORT_H
#define SELECTSORT_H

void SelectSort(int A[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[min] > A[j])
                min = j;
        }
        if (min != i)
        {
            temp = A[min];
            A[min] = A[i];
            A[i] = temp;
        }
    }
}

#endif 