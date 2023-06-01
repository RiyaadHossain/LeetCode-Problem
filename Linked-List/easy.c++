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