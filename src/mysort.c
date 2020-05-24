#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/times.h> 		/*times*/
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>




int main (int argc, char** argv) {

    double t1, t2;
    struct tms tb1, tb2;
    double ticspersec;
    double time0, coach2min, coach2max, coach2avg, coach3min, coach3max, coach3avg, coach4min, coach4max, coach4avg;
    double buffer[1];
    double tcoach1, tcoach2, tcoach3, tcoach4;

    ticspersec = (double) sysconf(_SC_CLK_TCK);
    t1 = (double) times(&tb1);

    pid_t pid1, pid2, pid3, pid4;
    int /*pid1, pid2, pid3, pid4,*/ fd, counter1, counter2, counter3, counter4;


    printf("%d\n", argc );
    //Case of 1 coach
    if (argc<=6){
        pid1=fork();

        if (pid1==0){
            // printf("This is Coach1 speaking\n");
            if (strcmp(argv[3],"-h")!=0 || strcmp(argv[3],"-q")!=0 ){
    			char* args[] = {"./coach1","-f", argv[2],"-q" , "1", argv[3], NULL};
    			execv(args[0], args);
                exit(10);
    		}
            char* args[] = {"./coach1","-f", argv[2], argv[3], argv[4], argv[5], NULL};
            execv(args[0], args);
            exit(10);
        }
        if (pid1>0){
            mkfifo("./forcoach1", 0666);
            fd = open("./forcoach1", O_RDONLY);
            read(fd, buffer,sizeof(buffer));
            time0=buffer[0];
            read(fd, buffer,sizeof(buffer));
            tcoach1=buffer[0];
            read(fd, &counter1,sizeof(counter1));
            printf("For Coach1:\nMin time was %lf sec (REAL TIME)\nMax Time was %lf sec (REAL TIME)\nAverage time was %lf sec (REAL TIME)\n", time0, time0, time0 );
            printf("Run time for coach1 was %lf sec (REAL time).\nSignal SIGUSR2 received %d times.\n\n",tcoach1, counter1);
            unlink("./forcoach1");
            close(fd);

            printf("Coach Average was %lf\n",tcoach1);
        }


        }
        //Case of 2 Coaches
    if (argc==9){
        pid1=fork();
        if (pid1>0){
        pid2=fork();
    }
        if (pid1==0 ){
            // printf("This is Coach1 speaking\n");
            char* args[] = {"./coach1","-f", argv[2], argv[3], argv[4], argv[5], NULL};
            execv(args[0], args);
            exit(10);
        }
        if (pid2==0){
            // printf("This is Coach2 speaking\n");
            char* args[] = {"./coach2","-f", argv[2], argv[6], argv[7], argv[8], NULL};
            execv(args[0], args);
            exit(10);
        }

        if (pid1>0 && pid2>0){

            mkfifo("./forcoach1", 0666);
            fd = open("./forcoach1", O_RDONLY);
            read(fd, buffer,sizeof(buffer));
            time0=buffer[0];
            read(fd, buffer,sizeof(buffer));
            tcoach1=buffer[0];
            read(fd, &counter1,sizeof(counter1));
            printf("For Coach1:\nMin time was %lf sec (REAL TIME)\nMax Time was %lf sec (REAL TIME)\nAverage time was %lf sec (REAL TIME)\n", time0, time0, time0 );
            printf("Run time for coach1 was %lf sec (REAL time).\nSignal SIGUSR2 received %d times.\n\n",tcoach1, counter1);
            unlink("./forcoach1");
            close(fd);

            mkfifo("./forcoach2", 0666);
            fd = open("./forcoach2", O_RDONLY);
            read(fd, buffer,sizeof(buffer));
            coach2min=buffer[0];
            read(fd, buffer,sizeof(buffer));
            coach2max=buffer[0];
            read(fd, buffer,sizeof(buffer));
            coach2avg=buffer[0];
            read(fd, buffer,sizeof(buffer));
            tcoach2=buffer[0];
            read(fd, &counter2,sizeof(counter2));


            printf("For Coach2:\nMin time was %lf sec (REAL TIME)\nMax Time was %lf sec (REAL TIME)\nAverage time was %lf sec (REAL TIME)\n", coach2min, coach2max, coach2avg );
            printf("Run time for coach2 was %lf sec (REAL time) .\nSignal SIGUSR2 received %d times.\n\n", tcoach2, counter2);
            unlink("./forcoach2");
            close(fd);

            printf("Coach Average was %lf\n",(tcoach1+tcoach2)/2.0 );

        }

    }

    //Case of 3 Coaches

    if (argc==12){
        pid1=fork();
        if (pid1>0){
        pid2=fork();
        }
        if (pid1>0 && pid2>0){
            pid3=fork();
        }
        if (pid1==0){
            // printf("This is Coach1 speaking\n");
            char* args[] = {"./coach1","-f", argv[2], argv[3], argv[4], argv[5], NULL};
            execv(args[0], args);
            exit(10);
        }
        if (pid2==0){
            // printf("This is Coach2 speaking\n");
            char* args[] = {"./coach2","-f", argv[2], argv[6], argv[7], argv[8], NULL};
            execv(args[0], args);
            exit(10);
        }
        if (pid3==0){
            // printf("This is Coach3 speaking\n");
            char* args[] = {"./coach3","-f", argv[2], argv[9], argv[10], argv[11], NULL};
            execv(args[0], args);
            exit(10);
        }
        if (pid1>0 && pid2>0 && pid3>0){

            mkfifo("./forcoach1", 0666);
            fd = open("./forcoach1", O_RDONLY);
            read(fd, buffer,sizeof(buffer));
            time0=buffer[0];
            read(fd, buffer,sizeof(buffer));
            tcoach1=buffer[0];
            read(fd, &counter1,sizeof(counter1));
            printf("For Coach1:\nMin time was %lf sec (REAL TIME)\nMax Time was %lf sec (REAL TIME)\nAverage time was %lf sec (REAL TIME)\n", time0, time0, time0 );
            printf("Run time for coach1 was %lf sec (REAL time).\nSignal SIGUSR2 received %d times.\n\n",tcoach1, counter1);
            unlink("./forcoach1");
            close(fd);

            mkfifo("./forcoach2", 0666);
            fd = open("./forcoach2", O_RDONLY);
            read(fd, buffer,sizeof(buffer));
            coach2min=buffer[0];
            read(fd, buffer,sizeof(buffer));
            coach2max=buffer[0];
            read(fd, buffer,sizeof(buffer));
            coach2avg=buffer[0];
            read(fd, buffer,sizeof(buffer));
            tcoach2=buffer[0];
            read(fd, &counter2,sizeof(counter2));


            printf("For Coach2:\nMin time was %lf sec (REAL TIME)\nMax Time was %lf sec (REAL TIME)\nAverage time was %lf sec (REAL TIME)\n", coach2min, coach2max, coach2avg );
            printf("Run time for coach2 was %lf sec (REAL time) .\nSignal SIGUSR2 received %d times.\n\n", tcoach2, counter2);
            unlink("./forcoach2");
            close(fd);


            mkfifo("./forcoach3", 0666);
            fd = open("./forcoach3", O_RDONLY);
            read(fd, buffer,sizeof(buffer));
            coach3min=buffer[0];
            read(fd, buffer,sizeof(buffer));
            coach3max=buffer[0];
            read(fd, buffer,sizeof(buffer));
            coach3avg=buffer[0];
            read(fd, buffer,sizeof(buffer));
            tcoach3=buffer[0];
            read(fd, &counter3,sizeof(counter3));
            // waitpid( pid3, status, options);



            printf("For Coach3:\nMin time was %lf sec (REAL TIME)\nMax Time was %lf sec (REAL TIME)\nAverage time was %lf sec (REAL TIME)\n", coach3min, coach3max, coach3avg );
            printf("Run time for coach3 was %lf sec (REAL time) .\nSignal SIGUSR2 received %d times.\n\n", tcoach3, counter3);
            unlink("./forcoach3");
            close(fd);
            printf("Coach Average was %lf\n",(tcoach1+tcoach2+tcoach3)/3.0 );
        }


    }


    //Case of 4 coaches
    if (argc==15){
        pid1=fork();
        if (pid1>0){
        pid2=fork();
        }
        if (pid1>0 && pid2>0){
            pid3=fork();
        }
        if (pid1>0 && pid2>0 && pid3>0){
            pid4=fork();
        }
        if (pid1==0){
            // printf("This is Coach1 speaking\n");
            char* args[] = {"./coach1","-f", argv[2], argv[3], argv[4], argv[5], NULL};
            execv(args[0], args);
            exit(10);
    }
        if (pid2==0){
            // printf("This is Coach2 speaking\n");
            char* args[] = {"./coach2","-f", argv[2], argv[6], argv[7], argv[8], NULL};
            execv(args[0], args);
            exit(10);
        }
        if (pid3==0){
            // printf("This is Coach3 speaking\n");
            char* args[] = {"./coach3","-f", argv[2], argv[9], argv[10], argv[11], NULL};
            execv(args[0], args);
            exit(10);
        }

        if (pid4==0){
            // printf("This is Coach4 speaking\n");
            char* args[] = {"./coach4","-f", argv[2], argv[12], argv[13], argv[14], NULL};
            execv(args[0], args);
            exit(10);
        }

        if (pid1>0 && pid2>0 && pid3>0 && pid4>0){

            mkfifo("./forcoach1", 0666);
            fd = open("./forcoach1", O_RDONLY);
            read(fd, buffer,sizeof(buffer));
            time0=buffer[0];
            read(fd, buffer,sizeof(buffer));
            tcoach1=buffer[0];
            read(fd, &counter1,sizeof(counter1));
            printf("For Coach1:\nMin time was %lf sec (REAL TIME)\nMax Time was %lf sec (REAL TIME)\nAverage time was %lf sec (REAL TIME)\n", time0, time0, time0 );
            printf("Run time for coach1 was %lf sec (REAL time).\nSignal SIGUSR2 received %d times.\n\n",tcoach1, counter1);
            unlink("./forcoach1");
            close(fd);

            mkfifo("./forcoach2", 0666);
            fd = open("./forcoach2", O_RDONLY);
            read(fd, buffer,sizeof(buffer));
            coach2min=buffer[0];
            read(fd, buffer,sizeof(buffer));
            coach2max=buffer[0];
            read(fd, buffer,sizeof(buffer));
            coach2avg=buffer[0];
            read(fd, buffer,sizeof(buffer));
            tcoach2=buffer[0];
            read(fd, &counter2,sizeof(counter2));


            printf("For Coach2:\nMin time was %lf sec (REAL TIME)\nMax Time was %lf sec (REAL TIME)\nAverage time was %lf sec (REAL TIME)\n", coach2min, coach2max, coach2avg );
            printf("Run time for coach2 was %lf sec (REAL time) .\nSignal SIGUSR2 received %d times.\n\n", tcoach2, counter2);
            unlink("./forcoach2");
            close(fd);


            mkfifo("./forcoach3", 0666);
            fd = open("./forcoach3", O_RDONLY);
            read(fd, buffer,sizeof(buffer));
            coach3min=buffer[0];
            read(fd, buffer,sizeof(buffer));
            coach3max=buffer[0];
            read(fd, buffer,sizeof(buffer));
            coach3avg=buffer[0];
            read(fd, buffer,sizeof(buffer));
            tcoach3=buffer[0];
            read(fd, &counter3,sizeof(counter3));
            // waitpid( pid3, status, options);



            printf("For Coach3:\nMin time was %lf sec (REAL TIME)\nMax Time was %lf sec (REAL TIME)\nAverage time was %lf sec (REAL TIME)\n", coach3min, coach3max, coach3avg );
            printf("Run time for coach3 was %lf sec (REAL time) .\nSignal SIGUSR2 received %d times.\n\n", tcoach3, counter3);
            unlink("./forcoach3");
            close(fd);


            mkfifo("./forcoach4", 0666);
            fd = open("./forcoach4", O_RDONLY);
            read(fd, buffer,sizeof(buffer));
            coach4min=buffer[0];
            read(fd, buffer,sizeof(buffer));
            coach4max=buffer[0];
            read(fd, buffer,sizeof(buffer));
            coach4avg=buffer[0];
            read(fd, buffer,sizeof(buffer));
            tcoach4=buffer[0];
            read(fd, &counter4,sizeof(counter4));
            // waitpid( pid3, status, options);


            printf("For Coach4:\nMin time was %lf sec (REAL TIME)\nMax Time was %lf sec (REAL TIME)\nAverage time was %lf sec (REAL TIME)\n", coach4min, coach4max, coach4avg );
            printf("Run time for coach3 was %lf sec (REAL time) .\nSignal SIGUSR2 received %d times.\n\n", tcoach4, counter4);
            unlink("./forcoach4");
            close(fd);
            printf("Coach Average was %lf\n",(tcoach1+tcoach2+tcoach3+tcoach4)/4.0 );
        }


    }
    // wait(NULL);
    t2 = (double) times(&tb2);
    printf("Turnarround time for program was %lf\n", (t2 - t1) / ticspersec);
    return 0;
}
