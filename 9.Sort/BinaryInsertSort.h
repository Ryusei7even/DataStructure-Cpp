#ifndef BINARYINSERTSORT_H
#define BINARYINSERTSORT_H


// 折半插入排序
void BinInsertSort(int A[], int n)
{
    int i, j, low, high, mid, temp;
    for (i = 1; i <= n - 1; i++)
    {
        temp = A[i];
        low = 0;
        high = i - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (temp > A[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        for (j = i; j > low; j--)
            A[j] = A[j - 1];
        A[low] = temp;
    }
}

#endif 