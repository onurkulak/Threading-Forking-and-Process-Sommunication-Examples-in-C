#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <mqueue.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>


int main(int argc, char const *argv[]){
	mqd_t mq;

    /* open the mail queue */
    mq = mq_open("/cs342", O_RDONLY);
    if(mq==-1)
    	fprintf(stderr, "%s:%d:%s ", __func__, __LINE__, strerror(errno)); 
    char buffer[6];
    int finished = 0;
	do{
    ssize_t bytes_read;
    bytes_read = mq_receive(mq, buffer, 7, NULL);
		if(bytes_read >= 0){
			buffer[bytes_read] = '\0';
    printf("%s\n", buffer);
    if (atoi(buffer)==10000)
    	finished++;
	}
	
	}while(finished<3);
	mq_close(mq);
	mq_unlink("/cs342");
}
