#ifndef MERGESORT_H
#define MERGESORT_H

// 归并排序
void Merge(int a[], int left, int mid, int right, int temp[])
{
    int i = left;
    int j = mid + 1;
    int t = 0;
    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
        {
            temp[t++] = a[i++];
        }
        else
        {
            temp[t++] = a[j++];
        }
    }
    while (i <= mid)
    {
        temp[t++] = a[i++];
    }
    while (j <= right)
    {
        temp[t++] = a[j++];
    }
    t = 0;
    while (left <= right)
    {
        a[left++] = temp[t++];
    }
}

void MergeSort(int a[], int left, int right, int temp[])
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(a, left, mid, temp);
        MergeSort(a, mid + 1, right, temp);
        Merge(a, left, mid, right, temp);
    }
}

#endif 
