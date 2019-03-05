#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return isIsomorphic_sub(s,t)&&isIsomorphic_sub(t,s);
    }
    bool isIsomorphic_sub(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char,char> map_char;
        for(int i=0;i<s.size();++i){
            if(map_char[s[i]]=='\0'){
                map_char[s[i]]=t[i];
            }
            else{
                if(map_char[s[i]]!=t[i]){
                    return false;
                }
            }
        }
        return true;
    }

};

int main()
{
    string s = "aa", t = "ab";
    cout<<Solution().isIsomorphic(s,t);
    return 0;
}
