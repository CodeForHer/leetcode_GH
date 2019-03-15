# Leetcode 447(number of boomerangs)

## 题目链接
[number of boomerangs](https://leetcode-cn.com/classic/problems/number-of-boomerangs/description/)

## 算法思想

### 方法1：
*Time:O(n^2),Space:O(n)*

- 对于每一个点，计算该点与其他点的距离，同时为这个点设置一个哈希表，键值为距离值，value值为频数，得到距离该点的距离-频数对应表。遍历这个哈希表，对于每个表中每个健值，结果中应该加上(频数)x(频数-1)。比如对于一个点point[i]，计算得到3-2，4-3这个表，表示与点point[i]距离为3的点有2个，距离为4的点有3个，则结果应该加上(2)x(2-1)与(3)x(3-1)。

### 方法1代码：
```
	
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
	        int dright = (point1.second-point2.second)*(point1.second-point2.second);
	        return dleft+dright;
    }

	


```


