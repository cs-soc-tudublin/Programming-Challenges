/* CS++
 * PROGRAMMING CHALLENGE 2: BEGINNER
 *
 * GIVEN AN ARRAY OF INTEGERS, RETURN AN ARRAY WHICH CONTAINS THE HIGHEST AND LOWEST VALUE
 *
 * EXAMPLE:
 * INPUT = [1,3,6,93,1,1,-2,50]
 * RESULT = [-2,93]
 *
 * SUBMITTED BY ADRIAN CAPACITE
 *
 */

// returns pointer to array of two integers
// first integer is lowest, second is highest
// params: input - array of integers
//         len - size of array
// returns: pointer to array of two integers
int *highLow(int input[],int len)
{
    static int result[2];
    result[0] = input[0];
    result[1] = input[0];

    // Loop through array and put highest and lowest values in result
    for (int i = 0; i < len; i++)
    {
        if (result[0] < input[i])
        {
            result[0] = input[i];
        }
        if (result[1] > input[i])
        {
            result[1] = input[i];
        }
    }

    return result;
}
