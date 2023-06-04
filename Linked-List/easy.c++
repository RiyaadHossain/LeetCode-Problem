/* 21. Merge Two Sorted Lists */
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{

    // Edge cases
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    // Find the first small node between two lists
    ListNode *ptr = list1;
    if (list1->val > list2->val)
    {
        ptr = list2;
        list2 = list2->next;
    }
    else
    {
        list1 = list1->next;
    }

    ListNode *curr = ptr;

    // Merge two sorted lists
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            curr->next = list1;
            list1 = list1->next;
        }
        else
        {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }

    // Add remaining nodes
    if (!list1)
        curr->next = list2;
    if (!list2)
        curr->next = list1;

    return ptr;
}

/* 876. Middle of the Linked List */
ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

        slow = slow->next;
    }

    return slow;
}

/* 206. Reverse Linked List */
ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *next = NULL;
    ListNode *curr = head;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

/* 141. Linked List Cycle */
bool hasCycle(ListNode *head)
{

    if (head == NULL)
        return false;

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }

    return false;
}