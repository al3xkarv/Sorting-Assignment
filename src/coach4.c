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
    double time7, time8, time9, time10, time11, time12, time13, time14;
    double min, max, avg, tcoach4;
    double buffer[1];
    ticspersec = (double) sysconf(_SC_CLK_TCK);
    t1 = (double) times(&tb1);


	int pid1, pid2, pid3, pid4, pid5, pid6, pid7, pid8, fd, i;
	long  sixteenth, eighth,threesixteenths, quarter, sixsixteenths, eightsixteenths, twelvesixteenths;
	FILE* fpw;


    sixteenth=atoi(argv[5])/16;
    eighth=2*sixteenth;
    threesixteenths=3*sixteenth;
    sixsixteenths=6*sixteenth;
    eightsixteenths=8*sixteenth;
    twelvesixteenths=12*sixteenth;
    quarter=2*eighth;

    char sixteenth_arg[9];
    char eighth_arg[9];
    char threesixteenths_arg[9];
    char quarter_arg[9];
    char sixsixteenths_arg[9];
    char eightsixteenths_arg[9];
    char twelvesixteenths_arg[9];


    sprintf (sixteenth_arg, "%ld", sixteenth);
    sprintf (threesixteenths_arg, "%ld", threesixteenths);
    sprintf (sixsixteenths_arg, "%ld", sixsixteenths);
    sprintf (eightsixteenths_arg, "%ld", eightsixteenths);
    sprintf (twelvesixteenths_arg, "%ld", twelvesixteenths);
    sprintf (eighth_arg, "%ld", eighth);
    sprintf (quarter_arg, "%ld", quarter);

    // printf ("%s %s %s %s %s %s %s\n", sixteenth_arg, eighth_arg, threesixteenths_arg, quarter_arg, sixsixteenths_arg, eightsixteenths_arg, twelvesixteenths_arg );
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

    if (pid1 > 0 && pid2 >0 && pid3 > 0 && pid4>0){
        pid5=fork();
    }
    if (pid1 > 0 && pid2 >0 && pid3 > 0 && pid4 && pid5>0){
        pid6=fork();
    }

    if (pid1 > 0 && pid2 >0 && pid3 > 0 && pid4 && pid5>0 && pid6>0){
        pid7=fork();
    }

    if (pid1 > 0 && pid2 >0 && pid3 > 0 && pid4 && pid5>0 && pid6>0 && pid7>0){
        pid8=fork();
    }

	if (pid1==0){
		// printf("This is Child 1 speaking of coach4\n");


		if (strcmp(argv[3],"-q")==0){
			char* args[] = {"./quick", argv[2], "0", sixteenth_arg, argv[4], "./sorter7", NULL};
			execv(args[0], args);
            exit(1);
		}
        if (strcmp(argv[3],"-h")==0){
			char* args[] = {"./heap", argv[2], "0", sixteenth_arg, argv[4], "./sorter7", NULL};
			execv(args[0], args);
            exit(1);
		}
	}



	if (pid2==0 ){
		// printf("This is Child 2 speaking of coach4\n");

		if (strcmp(argv[3],"-q")==0){
			char* args[] = {"./quick", argv[2], sixteenth_arg , eighth_arg, argv[4], "./sorter8", NULL};
			execv(args[0], args);
            exit(2);
        }
        if (strcmp(argv[3],"-h")==0){
			char* args[] = {"./heap", argv[2], sixteenth_arg , eighth_arg, argv[4], "./sorter8", NULL};
			execv(args[0], args);
            exit(2);
        }

	}



    	if (pid3==0 ){
    		// printf("This is Child 3 of coach4 speaking\n");

    		if (strcmp(argv[3],"-q")==0){
    			char* args[] = {"./quick", argv[2], eighth_arg , threesixteenths_arg, argv[4], "./sorter9", NULL};
    			execv(args[0], args);
                exit(2);
            }
            if (strcmp(argv[3],"-h")==0){
    			char* args[] = {"./heap", argv[2], eighth_arg , threesixteenths_arg, argv[4], "./sorter9", NULL};
    			execv(args[0], args);
                exit(2);
            }

    	}



        if (pid4==0 ){
        	// printf("This is Child 4 of coach4 speaking\n");

    		if (strcmp(argv[3],"-q")==0){
    			char* args[] = {"./quick", argv[2], threesixteenths_arg , quarter_arg, argv[4], "./sorter10", NULL};
    			execv(args[0], args);
                exit(2);
            }
            if (strcmp(argv[3],"-h")==0){
    			char* args[] = {"./heap", argv[2], threesixteenths_arg , quarter_arg, argv[4], "./sorter10", NULL};
    			execv(args[0], args);
                exit(2);
            }

    	}

        if (pid5==0 ){
        	// printf("This is Child 5 of coach4 speaking\n");

    		if (strcmp(argv[3],"-q")==0){
    			char* args[] = {"./quick", argv[2], quarter_arg , sixsixteenths_arg, argv[4], "./sorter11", NULL};
    			execv(args[0], args);
                exit(2);
            }
            if (strcmp(argv[3],"-h")==0){
    			char* args[] = {"./heap", argv[2], quarter_arg , sixsixteenths_arg, argv[4], "./sorter11", NULL};
    			execv(args[0], args);
                exit(2);
            }

    	}

        if (pid6==0 ){
        	// printf("This is Child 6 of coach4 speaking\n");

    		if (strcmp(argv[3],"-q")==0){
    			char* args[] = {"./quick", argv[2], sixsixteenths_arg , eightsixteenths_arg, argv[4], "./sorter12", NULL};
    			execv(args[0], args);
                exit(2);
            }
            if (strcmp(argv[3],"-h")==0){
    			char* args[] = {"./heap", argv[2], sixsixteenths_arg , eightsixteenths_arg, argv[4], "./sorter12", NULL};
    			execv(args[0], args);
                exit(2);
            }

    	}

        if (pid7==0 ){
        	// printf("This is Child 7 of coach4 speaking\n");

    		if (strcmp(argv[3],"-q")==0){
    			char* args[] = {"./quick", argv[2], eightsixteenths_arg , twelvesixteenths_arg, argv[4], "./sorter13", NULL};
    			execv(args[0], args);
                exit(2);
            }
            if (strcmp(argv[3],"-h")==0){
    			char* args[] = {"./heap", argv[2], threesixteenths_arg , twelvesixteenths_arg, argv[4], "./sorter13", NULL};
    			execv(args[0], args);
                exit(2);
            }

    	}

        if (pid8==0 ){
        	// printf("This is Child 8 of coach4 speaking\n");

    		if (strcmp(argv[3],"-q")==0){
    			char* args[] = {"./quick", argv[2], twelvesixteenths_arg , argv[5], argv[4], "./sorter14", NULL};
    			execv(args[0], args);
                exit(2);
            }
            if (strcmp(argv[3],"-h")==0){
    			char* args[] = {"./heap", argv[2], twelvesixteenths_arg , argv[5], argv[4], "./sorter14", NULL};
    			execv(args[0], args);
                exit(2);
            }

    	}


		if (pid1>0 && pid2>0 && pid3>0  && pid4>0 && pid5>0 && pid6>0 && pid7>0 && pid8>0 ){
            if (signal(SIGUSR2, sig_handler) == SIG_ERR){
                printf("\ncan't catch SIGUSR1\n");
            }
            mkfifo("./sorter7", 0666);

            MyRecord buff[50];
            int j=0;
            int range=sixteenth;
            char output[20];
            strcpy(output,"output");
            strncat(output,argv[4],1);
            strncat(output, ".txt", 4);

            fpw=fopen(output, "a");
            fd = open("./sorter7", O_RDONLY);
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
            read(fd, &time7,sizeof(time7));
            // printf("Sorter7 finished in %lf sec (REAL TIME)\n", time7 );
            unlink("./sorter7");
            close(fd);


        }
        if (pid1>0 && pid2>0 && pid3>0  && pid4>0 && pid5>0 && pid6>0 && pid7>0 && pid8>0){
        // if (signal(SIGUSR2, sig_handler) == SIG_ERR)
        // printf("\ncan't catch SIGUSR1\n");
        mkfifo("./sorter8", 0666);
        MyRecord buff[50];
        int j=0;
        int range = eighth-sixteenth;
        char output[20];
        strcpy(output,"output");
        strncat(output,argv[4],1);
        strncat(output, ".txt", 4);

        // fpw=fopen(output, "a");
        // wait(NULL);

        fd = open("./sorter8", O_RDONLY);
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

    read(fd, &time8,sizeof(time8));
    // printf("Sorter8 finished in %lf sec (REAL TIME)\n", time8 );
    unlink("./sorter8");
    close(fd);
        // fclose(fpw);
    }

    if (pid1>0 && pid2>0 && pid3>0  && pid4>0 && pid5>0 && pid6>0 && pid7>0 && pid8>0){

        mkfifo("./sorter9", 0666);
        MyRecord buff[50];
        int j=0;
        int range = threesixteenths-eighth;
        char output[20];
        strcpy(output,"output");
        strncat(output,argv[4],1);
        strncat(output, ".txt", 4);
        // fpw=fopen(output, "a");
        // wait(NULL);
        fd = open("./sorter9", O_RDONLY);
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
            read(fd, &time9,sizeof(time9));
            // printf("Sorter9 finished in %lf sec (REAL TIME)\n", time9 );
            unlink("./sorter9");
            close(fd);
                    // fclose(fpw);

    }


		if (pid1>0 && pid2>0 && pid3>0  && pid4>0 && pid5>0 && pid6>0 && pid7>0 && pid8>0){

            mkfifo("./sorter10", 0666);
			MyRecord buff[50];
	        int j=0;
	        int range = quarter-threesixteenths;
	        char output[20];
	        strcpy(output,"output");
	        strncat(output,argv[4],1);
	        strncat(output, ".txt", 4);

	        // fpw=fopen(output, "a");
            // wait(NULL);
            fd = open("./sorter10", O_RDONLY);
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
        read(fd, &time10,sizeof(time10));
        // printf("Sorter10 finished in %lf sec (REAL TIME)\n", time10 );
		unlink("./sorter10");
        close(fd);

}

if (pid1>0 && pid2>0 && pid3>0  && pid4>0 && pid5>0 && pid6>0 && pid7>0 && pid8>0){

    mkfifo("./sorter11", 0666);
    MyRecord buff[50];
    int j=0;
    int range = sixsixteenths-quarter;
    char output[20];
    strcpy(output,"output");
    strncat(output,argv[4],1);
    strncat(output, ".txt", 4);
    // fpw=fopen(output, "a");
    // wait(NULL);
    fd = open("./sorter11", O_RDONLY);
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
        read(fd, &time11,sizeof(time11));
        // printf("Sorter11 finished in %lf sec (REAL TIME)\n", time11 );
        unlink("./sorter11");
        close(fd);

}


if (pid1>0 && pid2>0 && pid3>0  && pid4>0 && pid5>0 && pid6>0 && pid7>0 && pid8>0){

    mkfifo("./sorter12", 0666);
    MyRecord buff[50];
    int j=0;
    int range = eightsixteenths-sixsixteenths;
    char output[20];
    strcpy(output,"output");
    strncat(output,argv[4],1);
    strncat(output, ".txt", 4);
    // fpw=fopen(output, "a");
    // wait(NULL);
    fd = open("./sorter12", O_RDONLY);
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
        read(fd, &time12,sizeof(time12));
        // printf("Sorter12 finished in %lf sec (REAL TIME)\n", time12 );
        unlink("./sorter12");
        close(fd);

}


if (pid1>0 && pid2>0 && pid3>0  && pid4>0 && pid5>0 && pid6>0 && pid7>0 && pid8>0){

    mkfifo("./sorter13", 0666);
    MyRecord buff[50];
    int j=0;
    int range = twelvesixteenths-eightsixteenths;
    char output[20];
    strcpy(output,"output");
    strncat(output,argv[4],1);
    strncat(output, ".txt", 4);
    // fpw=fopen(output, "a");
    // wait(NULL);
    fd = open("./sorter13", O_RDONLY);
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
        read(fd, &time13,sizeof(time13));
        // printf("Sorter13 finished in %lf sec (REAL TIME)\n", time13 );
        unlink("./sorter13");
        close(fd);

}


if (pid1>0 && pid2>0 && pid3>0  && pid4>0 && pid5>0 && pid6>0 && pid7>0 && pid8>0){

    mkfifo("./sorter14", 0666);
    MyRecord buff[50];
    int j=0;
    int range = atoi(argv[5])-twelvesixteenths;
    char output[20];
    strcpy(output,"output");
    strncat(output,argv[4],1);
    strncat(output, ".txt", 4);
    // fpw=fopen(output, "a");
    // wait(NULL);
    fd = open("./sorter14", O_RDONLY);
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
        read(fd, &time14,sizeof(time14));
        // printf("Sorter14 finished in %lf sec (REAL TIME)\n", time14 );
        unlink("./sorter14");
        close(fd);

        fclose(fpw);


        t2 = (double) times(&tb2);
        min=time7;
        max=time7;
        //finding min
        if (time8<min){
            min=time8;
        }
        if (time9<min){
            min=time9;
        }
        if (time10<min){
            min=time10;
        }
        if (time11<min){
            min=time11;
        }
        if (time12<min){
            min=time12;
        }
        if (time13<min){
            min=time13;
        }
        if (time14<min){
            min=time14;
        }

        //finding max
        if (time8>max){
            max=time8;
        }
        if (time9>max){
            max=time9;
        }
        if (time10>max){
            max=time10;
        }
        if (time11>max){
            max=time11;
        }

        if (time12>max){
            max=time12;
        }

        if (time13>max){
            max=time13;
        }

        if (time14>max){
            max=time14;
        }
        sleep(2); //quick-bad "fix"
        avg=((time7+time8+time9+time10+time11+time12+time13+time14)/8.0);
        t2 = (double) times(&tb2);
        tcoach4 = (t2 - t1) / ticspersec;
        fd = open("./forcoach4", O_WRONLY);
        buffer[0]=min;
        write(fd, buffer,sizeof(buffer));
        buffer[0]=max;
        write(fd, buffer,sizeof(buffer));
        buffer[0]=avg;
        write(fd, buffer,sizeof(buffer));
        buffer[0]=tcoach4;
        write(fd, buffer, sizeof(buffer));

        write(fd, &counter,sizeof(counter));
        unlink("./forcoach4");
        close(fd);

        // printf("For Coach4:\nMin time was %lf sec (REAL TIME)\nMax Time was %lf sec (REAL TIME)\nAverage time was %lf sec (REAL TIME)\nTotal runtime for Coach3: %lf sec (REAL TIME)\nSignal SIGUSR2 received %d times.\n\n",min, max, ((time7+time8+time9+time10+time11+time12+time13+time14)/8.0), ((t2 - t1) / ticspersec), counter);

    }
        free(fpw);
        printf("coach4 done\n" );
		return 0;
}
