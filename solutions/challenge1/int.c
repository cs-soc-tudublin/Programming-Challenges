/*  Intermediate Challenge
 *  Using recursion, find the nth fibonnaci number
 *
 *	SOLUTION SUBMITTED BY ADRIAN CAPACITE
 */
int recurFib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return recurFib(n - 1) + recurFib(n - 2);
    }
}
