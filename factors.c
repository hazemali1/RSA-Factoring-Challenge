#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * main - Main
 * @args: PArameter
 * @argv: Parameter2
 * Return: Always 0
*/
int main(int args, char *argv[])
{
	int w = 0, r = 0, t = 2, x;
	long int n;
	char *buff[1024];
	size_t d;
	FILE *s;

	s = fopen(argv[1], "r");
	if (s == NULL)
		return (0);
	while (getline(&buff[w], &d, s) != -1)
	{
		w++;
	}
	while (w > r)
	{
		n = atoi(buff[r]);
		while (t != 0)
		{
			x = n % t;
			if (x == 0)
			{
				printf("%ld=%ld*%d\n", n, n / t, t);
				t = -1;
			}
			t++;
		}
		t = 2;
		r++;
	}
	fclose(s);
	return (0);
}
