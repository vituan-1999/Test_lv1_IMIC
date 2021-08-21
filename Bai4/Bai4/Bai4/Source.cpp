#include"Header.h"

void PT::solve(float a, float b, float c)
{
	float debta = b * b - 4 * a * c;
	if (debta < 0)
	{
		x1 = x2 = 0.0;
	}
	else if (debta == 0)
	{
		x1 = x2 = -b / (2 * a);
	}
	else
	{
		debta = sqrt(debta);
		x1 = (-b + debta) / (2 * a);
		x2 = (-b - debta) / (2 * a);
	}
	printf("\n\tx1 = %.2f \n\tx2 = %.2f\n\n", x1, x2);
}