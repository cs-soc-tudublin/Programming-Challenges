/* CS++
 * PROGRAMMING CHALLENGE 2: INTERMEDIATE
 * GIVEN AN ARRAY OF INTEGERS, RETURN THE LONGEST SEQUENCE OF CONSECUTIVE NUMBERS
 *
 * EXAMPLE:
 *
 * INPUT = [1,2,7,8,9,-1,0,2]
 * RESULT = [7,8,9]
 *
 * SUBMITTED BY ADRIAN CAPACITE
 *
 */

int *longestSeq(int *, int);

// Returns an array of integers that are the longest consecutive sequence
// If there is two of the same length, it finds the first one
// params: input - array of integers
//         len - size of array
// returns: pointer to dynamic array of integers - size is same as input array
int *longestSeq(int input[],int len) {
    // Initialize result array
    int *result = calloc(len, sizeof(int));

    // Initialize start and end indexes
    int start = 0;
    int length = 0;
    int longestStart = 0;
    int longestLength = 0;

    // Loop through each number in array to find longest consecutive numbers
    for (int i = 0; i < len - 1; i++)
    {
        // If current number is consecutive to previous number, increment length
        // Else reset start and length to current index
        if (input[i] != input[i+1] - 1)
        {
            start = i;
            length = 0;
        }
        length++;

        // If length is greater than longest length, set longest start and length to current
        if (length > longestLength)
        {
            longestStart = start;
            longestLength = length;
        }
    }

    // Copy longest consecutive sequence into result array
    for (int i = 0; i < longestLength; i++)
    {
        result[i] = input[i + longestStart];
    }

    return result;
}
