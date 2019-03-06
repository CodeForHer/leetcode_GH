#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> freq;
        for(int i=0;i<s.size();++i){
            freq[s[i]]++;
        }
        for(int i=0;i<t.size();++i){
            if(freq[t[i]]==0){
                return false;
            }
            freq[t[i]]--;
        }
        for(unordered_map<char,int>::iterator iter=freq.begin();iter!=freq.end();++iter){
            if(iter->second!=0){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string  s = "ab", t = "a";
    cout<<Solution().isAnagram(s,t);
    return 0;
}
