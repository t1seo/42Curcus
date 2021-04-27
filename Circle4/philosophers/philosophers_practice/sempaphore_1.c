#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

sem_t *sem;

void *routine(void *num)
{
	sem_wait(sem);
	for (int i = 0; i < 3; ++i)
	{
		printf("%d: use semaphore\n", *(int *)num);
		usleep(1000 * 1000);
	}
	sem_post(sem);
	return (num);
}

int main(void)
{
	int ret;
	pthread_t tid[4];
	int num[4];

	sem = sem_open("test_sem", O_CREAT | O_EXCL, 0644, 3);
	if (sem == SEM_FAILED)
	{
		fprintf(stderr, "sem errro\n");
		return (-1);
	}

	for (int i = 0; i < 4; ++i)
	{
		num[i] = i;
		pthread_create(&tid[i], NULL, routine, (void *)&num[i]);
	}
	for (int i = 0; i < 4; ++i)
		pthread_join(tid[i], NULL);
	ret = sem_close(sem);
	printf("sem_close: %d\n", ret);
	ret = sem_unlink("test_sem");
	printf("sem_unlink: %d\n", ret);
	return 0;
}
