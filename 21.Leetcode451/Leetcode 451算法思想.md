# Leetcode 451(Sort Characters By Frequency）

## 题目链接
[Sort Characters By Frequency](https://leetcode-cn.com/classic/problems/sort-characters-by-frequency/description/)

## 算法思想

### 方法1：

- 这道题目算法思想较为简单，设置哈希表，首先对字符串统计字符频率，之后按照字符串频率排序输出即可

### 方法1代码：
```

	class Solution{
	public:
		string frequencySort(string s) {
	        unordered_map<char,int> freq;
	        string res;
	        for(int i=0;i<s.size();++i){
	            freq[s[i]]++;
	        }
	        vector<pair<char,int>> vec(freq.begin(),freq.end());
	        sort(vec.begin(),vec.end(),cmp);
	        for(int i=0;i<vec.size();++i){
	            pair<char,int> tmp = vec[i];
	            while(tmp.second!=0){
	                res.push_back(tmp.first);
	                --tmp.second;
	            }
	        }
	        	return res;
	        }

	
		static bool cmp(pair<char, int>& p1,pair<char, int>& p2) {
	            return p1.second > p2.second;
	        }
	 }	

```
###需要注意的地方

- 这里的sort()方法需要用到成员函数cmp，需要注意的是，cmp函数需要写为静态static，即表示为类的方法而非成员的方法。原因是因为在类的实例没有初始化时，其成员函数没有地址，必须把比较函数声明为静态，或者写在类外面。当然，也可以写成lamda函数：
- 参考 [c++使用静态成员函数](https://blog.csdn.net/zhangxiao93/article/details/51265348)


```
	
	sort(vec.begin(),vec.end(),[](pair<char, int>& a,pair<char, int>& b) { return a.second > b.second; });

```