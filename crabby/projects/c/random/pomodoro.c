#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>

int main(void)
{
    // time_t currentTime = time(NULL);                                            // Get current unix timestamp
    int work, rest;
    clock_t start, now, end;
    struct tm workTimer, restTimer;                                                       // Get current local time based on unix timestamp
            // printf("Local Time: %s\n", asctime(currentTimeLocal));                      // Print current local time: ex "Sun May 15 06:24:11 2025"
            // char formattedCTL[10];                                                      // Declare array to store time formatted to just hour:minute:second
            // strftime(formattedCTL, sizeof(formattedCTL), "%H:%M:%S", currentTimeLocal); // ^
            // printf("%s\n", formattedCTL);

    workTimer.tm_year = -1;
    workTimer.tm_mon = -1;
    workTimer.tm_mday = -1;
    workTimer.tm_hour = -1;
    workTimer.tm_min = 25;
    workTimer.tm_sec = -1;
    workTimer.tm_isdst = -1;
    work = mktime(&workTimer);

    restTimer.tm_year = -1;
    restTimer.tm_mon = -1;
    restTimer.tm_mday = -1;
    restTimer.tm_hour = -1;
    restTimer.tm_min = 5;
    restTimer.tm_sec = -1;
    restTimer.tm_isdst = -1;
    rest = mktime(&restTimer);
    
    printf("work: %d\n", work);
    printf("rest: %d\n", rest);
    start = clock();
    double elapsed = ((double)start / CLOCKS_PER_SEC);
    // while () {
    //     char temp[10];
    //     sprintf(temp,
    // }
}
