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

/* 234. Palindrome Linked List */
bool isPalindrome(ListNode *head)
{
    if (head == NULL)
        return false;

    // step 1: Find the middle node
    ListNode *middleNode = findMiddle(head);

    // Step 2: Reverse the secode half
    ListNode *curr = middleNode->next;
    ListNode *prev = NULL;
    while (curr)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Step 3: Match the node element
    ListNode *firstHalf = head;
    ListNode *secondHalf = prev;
    while (secondHalf)
    {
        if (firstHalf->val != secondHalf->val)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

/* GFG: Find length of Loop */
int countNodesinLoop(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = slow->next;
            int ctn = 1;
            while (slow != fast)
            {
                ctn++;
                slow = slow->next;
            }
            return ctn;
        }
    }

    return 0;
}

/* 160. Intersection of Two Linked Lists */

/* Approach 1 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    map<ListNode *, bool> hashTable;

    // Mark on the hashTable
    ListNode *ptr1 = headA;
    while (ptr1)
    {
        hashTable[ptr1] = true;
        ptr1 = ptr1->next;
    }

    // Check intersection
    ListNode *ptr2 = headB;
    while (ptr2)
    {
        if (hashTable[ptr2])
            return ptr2;
        ptr2 = ptr2->next;
    }

    return NULL;
}

/* Approach 2 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{

    // Count length
    int lenA = countLen(headA), lenB = countLen(headB);

    // Level the starting head
    if (lenA > lenB)
    {
        while (lenA > lenB)
        {
            headA = headA->next;
            lenA--;
        }
    }
    else if (lenA < lenB)
    {
        while (lenA < lenB)
        {
            headB = headB->next;
            lenB--;
        }
    }

    // Find the intersection
    while (headA && headB)
    {
        if (headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }

    return nullptr;
}

/* GFG: Add 1 to a number represented as linked list */
Node *addOne(Node *head)
{
    // Reverse List
    Node *prev = NULL;
    Node *curr = head;
    while (curr)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    Node *newHead = prev;

    int carry = 1; // Initialize carry to 1, as we are adding 1
    while (newHead)
    {
        int sum = newHead->data + carry; // Add current digit and carry
        newHead->data = sum % 10;        // Store the least significant digit
        carry = sum / 10;                // Update the carry for the next iteration
        newHead = newHead->next;
    }

    // Reverse List again
    curr = prev;
    prev = NULL;
    while (curr)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // If there is a remaining carry, create a new digit node
    if (carry > 0)
    {
        Node *newDigit = new Node(carry);
        newDigit->next = prev;
        prev = newDigit;
    }

    return prev; // Return the updated linked list
}