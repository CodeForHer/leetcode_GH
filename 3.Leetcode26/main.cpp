#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for(int i=0;i<nums.size();++i)
        {
            if((k==0)||(nums[i]!=nums[k-1]))
            {
                nums[k++]=nums[i];
            }
        }
        return k;
    }
    void PrintVector(vector<int> &nums)
    {
        for(int i=0;i<nums.size();++i)
        {
            cout<<nums[i]<<" ";
        }
    }
};
int main()
{
    int arr[] = {0,2,3,2,3,4,5,6,4,5,6,2};
    vector<int> test(arr,arr+sizeof(arr)/sizeof(int));
    sort(test.begin(),test.end());
    Solution().PrintVector(test);
    cout<<Solution().removeDuplicates(test);
}
