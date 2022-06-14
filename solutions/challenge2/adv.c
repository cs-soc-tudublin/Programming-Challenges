/* CS++
 * PROGRAMMING CHALLENGE 2: ADVANCED
 * GIVEN AN ARRAY OF INTEGERS, RETURN AN ARRAY WHERE THE PRODUCT OF THE FIRST TWO ELEMENTS IS THE THIRD
 *
 * NOTE: IF THERE ARE MORE THAN ONE SETS OF NUMBERS WHICH SATISFY THIS CONDITION, RETURN THE FIRST
 *
 * EXAMPLE: 
 *	
 * INPUT = [4,2,9,7,54,2,9,18]
 * RESULT = [9,7,54]
 *
 * SUBMITTED BY MATTHEW ENNIS
 *
 */

int *prodArray(int input[],int len)
{
	int i;
	for (i=2; i<len; i++) if (input[i-2] * input[i-1] == input[i]) break;
	int *output = malloc(3);
	output[0] = input[i-2], output[1] = input[i-1], output[2] = input[i];
	return output;
}
