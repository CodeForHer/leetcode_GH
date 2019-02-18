#include <iostream>
#include <algorithm>


using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
    void sortColors2(vector<int>& nums){
        int Count[3]={0,0,0};
        for(int i=0;i<nums.size();++i)
        {
            Count[nums[i]]++;
        }
        int index = 0;
        for(int i=0;i<Count[0];++i)
        {
            nums[index++]=0;
        }
        for(int i=0;i<Count[1];++i)
        {
            nums[index++]=1;
        }
        for(int i=0;i<Count[2];++i)
        {
            nums[index++]=2;
        }
    }
    void sortColors3(vector<int>& nums)
    {
        int zero = -1;
        int two = nums.size();
        for(int i=0;i<two;)//注意这里终止条件是i<two,当i=two-1时，意味着正在处理最后一个元素
        {
            if(nums[i]==0)
            {
                if(i!=zero+1)
                    swap(nums[i],nums[zero+1]);
                ++i;
                ++zero;
            }
            else if(nums[i]==1)
            {
                ++i;
            }
            else
            {
                swap(nums[two-1],nums[i]);
                --two;
            }
        }
    }
};

int main()
{
    int arr[]={0,0,0,0,2,2,1,1,2,0};
    vector<int> test(arr,arr+sizeof(arr)/sizeof(int));
    Solution().sortColors3(test);
    for(int i=0;i<test.size();++i)
    {
        cout<<test[i]<<" ";
    }
    return 0;
}
