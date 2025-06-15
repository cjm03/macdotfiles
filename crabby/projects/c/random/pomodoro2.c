#include <stdio.h>
#include <time.h>
#include <unistd.h>

void delay(int seconds)
{
    int ms = 10000 * seconds;
    clock_t startTime = clock();
    while (clock() < startTime + ms);
}

int main()
{
    int workTimer = 25;
    int restTimer = 5;
    int longRestTimer = 15;
    int sessions = 4;
    int seshCount = 0;

    while (1) {
        printf("begin\n");
        for (int i = workTimer; i > 0; i--) {
            printf("Time remaining: %d minutes %d seconds\r", i, 0);
            fflush(stdout);
            delay(600);
        }
        printf("Work session complete. Time for a break.\n");
        seshCount++;

        // Break session
        if (seshCount % sessions == 0) {
            printf("Long break started. Relax for %d minutes.\n", longRestTimer);
            for (int i = longRestTimer; i > 0; i--) {
                printf("Time remaining: %d minutes %d seconds\r", i, 0);
                fflush(stdout);
                delay(600);
            }
            printf("Long break complete. Get ready for the next work session.\n");
        } else {
            printf("Short break started. Relax for %d minutes.\n", restTimer);
            for (int i = restTimer; i > 0; i--) {
                printf("Time remaining: %d minutes %d seconds\r", i, 0);
                fflush(stdout);
                delay(600);
            }
            printf("Short break complete. Get ready for the next work session.\n");
        }
    }

    return 0;
}

