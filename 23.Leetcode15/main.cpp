#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<vector<int>> res;
        for(int i=0;i<nums.size();++i){
            freq[nums[i]]++;
        }
        sort(nums.begin(),nums.end());
        vector<int>::iterator iter = unique(nums.begin(),nums.end());
        nums.erase(iter,nums.end());
        if(freq[0]>=3){
            res.push_back({0,0,0});
        }

        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                if(nums[i]*2+nums[j]==0&&freq[nums[i]]>=2){
                    res.push_back({nums[i],nums[i],nums[j]});
                }
                if(nums[i]+nums[j]*2==0&&freq[nums[j]]>=2){
                    res.push_back({nums[i],nums[j],nums[j]});
                }
                int c = 0-nums[i]-nums[j];
                if(c>nums[j]&&freq[c]>0){
                    res.push_back({nums[i],nums[j],c});
                }
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
