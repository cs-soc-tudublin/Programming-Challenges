/*	PROGRAMMING CHALLENGE 3
 *	
 *	Write a parser which takes a given set of instructions and prints an output based on said instructions.
 *
 *	parser begins with a value at zero
 *	'i' = increments the value
 *	'd' = decrements the value
 *	's' = squares the value
 *	'o' = outputs the value and resets it to zero
 *	
 *	Instructions are stored as strings and passed into the parser
 */

void parser(char *input)
{	
	int val = 0;
	do
	{
		switch(*input)
		{
			case 'i':
				val++;
				break;
			case 'd':
				val--;
				break;
			case 's':
				val = val * val;
				break;
			case 'o':
				printf("%d\n",val);
				val = 0;
				break;
			default:
				break;
		}
	}while(*++input);
}
