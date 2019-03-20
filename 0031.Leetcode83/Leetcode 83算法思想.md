# Leetcode 83(Remove Duplicates From Sorted List)

## 题目链接
[Remove Duplicates From Sorted List](https://leetcode-cn.com/classic/problems/remove-duplicates-from-sorted-list/description/)

## 算法思想

### 方法1：
*Time:O(n),Space:O(1)*

- 因为链表是有序排列的，因此只需比较当前节点和下一个节点的value值，如果相同，则当前节点的next指针指向下一个节点的next，否则另当前节点为下一个节点

### 方法1代码：
```
	
	class Solution {
	public:
	    ListNode* deleteDuplicates(ListNode* head) {
	        ListNode* cur = head;
	        while(cur!=NULL){
	            if(cur->next==NULL)
	                break;
	            ListNode* next = cur->next;
	            if(cur->val==next->val){
	                cur->next = next->next;
	            }
	            else{
	                cur = cur->next;
	            }
	        }
	        return head;
	    }
	};



```


