#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for(int i=0;i<numbers.size();++i){
            for(int j=i+1;j<numbers.size();++j)
            {
                if(numbers[i]+numbers[j]==target)
                {
                    res.push_back(i+1);
                    res.push_back(j+1);
                    return res;
                }
            }
        }
    }

    vector<int> twoSum2(vector<int>& numbers, int target){
        vector<int> res;
        for(int i=0;i<numbers.size();++i){
            int j = BinarySearch(numbers,target-numbers[i],i);
            if(j!=-1){
                res.push_back(i+1);
                res.push_back(j+1);
                break;
            }
        }
        return res;
    }
    int BinarySearch(vector<int>& nums,int target,int i){
        int low = 0,high = nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if((nums[mid]==target)&&(mid!=i)){
                return mid;
            }
            else{
                if(nums[mid]<target){
                    low=mid+1;
                }
                else{
                    high =mid-1;
                }
            }
        }
        return -1;
    }


    vector<int> twoSum3(vector<int>& numbers, int target){
        int i=0,j=numbers.size()-1;
        vector<int> res;
        while(i<j){
            int sum =numbers[i]+numbers[j];
            if(sum==target){
                res.push_back(i+1);
                res.push_back(j+1);
                break;
            }
            else{
                if(sum<target){
                    ++i;
                }
                else{
                    --j;
                }
            }
        }
        return res;
    }
    void print_vec(vector<int>& numbers)
    {
        for(int i=0;i<numbers.size();++i){
            cout<<numbers[i]<<" ";
        }
    }
};

int main()
{
    vector<int> test = {1,2,3,4,4,9,56,90};
    vector<int> res(Solution().twoSum3(test,8));
    Solution().print_vec(res);
    return 0;
}
