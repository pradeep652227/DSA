/* Approach#2 Gap Method*/
#include <bits/stdc++.h>
using namespace std;

int nextGap(int gap)
{
    if(gap <= 1)
        return 0;

    return (gap / 2) + (gap % 2);
}

void merge(long long arr1[], long long arr2[], int n, int m)
{
    int gap = nextGap(n + m);

    while(gap > 0)
    {
        int left = 0;
        int right = gap;

        while(right < n + m)
        {
            // Both pointers in arr1
            if(left < n && right < n)
            {
                if(arr1[left] > arr1[right])
                    swap(arr1[left], arr1[right]);
            }

            // left in arr1, right in arr2
            else if(left < n && right >= n)
            {
                if(arr1[left] > arr2[right - n])
                    swap(arr1[left], arr2[right - n]);
            }

            // Both pointers in arr2
            else
            {
                if(arr2[left - n] > arr2[right - n])
                    swap(arr2[left - n], arr2[right - n]);
            }

            left++;
            right++;
        }

        gap = nextGap(gap);
    }
}