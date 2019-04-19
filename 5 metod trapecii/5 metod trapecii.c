#include<math.h>
#include<stdio.h>
#include<stdlib.h>

void f_MyEnd(void);
double *function_values(int number_of_breaks, double lower_limit, double gap_lenght) {
	double *values = (double *)(malloc(sizeof(double)*(number_of_breaks + 1)));

	double Xi = lower_limit;
	for (int i = 0; i <= number_of_breaks; i++) {

		values[i] = 3 * Xi - cos(Xi) - 1;
		Xi += gap_lenght;
	}
	return values;
}

double integral_calculations(double lower_limit, double upper_limit, int number_of_breaks) {

	double gap_lenght = ((upper_limit)-(lower_limit)) / (double)number_of_breaks;
	double *values = function_values(number_of_breaks, lower_limit, gap_lenght);

	double summ = 0;
	for (int i = 0; i < number_of_breaks; i++)
		summ += ((values[i] + values[i + 1]) / 2)*gap_lenght;
	free(values);
	return summ;
}


int main(void) {
	char Pwork = 0; char MyChar = 0;
	Pwork = atexit(f_MyEnd);
	if (Pwork != 0)
	{
		puts("error f_MyEnd ");
	}
	while (1) {
		double lower_limit = 0, upper_limit = 0;
		int number_of_breaks = 0;

	data_collection:
		printf("Hi I am calculating the integral functions f(x) = 3*x - cos(x) - 1\n");
		printf("Enter the limits of integration:\n");

		printf("From: ");
		scanf_s("%lf", &lower_limit);

		printf("up: ");
		scanf_s("%lf", &upper_limit);

		printf("Enter the number of breaks:");
		scanf_s("%d", &number_of_breaks);
		if (((number_of_breaks == 0) || (upper_limit - lower_limit) == 0)) goto data_collection;

		printf("%lf", integral_calculations(lower_limit, upper_limit, number_of_breaks));
		printf("\nWould you like to repeat the calculation? \nEnter Y or N.\n");
		int triger = 1;
		do {
			MyChar = getchar();
			MyChar = getchar();
			int triger = 1;
			if (MyChar == 'N')
			{
				exit(EXIT_SUCCESS);
			}
			if (MyChar != 'Y')
			{
				printf("unknown command, re-enter\n");
				triger = 1;
			}
			else break;
		} while (triger > 0);
	}
}

void f_MyEnd(void) {
	puts("end of work");
}