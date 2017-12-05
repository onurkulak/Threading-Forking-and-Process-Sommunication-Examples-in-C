#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <mqueue.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char const *argv[])
{

	mqd_t mq;
    struct mq_attr attr;

    /* initialize the queue attributes */
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 6;
    attr.mq_curmsgs = 0;


    /* open the mail queue */
    mq = mq_open("/cs342", O_CREAT | O_WRONLY, 0644, &attr);
    if(mq==-1) fprintf(stderr, "%s:%d:%s ", __func__, __LINE__, strerror(errno)); 

	pid_t pid;
	pid = fork();
	if(pid>0)
		pid *= fork();
	if(pid>0)
		pid *= fork();

	if(pid == 0){
		int i = 1;
		while(i<10001){
			char* buffer=(char *)malloc(6*sizeof(char));
			sprintf(buffer, "%d", i);
			mq_send(mq, buffer, strlen(buffer) , 0);
			i++;
		}
		mq_close(mq);
	}
	else{
		mq_close(mq);
		execlp("./C", "consumer",(char *)NULL);
	}

	return 0;
}
