#include <stdio.h>
#include <unistd.h>
int main ()
{
	write(1, "c", 1);
	printf("1");
	fflush(stdout);
	write(1, "c", 1);
	printf("1");
	fflush(stdout);
}