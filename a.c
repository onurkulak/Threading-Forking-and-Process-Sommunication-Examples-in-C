#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	char name = 'a';
	pid = fork();

	if(pid == 0)
		name = 'b';
	else{
		pid = fork();
		if(pid == 0){
			name = 'c';
			pid = fork();
			if(pid == 0)
				name = 'e';
			else{
				pid = fork();
				if(pid == 0)
					name = 'd';
			}
		}
		else{
			pid = fork();
			if(pid == 0){
				name = 'f';
				pid = fork();
					if(pid == 0)
						name = 'g';
			}
		}
	}
	int i = 0;
	while(i < 100){
		printf("name: %c  parentID: %d processID: %d \n", name, getppid(), getpid());
		i++;
	}
	sleep(50);
	if(pid!=0)
		wait(NULL);

	return 0;
}
