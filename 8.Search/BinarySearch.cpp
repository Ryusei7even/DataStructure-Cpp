#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int *a, int n, int x)
{
    int left=0, right=n-1, mid;
    while(left<=right){
        mid = (left+right)/2;
        if(a[mid]==x)
            return mid;
        else if(x>mid)
            left=mid+1;
        else
            right=mid-1;
    }
    return -1;
}

int binarySearch_recur(int *a, int left, int right, int x)
{
    int mid;
    while(left<=right){
        mid = (left+right)/2;
        if(a[mid]==x)
            return mid;
        else if(x>mid)
            return binarySearch_recur(a, mid+1, right, x);
        else
            return binarySearch_recur(a, left, mid-1, x);
    }
    return -1;
}

int main()
{
    int arr[9] = {1, 3, 4, 7, 9, 11, 16, 20, 36};
    int res = binarySearch(arr, 9, 36);
    // int res2 = binarySearch_recur(arr, 0, 9, 16);
    cout << res << endl;
    return 0;
}


