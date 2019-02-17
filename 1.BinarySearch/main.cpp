#include <iostream>
#include <cmath>
#include <ctime>
#include <cassert>
#include "util.h"
using namespace std;


template<typename T>
int binarysearch(T arr[],int n,T target)
{
    int l = 0, r = n-1;
    //int mid = l+(r-l)/2;
    while(l<=r)
    {
        int mid =l+(r-l)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else
        {
            if(arr[mid]>target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }
    return -1;
}

template<typename T>
int binarysearch2(T arr[],int n,T target)
{
    int l = 0;
    int r = n;
    while(l<r)
    {
        int mid = l +(r-l)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        if(arr[mid]>target)
        {
            r = mid;
        }
        else
            l = mid +1;
    }
    return -1;
}


int main()
{
    int n = pow(10,7);
    int* data = MyUtil::generateOrderedArray(n);

    clock_t startTime = clock();
    for(int i=0;i<n;i++)
    {
        //cout<<"finding..."<<endl;
        assert(i==binarysearch2(data,n,i));
    }
    clockid_t endTime = clock();
    cout << "Binary Search test complete." << endl;
    cout << "Time cost: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    return 0;
}
