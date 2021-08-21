#include"Header.h"

int main()
{
	PT pt_bac2;
	float a = 0;
	float b = 0;
	float c = 0;
	printf("\n\tA*X^2 + B*X + C = 0; \n\tA B C: ");
	scanf("%f%f%f", &a, &b, &c);
	pt_bac2.solve(a, b, c);
	return 0;
}