#include <sys/time.h> // gettimeofday, struct time val
#include <unistd.h> // sleep
#include <stdio.h>
#include <string.h>

int main(void)
{
	struct timeval bgn, end;
	double one_sec = 1000000.0;

	double diff;
	gettimeofday(&bgn, NULL);
	sleep(1);
	gettimeofday(&end, NULL);
	diff = (end.tv_sec - bgn.tv_sec) + ((end.tv_usec - bgn.tv_usec) / one_sec);

	printf("%f\n", diff);

	return 0;
}
