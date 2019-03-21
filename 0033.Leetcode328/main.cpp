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

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
