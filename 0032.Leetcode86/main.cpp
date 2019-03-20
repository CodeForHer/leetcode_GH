#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

ListNode* Make_list(vector<int>& vec){
    int n = vec.size();
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    for(int i=0;i<n;i++){
        cur->next = new ListNode(vec[i]);
        cur = cur->next;
    }
    cur = dummy->next;
    delete dummy;
    return cur;
}

void Show_list(ListNode* head){
    ListNode* point = head;
    while(point!=NULL){
        cout<<point->val<<"->";
        point=point->next;
    }
    cout<<"NULL";
}

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

                less_x = less_x->next;
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

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
