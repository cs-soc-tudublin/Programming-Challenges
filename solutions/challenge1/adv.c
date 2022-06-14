/* 
 * Advanced challenge
 * Find the nth perfect number
 *
 * SOLUTION SUBMITTED BY MATTHEW ENNIS
 *
 */

int perfect(int n)
{
	int p = 2;
	while (n>0)
	{
		p = p << 1;
		int prime = 1;
		for (int i=2; i < p/2; i++) if ((p-1)%i == 0) prime = 0;
		if (prime) n -= 1;
	}
	return (p >> 1) * (p-1);
}
