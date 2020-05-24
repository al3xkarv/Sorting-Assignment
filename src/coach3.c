#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/times.h> 		/*times*/
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
    double time3, time4, time5, time6;
    double min, max, avg, tcoach3;
    double buffer[1];
    ticspersec = (double) sysconf(_SC_CLK_TCK);
    t1 = (double) times(&tb1);


	int pid1, pid2, pid3, pid4, fd, i;
	long  eighth, quarter, two_quarters;
	FILE* fpw;


	eighth = atoi(argv[5])/8;
    quarter=2*eighth;
    two_quarters=atoi(argv[5])-2*eighth-quarter;


	char eighth_arg[9];

    char quarter_arg[9];
    char two_quarters_arg[9];


    sprintf (eighth_arg, "%ld", eighth);
    sprintf (quarter_arg, "%ld", quarter);
    sprintf (two_quarters_arg, "%ld", two_quarters);

    // printf ("%s %s %s \n", eighth_arg, quarter_arg, two_quarters_arg );
	pid1=fork();

	if (pid1 > 0){
		pid2=fork();
	}

    if (pid1 > 0 && pid2 > 0){
		pid3=fork();
	}

    if (pid1 > 0 && pid2 >0 && pid3 > 0){
		pid4=fork();
	}


	if (pid1==0){
		// printf("This is Child 1 speaking\n");


		if (strcmp(argv[3],"-q")==0){
			char* args[] = {"./quick", argv[2], "0", eighth_arg, argv[4], "./sorter3", NULL};
			execv(args[0], args);
            exit(1);
		}
        if (strcmp(argv[3],"-h")==0){
			char* args[] = {"./heap", argv[2], "0", eighth_arg, argv[4], "./sorter3", NULL};
			execv(args[0], args);
            exit(1);
		}
	}



	if (pid2==0 ){
		// printf("This is Child 2 speaking\n");

		if (strcmp(argv[3],"-q")==0){
			char* args[] = {"./quick", argv[2], eighth_arg , quarter_arg, argv[4], "./sorter4", NULL};
			execv(args[0], args);
            exit(2);
        }
        if (strcmp(argv[3],"-h")==0){
			char* args[] = {"./heap", argv[2], eighth_arg , quarter_arg, argv[4], "./sorter4", NULL};
			execv(args[0], args);
            exit(2);
        }

	}



    	if (pid3==0 ){
    		// printf("This is Child 3 speaking\n");

    		if (strcmp(argv[3],"-q")==0){
    			char* args[] = {"./quick", argv[2], quarter_arg , two_quarters_arg, argv[4], "./sorter5", NULL};
    			execv(args[0], args);
                exit(2);
            }
            if (strcmp(argv[3],"-h")==0){
    			char* args[] = {"./heap", argv[2], quarter_arg , two_quarters_arg, argv[4], "./sorter5", NULL};
    			execv(args[0], args);
                exit(2);
            }

    	}



        if (pid4==0 ){
        	// printf("This is Child 4 speaking\n");

    		if (strcmp(argv[3],"-q")==0){
    			char* args[] = {"./quick", argv[2], two_quarters_arg , argv[5], argv[4], "./sorter6", NULL};
    			execv(args[0], args);
                exit(2);
            }
            if (strcmp(argv[3],"-h")==0){
    			char* args[] = {"./heap", argv[2], two_quarters_arg , argv[5], argv[4], "./sorter6", NULL};
    			execv(args[0], args);
                exit(2);
            }

    	}



		if (pid1>0 && pid2>0 && pid3>0  && pid4>0 ){
            if (signal(SIGUSR2, sig_handler) == SIG_ERR){
                printf("\ncan't catch SIGUSR1\n");
            }
            mkfifo("./sorter3", 0666);

            MyRecord buff[50];
            int j=0;
            int range=eighth;
            char output[20];
            strcpy(output,"output");
            strncat(output,argv[4],1);
            strncat(output, ".txt", 4);

            fpw=fopen(output, "a");
            fd = open("./sorter3", O_RDONLY);
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
            read(fd, &time3,sizeof(time3));
            // printf("Sorter3 finished in %lf sec (REAL TIME)\n", time3 );
            unlink("./sorter3");
            close(fd);


        }
        if (pid1>0 && pid2>0 && pid3>0  && pid4>0 ){
        // if (signal(SIGUSR2, sig_handler) == SIG_ERR)
        // printf("\ncan't catch SIGUSR1\n");
        mkfifo("./sorter4", 0666);
        MyRecord buff[50];
        int j=0;
        int range = quarter-eighth;
        char output[20];
        strcpy(output,"output");
        strncat(output,argv[4],1);
        strncat(output, ".txt", 4);

        // fpw=fopen(output, "a");
        // wait(NULL);

        fd = open("./sorter4", O_RDONLY);
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

    read(fd, &time4,sizeof(time4));
    // printf("Sorter4 finished in %lf sec (REAL TIME)\n", time4 );
    unlink("./sorter4");
    close(fd);
        // fclose(fpw);
    }

    if (pid1>0 && pid2>0 && pid3>0  && pid4>0){
        // if (signal(SIGUSR2, sig_handler) == SIG_ERR)
                // printf("\ncan't catch SIGUSR1\n");
        mkfifo("./sorter5", 0666);
        MyRecord buff[50];
        int j=0;
        int range = two_quarters-quarter;
        char output[20];
        strcpy(output,"output");
        strncat(output,argv[4],1);
        strncat(output, ".txt", 4);
        // fpw=fopen(output, "a");
        // wait(NULL);
        fd = open("./sorter5", O_RDONLY);
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
            read(fd, &time5,sizeof(time5));
            // printf("Sorter5 finished in %lf sec (REAL TIME)\n", time5 );
            unlink("./sorter5");
            close(fd);
                    // fclose(fpw);

    }


		if (pid1>0 && pid2>0 && pid3>0  && pid4>0 ){
            // if (signal(SIGUSR2, sig_handler) == SIG_ERR)
				// printf("\ncan't catch SIGUSR1\n");
            mkfifo("./sorter6", 0666);
			MyRecord buff[50];
	        int j=0;
	        int range = atoi(argv[5])-two_quarters;
	        char output[20];
	        strcpy(output,"output");
	        strncat(output,argv[4],1);
	        strncat(output, ".txt", 4);

	        // fpw=fopen(output, "a");
            // wait(NULL);

			fd = open("./sorter6", O_RDONLY);
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
        read(fd, &time6,sizeof(time6));
        // printf("Sorter6 finished in %lf sec (REAL TIME)\n", time6 );
		unlink("./sorter6");
        close(fd);
        fclose(fpw);


        min=time3;
        max=time3;
        //finding min
        if (time4<min){
            min=time4;
        }
        if (time5<min){
            min=time5;
        }
        if (time6<min){
            min=time6;
        }
        //finding max
        if (time4>max){
            max=time4;
        }
        if (time5>max){
            max=time5;
        }
        if (time6>max){
            max=time6;
        }
        // sleep(2);       //quick fix
        avg=((time3+time4+time5+time6)/4.0);
        t2 = (double) times(&tb2);
        tcoach3 = (t2 - t1) / ticspersec;
        fd = open("./forcoach3", O_WRONLY);
        buffer[0]=min;
        write(fd, buffer,sizeof(buffer));
        buffer[0]=max;
        write(fd, buffer,sizeof(buffer));
        buffer[0]=avg;
        write(fd, buffer,sizeof(buffer));
        buffer[0]=tcoach3;
        write(fd, buffer, sizeof(buffer));

        write(fd, &counter,sizeof(counter));
        unlink("./forcoach3");
        close(fd);

    }
    free(fpw);
    printf("coach3 done\n" );
    // printf("For Coach3:\nMin time was %lf sec (REAL TIME)\nMax Time was %lf sec (REAL TIME)\nAverage time was %lf sec (REAL TIME)\nTotal runtime for Coach3: %lf sec (REAL TIME)\nSignal SIGUSR2 received %d times.\n\n",min, max, ((time3+time4+time5+time6)/4.0), ((t2 - t1) / ticspersec), counter);
    exit(9);
    return 0;

    }
