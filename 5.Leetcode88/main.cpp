#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m,j=0;j<n;++i,++j)
        {
            nums1[i]=nums2[j];
        }
        sort(nums1.begin(),nums1.end());
    }
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> save;
        int i=0,j=0;
        while((i<m)&&(j<n))
        {
            if(nums1[i]<=nums2[j])
            {
                save.push_back(nums1[i]);
                ++i;
            }
            else
            {
                save.push_back(nums2[j]);
                ++j;
            }
        }
        while(i<m)
        {
            save.push_back(nums1[i]);
            ++i;
        }
        while(j<n)
        {
            save.push_back(nums2[j]);
            ++j;
        }
        nums1.assign(save.begin(),save.end());
    }
    void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n){
        for(int i=m-1,j=m+n-1;i>=0;--i,--j)
        {
            nums1[j]=nums1[i];
        }
        int i=n,j=0,index=0;
        while((i<m+n)&&(j<n))
        {
            if(nums1[i]<nums2[j])
            {
                nums1[index++]=nums1[i++];
            }
            else
            {
                nums1[index++]=nums2[j++];
            }
        }
        while(j<n)
        {
            nums1[index++]=nums2[j++];
        }
    }
    void print(vector<int>& nums)
    {
        for(int i=0;i<nums.size();++i)
        {
            cout<<nums[i]<<" ";
        }
    }
};

int main()
{
    int arr1[]={1,2,3,3,4,4,5,6,0,0,0};
    int arr2[]={2,5,6};
    vector<int> nums1(arr1,arr1+sizeof(arr1)/sizeof(int));
    vector<int> nums2(arr2,arr2+sizeof(arr2)/sizeof(int));
    Solution().merge3(nums1,8,nums2,3);
    Solution().print(nums1);
    return 0;
}
