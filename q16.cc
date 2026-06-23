ListNode *Solution::addTwoNumbers(ListNode *A, ListNode *B)
{
    if (A == NULL)
        return B;
    if (B == NULL)
        return A;
    int sum = 0;
    int carry = 0;
    ListNode *prev = new ListNode(-1);
    ListNode *ans = prev;
    while (A != NULL || B != NULL || carry == 1)
    {
        sum = 0;
        if (A)
        {
            sum += A->val;
            A = A->next;
        }
        if (B)
        {
            sum += B->val;
            B = B->next;
        }
        sum += carry;
        carry = 0;
        prev->next = new ListNode(sum % 10);
        prev = prev->next;
        carry = sum / 10;
    }
    return ans->next;
}