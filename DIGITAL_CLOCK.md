```c
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <windows.h>

int main(){

    // DIGITAL CLOCK
    time_t rawtime = 0;
    struct tm *pTime = NULL;
    bool isRunning = true;

    printf("DIGITAL CLOCK\n");

    while(isRunning){
        // printf("TEST\n");

        time (&rawtime);
        // printf("%ld\n", rawtime);

        pTime = localtime(&rawtime);
        printf("\r%02d:%02d:%02d", (*pTime).tm_hour, (*pTime).tm_min, (*pTime).tm_sec); // = pTime->tm_hour

        sleep(1);
    }


    return 0;
}

```
