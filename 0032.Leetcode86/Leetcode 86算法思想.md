# Leetcode 86(Partition List)

## 题目链接
[Partition List](https://leetcode-cn.com/classic/problems/partition-list/description/)

## 算法思想

### 方法1：
*Time:O(n),Space:O(1)*

- 基本思想是：假设链表的开头部分都是小于x的节点，则找到这部分的最后一个节点，同时保存这个节点的前后指针。之后向右边寻找第一个小于x的节点，将这个节点加入开头小于x的部分，并放在最后的位置。之后，利用前面保存的指针将整个链表连接起来。

### 方法1代码：
```
	
	class Solution {
	public:
	    ListNode* partition(ListNode* head, int x) {
	        ListNode* dummy = new ListNode(INT_MIN);
	        dummy->next = head;
	        ListNode* pre = NULL;
	        ListNode* cur = dummy;
	        while((cur!=NULL)&&(cur->val<x)){
	            pre = cur;
	            cur =cur->next;
	        }
	
	        ListNode* less_x = pre;
	        ListNode* less_x_next = cur;
	
	        ListNode* pre_aim = NULL;
	        ListNode* aim = NULL;
	        ListNode* next_aim = NULL;
	
	        while(cur!=NULL){
	            if(cur->val<x){
	                aim = cur;
	                pre_aim = pre;
	                next_aim = cur->next;
	
	                less_x->next = aim;
	                aim->next = less_x_next;
	                pre_aim->next = next_aim;
	                
	                less_x = less_x->next;			//要对小于x部分的最后一个节点更新
	                less_x_next = less_x->next;
	
	                pre = pre_aim;
	                cur = next_aim;
	            }
	            else
	            {
	                pre = cur;
	                cur = cur->next;
	            }
	        }
	        ListNode* res = dummy->next;
	        delete dummy;
	        return res;
	    }
	};



```


