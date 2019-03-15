#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for(int i=0;i<points.size();++i){
            unordered_map<int,int> distanceMap;
            for(int j=0;j<points.size();++j){
                if(i!=j){
                    int d = CountDistance(points[i],points[j]);
                    distanceMap[d]+=1;
                }
            }
            for(unordered_map<int,int>::iterator iter = distanceMap.begin();iter!=distanceMap.end();++iter){
                if(iter->second>=2){
                    int number = iter->second;
                    res+=number*(number-1);
                }
            }
        }
        return res;
    }

    int CountDistance(pair<int,int>& point1,pair<int,int>& point2){
        int dleft = (point1.first-point2.first)*(point1.first-point2.first);
        int dright = (point1.first-point2.first)*(point1.first-point2.first);
        return dleft+dright;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
