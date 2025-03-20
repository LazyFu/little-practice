#include<iostream>
#include<stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

ListNode* removeElement(ListNode *head,int val)
{
    ListNode *dummy=new ListNode(0);
    dummy->next=head;
    ListNode *current=dummy;
    while(current->next!=NULL)
    {
        if(current->next->val==val)
        {
            current->next=current->next->next;
        }
        else
        {
            current=current->next;
        }
    }
    return dummy->next;
}

ListNode* addLists2(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;
    while(l1 != nullptr) {
        s1.push(l1->val);
        l1 = l1->next;
    }
    while(l2 != nullptr) {
        s2.push(l2->val);
        l2 = l2->next;
    }
    
    int carry = 0;
    ListNode* head = nullptr;
    while(!s1.empty() || !s2.empty() || carry) {
        int sum = carry;
        if(!s1.empty()){
            sum += s1.top();
            s1.pop();
        }
        if(!s2.empty()){
            sum += s2.top();
            s2.pop();
        }
        carry = sum / 10;
        ListNode* node = new ListNode(sum % 10);
        node->next = head;
        head = node;
    }
    return head;
}

string tree2str(TreeNode * t) 
{
    if(t==NULL)
    {
        return "";
    }
    string result=to_string(t->val);
    if(t->left!=NULL)
    {
        result+="("+tree2str(t->left)+")";
    }
    if(t->right!=NULL)
    {
        if(t->left==NULL)
        {
            result+="()";
        }
        result+="("+tree2str(t->right)+")";
    }
    return result;
}

int main()
{
    int val;
    cin>>val;

}