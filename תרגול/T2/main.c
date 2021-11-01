#include <stdio.h>
#include "mult3.h"
#include "div2.h"

int main() {
	double a;
	scanf("%lf", &a);
	printf("%f", mult3(div2(a)));
	return 0;
}


