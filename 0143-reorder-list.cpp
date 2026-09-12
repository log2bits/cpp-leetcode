class Solution {
public:
  void reorderList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* second = reverse(slow->next);
    slow->next = nullptr;

    ListNode* first = head;
    while (second) {
      ListNode* next_first = first->next;
      ListNode* next_second = second->next;
      first->next = second;
      second->next = next_first;
      first = next_first;
      second = next_second;
    }
  }

private:
  ListNode* reverse(ListNode* node) {
    ListNode* prev = nullptr;
    while (node) {
      ListNode* next = node->next;
      node->next = prev;
      prev = node;
      node = next;
    }
    return prev;
  }
};
