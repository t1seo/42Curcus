#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

void *routine(void *thread_number)
{
	for (int i = 0; i < 5; i++)
	{
		usleep(1000 * 1000);
		i++;
		printf("Thread[%d]: Wating %d Seconds.\n", *(int *)thread_number, i);
	}
	printf("%d Thread end\n", *(int *)thread_number);
	return (thread_number);
}

int main(void)
{
	pthread_t thread1;
	pthread_t thread2;
	int number1;
	int number2;
	void *ret;

	number1 = 1;
	number2 = 2;

	if (pthread_create(&thread1, NULL, routine, (void *)&number1))
	{
		fprintf(stderr, "Thread(1): pthread_create error: %s", strerror(errno));
		return (errno);
	}
	if (pthread_create(&thread2, NULL, routine, (void *)&number2))
	{
		fprintf(stderr, "Thread(2): pthread_create error: %s", strerror(errno));
		return (errno);
	}

	printf("detach thread2\n");
	pthread_detach(thread2); // main thread에서 join 하지 않아도 알아서 진행하고 종료된다.
	printf("waiting for a thread\n");
	pthread_join(thread1, &ret); // thread1을 대기한다. routine의 값을 ret에 넣어준다
	printf("main end: %d\n", *(int *)ret);
	return 0;
}
