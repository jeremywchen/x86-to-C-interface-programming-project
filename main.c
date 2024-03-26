#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
	int input;

	printf("Enter Integer: ");
	scanf_s("%d", &input);

	float vec = 1.0;
	float a[64];
	float b[64];
	float sDot = 0.0;

	int i;
	for (i = 0; i < input; i++) {
		a[i] = vec;
		b[i] = vec;
		vec++;
	}

	for (i = 0; i < input; i++) {
		printf("%.2f * %.2f\n", a[i], b[i]);
		float x = a[i] * b[i];
		sDot += x;
		x = 0;
	}

	printf("%.2f", sDot);

	return 0;
}