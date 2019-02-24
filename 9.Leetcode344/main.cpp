#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0,j=s.size()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    void printString(vector<char> &s){
        for(int i=0;i<s.size();++i){
            cout<<s[i]<<" ";
        }
    }
};

int main()
{
    vector<char> s = {'h','e','l','l','o'};
    Solution().reverseString(s);
    Solution().printString(s);
    return 0;
}
