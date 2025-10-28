#include<iostream>
using namespace std;


// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* prev1 = NULL;
    ListNode* curr1 = list1;
    ListNode* prev2 = NULL;
    ListNode* curr2 = list2;
    ListNode* head = NULL;
    ListNode* prev = NULL;
    while(curr1 != NULL && curr2 != NULL){
        ListNode* curr;
        if(curr1->val <= curr2->val){
            curr = curr1;
            curr1 = curr1->next;
        }else{
            curr = curr2;
            curr2 = curr2->next;
        }
        if(prev == NULL){
            head = curr;
        }else{
            prev->next = curr;
        }
        prev = curr;
    }
    if(curr1 != NULL){
        if(prev == NULL){
            head = curr1;
        }else{
            prev->next = curr1;   
        }
    }
    if(curr2 != NULL){
        if(prev == NULL){
            head = curr2;
        }else{
            prev->next = curr2;   
        }
    }
    return head;
}