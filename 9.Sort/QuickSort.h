#ifndef QUICKSORT_H
#define QUICKSORT_H

int partition(int *a, int left, int right)
{
    // 基准数据，a[left]也称主元
    int tmp = a[left];
    while (left < right)
    {
        while (left < right && a[right] >= tmp)
        {
            right--;
        }
        a[left] = a[right];
        while (left < right && a[left] <= tmp)
        {
            left++;
        }
        a[right] = a[left];
    }
    a[left] = tmp; //把temp放到1eft与 right相遇的地方
    return left;   // 返回相遇的下标
}

// 快速排序
void QuickSort(int *a, int left, int right)
{
    if (left >= right)
        return;
    int pivot = partition(a, left, right);
    QuickSort(a, left, pivot - 1);
    QuickSort(a, pivot + 1, right);
}

#endif 
