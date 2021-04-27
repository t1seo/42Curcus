#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

pthread_mutex_t mutex;

void *routine(void *thread_number)
{
	pthread_mutex_lock(&mutex);
	printf("Thread[%d]: mutex lock\n", *(int *)thread_number);

	for (int i = 0; i < 5; i++)
	{
		usleep(1000 * 1000);
		printf("Thread[%d]: Wating %d Seconds\n", *(int *)thread_number, i);
	}
	printf("Thread end\n");
	pthread_mutex_unlock(&mutex);
	printf("Thread[%d]: mutex unlock\n", *(int *)thread_number);
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
	printf("Pthread create\n");
	pthread_create(&thread1, NULL, routine, (void *)&number1);
	pthread_create(&thread2, NULL, routine, (void *)&number2);

	printf("Mutex init\n");
	pthread_mutex_init(&mutex, NULL);

	printf("Wating for threads\n");
	pthread_join(thread1, &ret); // thread1을 대기한다. routine의 값을 ret에 넣어준다.
	pthread_join(thread2, &ret); // thread1을 대기한다. routine의 값을 ret에 넣어준다.

	printf("Mutex destroy\n");
	pthread_mutex_destroy(&mutex);

	printf("main end\n");
	return 0;
}
