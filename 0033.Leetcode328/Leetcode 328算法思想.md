# Leetcode 328(Odd Even Linked List)

## 题目链接
[Odd Even Linked List](https://leetcode-cn.com/classic/problems/odd-even-linked-list/description/)

## 算法思想

### 方法1：
*Time:O(n),Space:O(1)*

- 基本思想是：初始化两个指针，奇指针和偶指针，分别指向第一个和第二个节点，之后修改其后即指针即可。

### 方法1代码：
```
	
	class Solution {
	public:
	    ListNode* oddEvenList(ListNode* head) {
	        if(head==NULL||head->next==NULL){
	            return head;
	        }
	        ListNode* odd_cur = head;
	        ListNode* even_cur = head->next;
	        ListNode* odd_first = head;
	        ListNode* even_first = head->next;
	        while((odd_cur->next!=NULL)&&(even_cur->next!=NULL)){
	            if(even_cur->next!=NULL){
	                odd_cur->next = even_cur->next;
	                odd_cur = odd_cur->next;
	            }
	            if(odd_cur->next!=NULL){
	                even_cur->next = odd_cur->next;
	                even_cur = even_cur->next;
	            }
	        }
	        if(odd_cur->next==NULL){
	            odd_cur->next = even_first;
	            even_cur->next = NULL;
	        }
	        else{
	            odd_cur->next = even_first;
	        }
	        return odd_first;
	    }
	};


```


