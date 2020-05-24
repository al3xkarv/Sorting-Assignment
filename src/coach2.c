#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/times.h>  /* times() */
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#define SIZEofBUFF 20
#define SSizeofBUFF 6

int counter=0;
void sig_handler(int signo)
{
  if (signo == SIGUSR2)
    ++counter;
}

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

int main (int argc, char** argv) {


    double t1, t2;
    struct tms tb1, tb2;
    double ticspersec;
    double time1, time2, min, max, avg, tcoach2, buffer;
    ticspersec = (double) sysconf(_SC_CLK_TCK);
    t1 = (double) times(&tb1);



	int pid1, pid2, fd, i;
	long half;;
	FILE* fpw;



	half=atoi(argv[5])/2;

	char half_arg[9];
	sprintf (half_arg, "%ld", half);

	pid1=fork();

	if (pid1 > 0){
		pid2=fork();
	}
	if (pid1==0){
		// printf("This is Child 1 speaking\n");


		if (strcmp(argv[3],"-q")==0){
			char* args[] = {"./quick", argv[2], "0", half_arg, argv[4], "./sorter1", NULL};
			execv(args[0], args);
            exit(1);
		}
        if (strcmp(argv[3],"-h")==0){
			char* args[] = {"./heap", argv[2], "0", half_arg, argv[4], "./sorter1", NULL};
			execv(args[0], args);
            exit(1);
		}
	}



	if (pid2==0 && pid1>0){
		// printf("This is Child 2 speaking\n");

		if (strcmp(argv[3],"-q")==0){
			char* args[] = {"./quick", argv[2], half_arg , argv[5], argv[4], "./sorter2", NULL};
			execv(args[0], args);
            exit(2);
        }
        if (strcmp(argv[3],"-h")==0){
			char* args[] = {"./heap", argv[2], half_arg , argv[5], argv[4], "./sorter2", NULL};
			execv(args[0], args);
            exit(2);
        }

	}


    if (pid1>0 && pid2>0){
        if (signal(SIGUSR2, sig_handler) == SIG_ERR){
            printf("\ncan't catch SIGUSR1\n");
        }
        mkfifo("./sorter1", 0666);

		MyRecord buff[50];
        int j=0;
        int range=half;
        char output[20];
        strcpy(output,"output");
        strncat(output,argv[4],1);
        strncat(output, ".txt", 4);

        fpw=fopen(output, "a");
        fd = open("./sorter1", O_RDONLY);

        while (j<range) {

            read(fd, buff, 50*sizeof(MyRecord));
    		for (i = 0; i < 50 && j<range; i++,j++) {

                // CODE FOR TESTING PURPOSES

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
        read(fd, &time1,sizeof(time1));
        // printf("Sorter1 finished in %lf sec (REAL TIME)\n", time1 );
        unlink("./sorter1");
        close(fd);
    }
	if (pid1>0 && pid2>0){
        // if (signal(SIGUSR2, sig_handler) == SIG_ERR)
			// printf("\ncan't catch SIGUSR1\n");
        mkfifo("./sorter2", 0666);
		MyRecord buff[50];
        int j=0;
        int range = atoi(argv[5]) - half;
        char output[20];
        strcpy(output,"output");
        strncat(output,argv[4],1);
        strncat(output, ".txt", 4);

        fd = open("./sorter2", O_RDONLY);
        while (j < range) {

            read(fd, buff, 50*sizeof(MyRecord));
    		for (i = 0; i < 50 &&  j < range;  i++,j++) {

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
        read(fd, &time2,sizeof(time2));
        // printf("Sorter2 finished in %lf sec (REAL TIME)\n", time2 );
        unlink("./sorter2");
        close(fd);
        fclose(fpw);

        t2 = (double) times(&tb2);
        min=time1;
        max=time2;
        if (time2 < time1) {
            min=time2;
            max=time1;
            // printf("For Coach2:\nMin time was of Sorter2 at %lf sec (REAL TIME)\nMax Time was of Sorter1 at %lf sec (REAL TIME)\n Average time was %lf sec (REAL TIME)\n", time2, time1, (time2+time1)/2.0 );
        }
        // else{
            // printf("For Coach2:\nMin time was of Sorter1 at %lf sec (REAL TIME)\nMax Time was of Sorter2 at %lf sec (REAL TIME)\nAverage time was %lf sec (REAL TIME)\n", time1, time2, (time2+time1)/2.0 );

        // }
        avg=(time2+time1)/2.0;
        tcoach2 = (t2 - t1) / ticspersec;
        fd = open("./forcoach2", O_WRONLY);

        buffer=min;
        write(fd, &buffer,sizeof(buffer));
        buffer=max;
        write(fd, &buffer,sizeof(buffer));
        buffer=avg;
        write(fd, &buffer,sizeof(buffer));
        buffer=tcoach2;
        write(fd, &buffer, sizeof(buffer));

        write(fd, &counter,sizeof(counter));

        // write(fd, &min,sizeof(min));
        // write(fd, &max,sizeof(max));
        // write(fd, &avg,sizeof(avg));
        // write(fd, &counter,sizeof(counter));
        // write(fd, &tcoach2, sizeof(tcoach2));
        unlink("./forcoach2");



    }
    close(fd);
    printf("coach2 done\n");
    // printf("Run time for coach2 was %lf sec (REAL time) .\nSignal SIGUSR2 received %d times.\n\n", tcoach2);
    free(fpw);
    exit(9);
    return 0;


}
