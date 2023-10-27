#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int i;
    pid_t child_pid;

    for (i = 0; i < 5; i++) {
        child_pid = fork();
        if (child_pid == 0) {
            // Child process exits immediately, becoming a zombie
            exit(0);
        } else if (child_pid > 0) {
            printf("Zombie process created, PID: %d\n", child_pid);
        }
    }

    // Infinite loop to keep the program running
    while (1) {
        sleep(1);
    }

    return (0);
}
