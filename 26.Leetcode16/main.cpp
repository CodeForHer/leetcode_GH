#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closet = INT_MAX;
        int sum = 0;
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                for(int k=j+1;k<nums.size();++k){
                    int sum_temp = nums[i]+nums[j]+nums[k];
                    if(abs(sum_temp-target)<closet){
                        closet = abs(sum_temp-target);
                        sum = sum_temp;
                    }
                }
            }
        }
        return sum;
    }

    int threeSumClosest2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff = abs(nums[0]+nums[1]+nums[2]-target);
        int res = nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();++i){
            int l = i+1,r = nums.size()-1;
            int t = target - nums[i];
            while(l<r){
                if(nums[l]+nums[r]==t){
                    return nums[i]+nums[l]+nums[r];
                }
                else{
                    if(abs(nums[l]+nums[r]-t)<diff){
                        diff = abs(nums[l]+nums[r]-t);
                        res = nums[i] + nums[l] +nums[r];
                    }
                }
                if(nums[l]+nums[r]<t)
                    ++l;
                else
                    --r;
            }
        }
        return res;
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
