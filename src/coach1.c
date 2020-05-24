#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/times.h>
// #include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#define SIZEofBUFF 20
#define SSizeofBUFF 6


typedef struct{
	long  	custid;
	char 	FirstName[SIZEofBUFF];
	char 	LastName[SIZEofBUFF];
	char	Street[SIZEofBUFF];
	int 	HouseID;
	char	City[SIZEofBUFF];
	char	postcode[SSizeofBUFF];
	float  	amount;
} MyRecord;

int counter=0;
void sig_handler(int signo)
{
  if (signo == SIGUSR2)
    ++counter;
}

int main (int argc, char** argv) {

	double t1, t2;
	struct tms tb1, tb2;
	double ticspersec;
	double time0, tcoach1, buffer;
	ticspersec = (double) sysconf(_SC_CLK_TCK);
	t1 = (double) times(&tb1);

	int pid1;
	int fd, i;
    FILE* fpw;
	MyRecord buff[50];
	int j=0;
	int range=atoi(argv[5]);
	char output[20];


    pid1=fork();
    if (!pid1){
		// printf("This is Child speaking\n");

		if (strcmp(argv[3],"-q")==0){
			char* args[] = {"./quick", argv[2], "0", argv[5],argv[4],"./sorter0", NULL};
			execv(args[0], args);
		}
		if (strcmp(argv[3],"-h")==0){
			char* args[] = {"./heap", argv[2], "0", argv[5],argv[4],"./sorter0", NULL};
			execv(args[0], args);
		}


    }

	if (pid1>0){

		if (signal(SIGUSR2, sig_handler) == SIG_ERR){
		        printf("\ncan't catch SIGUSR1\n");
		}
        mkfifo("./sorter0", 0666);

	    strcpy(output,"output");
        strncat(output,argv[4],1);
        strncat(output, ".txt", 4);

		fpw=fopen(output, "w");
		fd = open("./sorter0", O_RDONLY);

        while (j<range) {

            read(fd, buff, 50*sizeof(MyRecord));
    		for (i = 0; i < 50 && j<range; i++,j++) {

                //CODE FOR TESTING PURPOSES

                // printf(" i is %d \n",i);
        		// printf("%ld %s %s  %s %d %s %s %-9.2f\n",buff[i].custid,
        		// buff[i].LastName, buff[i].FirstName,
        		// buff[i].Street, buff[i].HouseID, buff[i].City,
                // buff[i].postcode,
        		// buff[i].amount);
                fprintf(fpw,"%ld %s %s  %s %d %s %s %-9.2f\n",buff[i].custid,
        		buff[i].LastName, buff[i].FirstName,
        		buff[i].Street, buff[i].HouseID, buff[i].City,
                buff[i].postcode,
    		    buff[i].amount);
		    }

        }
		read(fd, &time0,sizeof(time0));

		// printf("Sorter0 finished in %lf sec (REAL TIME)\n", time0);
		unlink("./sorter0");
		close(fd);
		fclose(fpw);



		// printf("For Coach1:\nMin time was of Sorter0 at %lf sec (REAL TIME)\nMax Time was of Sorter0 at %lf sec (REAL TIME)\nAverage time was %lf sec (REAL TIME)\n", time0, time0, time0 );
		t2 = (double) times(&tb2);
		tcoach1=(t2 - t1) / ticspersec;
		fd = open("./forcoach1", O_WRONLY);
		buffer=time0;
		write(fd, &buffer,sizeof(buffer));
		buffer=tcoach1;
		write(fd, &buffer, sizeof(buffer));

		write(fd, &counter,sizeof(counter));

		unlink("./forcoach1");
		close(fd);
		// printf("Run time for coach1 was %lf sec (REAL time).\nSignal SIGUSR2 received %d times.\n\n",tcoach1, counter);

        }
		printf("coach1 done\n");
		free(fpw);
		exit(9);
		return 0;

}
