#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	char command[1000];
	int i = 2;
	strcpy(command, argv[1]);
	while(i < argc){
		strcat(command, " ");
		strcat(command, argv[i]);
		
		i++;
	}
	execlp("/bin/sh", "shell","-c", command, (char *)NULL);
	return 0;
}
