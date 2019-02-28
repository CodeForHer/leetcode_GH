#include <iostream>
#include <string>
using namespace std;



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int l=0,r=-1;
        int freq[256] = {0};
        while(l<(int)s.size()){
            if(r+1<(int)s.size()&&freq[s[r+1]]==0){
                ++r;
                freq[s[r]]++;
            }
            else{
                freq[s[l]]--;
                l++;
            }
            if(r-l+1>maxLength)
                maxLength = r-l+1;
        }
        return maxLength;
    }
};
int main()
{
    string s = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    cout<<Solution().lengthOfLongestSubstring(s);
    return 0;
}
