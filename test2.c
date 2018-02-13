#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	double Name,Name2;
	FILE *fp1;
	fp1 = fopen ("test.csv", "r");
	rewind(fp1);
	fscanf(fp1,"%lf,%lf",&Name,&Name2);
	printf("%lf",Name);
	fclose(fp1);
	return 0;
	
}
