#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void moveZeroes1(vector<int>& nums)
    {
        vector<int> temp ;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]!=0)
            {
                temp.push_back(nums[i]);
            }
        }
        for(int i=0;i<temp.size();++i)
        {
            nums[i] = temp[i];
        }
        for(int i=temp.size();i<nums.size();++i)
        {
            nums[i] = 0;
        }
    }

    void moveZeroes2(vector<int> &nums)
    {
        int k = 0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]!=0)
            {
                nums[k++]=nums[i];
            }
        }
        for(int i=k;i<nums.size();++i)
        {
            nums[i]=0;
        }
    }

};


int main()
{
    int arr[] = {0,3,0,2,3,1,0,2};
    vector<int> vec(arr,arr+sizeof(arr)/sizeof(int));
    Solution().moveZeroes2(vec);
    for(int i=0;i<vec.size();++i)
    {
        cout<<vec[i]<<" ";
    }
    return 0;
}
