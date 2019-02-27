#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int count_num = INT_MAX;
        for(int i=0;i<nums.size();++i){
            for(int j=i;j<nums.size();++j){
                int sum = 0;
                for(int k=i;k<=j;++k){
                    sum+=nums[k];
                }
                if(sum>=s){
                    if(j-i+1<count_num){
                        count_num=j-i+1;
                    }
                }
            }
        }
        if(count_num==INT_MAX){
            return 0;
        }
        else{
            return count_num;
        }
    }

    int minSubArrayLen2(int s, vector<int>& nums){
        vector<int> sum(nums.size()+1,0);
        int count_num = INT_MAX;
        for(int i=1;i<=nums.size();++i){
            sum[i]=sum[i-1]+nums[i-1];
        }
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<=nums.size();++j){
                if(sum[j]-sum[i]>=s){
                    if(j-i<count_num){
                        count_num = j-i;
                    }
                }
            }
        }
        if(count_num==INT_MAX){
            return 0;
        }
        else{
            return count_num;
        }
    }

    int minSubArrayLen3(int s, vector<int>& nums){
        int l=0,r=-1;
        int sum = 0;
        int len = nums.size()+1;
        while(l<nums.size()){

            if(r<(int)(nums.size()-1)&&sum<s){
                r++;
                sum+=nums[r];

            }
            else{
                sum-=nums[l];

                l++;
            }
            if(sum>=s){
                if(r-l+1<len){
                    len = r-l+1;
                }
            }
        }
        if(len==nums.size()+1){
            return 0;
        }
        else{
            return len;
        }
    }
};

int main()
{
    vector<int> num ={2,3,1,2,4,3};
    cout<<Solution().minSubArrayLen3(7,num);
    return 0;
}
