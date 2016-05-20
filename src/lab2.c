#include <stdio.h>
#include <math.h>
#include "qwrt.h"

int main()
{
	int roots;
	double a, b, c, d, x1, x2;
	printf("Enter a, b, c: \n");
	scanf("%lf %lf %lf", &a, &b, &c);
	roots = qwrt(a, b, c, &d, &x1, &x2);
	if (roots == -1)
	{
		printf("Coefficient A should be more than zero.\n");
		return 0;
	}
	
	printf("\nDiscriminant: %lf\n", d);
	
	if (roots == 0)
		printf("No roots\n");
	else if (roots == 1)
		printf("Root: %lf\n", x1);
	else
		printf("\nRoots: %lf %lf\n", x1, x2);
	return 0;
}
