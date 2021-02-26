#include <stdio.h>
#include <unistd.h> // sleep
#include <signal.h>


void	(*old_fun)(int);

void	sigint_handler(int signo)
{
	printf("You Pressed Ctrl-C\n");
	printf("If you press again, it will be terminated.\n");
	signal(SIGINT, old_fun); // or signal(SIGINT, SIG_DFL);
}

int		main(void)
{
	old_fun = signal(SIGINT, sigint_handler);
	while (1)
	{
		printf("Hello, world!\n");
		sleep(1);
	}
}
