#include "kernel/types.h"
#include "user/user.h"

#define EXCHANGES 10000

int
main(int argc, char *argv[])
{
    int p1[2];
    int p2[2];
    char buf = 'a';
    int i;

    pipe(p1);
    pipe(p2);

    int pid = fork();

    if(pid == 0){
        // child
        for(i = 0; i < EXCHANGES; i++){
            read(p1[0], &buf, 1);
            write(p2[1], &buf, 1);
        }
    } else {
        // parent
        int start = uptime();

        for(i = 0; i < EXCHANGES; i++){
            write(p1[1], &buf, 1);
            read(p2[0], &buf, 1);
        }

        int end = uptime();
        int ticks = end - start;

        int seconds = ticks / 10;

        printf("Total exchanges: %d\n", EXCHANGES);
        printf("Time (seconds): %d\n", seconds);

        if(seconds > 0){
            printf("Exchanges per second: %d\n", EXCHANGES / seconds);
        } else {
            printf("Program finished too fast to measure seconds\n");
        }
    }

    exit(0);
}
