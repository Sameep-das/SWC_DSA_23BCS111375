int Solution::numSetBits(unsigned int A)
{
    if (A == 0)
        return 0;
    int count = 0;
    while (A)
    {
        A = A & (A - 1);
        count++;
    }
    return count;
}