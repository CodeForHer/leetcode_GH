#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size()-1;
        return nums[find_pivot_rank(nums,0,len,k)];
    }
    int find_pivot_rank(vector<int>& nums,int left,int right,int k)
    {
        if(left==right)
        {
            return left;
        }
        int pivot=nums[left];
        int i=left,j=right,len=right-left+1;
        while(i<j)
        {
            while((i<j)&&(nums[j]<=pivot))
            {
                --j;
            }
            if(i<j)
            {
                nums[i]=nums[j];
                ++i;
            }
            while((i<j)&&(nums[i]>pivot))
            {
                ++i;
            }
            if(i<j)
            {
                nums[j]=nums[i];
                --j;
            }
        }
        nums[i]=pivot;
        int cur_rank = i-left+1;
        if(cur_rank==k)
        {
            return i;
        }
        else
        {
            if(cur_rank<k)
            {
                return find_pivot_rank(nums,i+1,right,k-cur_rank);
            }
            else
            {
                return find_pivot_rank(nums,left,i-1,k);
            }
        }
    }
    /*int findKthLargest2(vector<int>& nums, int k)
    {
        int length = nums.size();
        if(pivot(nums,0,length)==k)
        {
            return nums[k];
        }
        else
        {
            if(pivot(nums,0,length)k)
            {
                findKthLargest2(nums,)
            }
        }
    }*/
};

int main()
{
    int arr[]={3,2,3,1,2,4,5,5,6};
    vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));
    cout<<Solution().findKthLargest(nums,7);
    return 0;
}
