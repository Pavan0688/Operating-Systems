#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void print_odd_numbers() {
    printf("Odd numbers: ");
    for (int i = 1; i <= 10; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
}

void print_even_numbers() {
    printf("Even numbers: ");
    for (int i = 2; i <= 10; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
}

void print_multiples_of_3() {
    printf("Multiples of 3: ");
    for (int i = 3; i <= 30; i += 3) {
        printf("%d ", i);
    }
    printf("\n");
}

void print_multiples_of_5() {
    printf("Multiples of 5: ");
    for (int i = 5; i <= 50; i += 5) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    pid_t pid1, pid2, pid3, pid4;

    // create first child process
    pid1 = fork();

    if (pid1 < 0) {
        fprintf(stderr, "Error creating first child process\n");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        // first child process
        printf("First child process (pid=%d):\n", getpid());
        print_odd_numbers();
        exit(EXIT_SUCCESS);
    }

    // create second child process
    pid2 = fork();

    if (pid2 < 0) {
        fprintf(stderr, "Error creating second child process\n");
        exit(EXIT_FAILURE);
    } else if (pid2 == 0) {
        // second child process
        printf("Second child process (pid=%d):\n", getpid());
        print_even_numbers();
        exit(EXIT_SUCCESS);
    }

    // create third child process
    pid3 = fork();

    if (pid3 < 0) {
        fprintf(stderr, "Error creating third child process\n");
        exit(EXIT_FAILURE);
    } else if (pid3 == 0) {
        // third child process
        printf("Third child process (pid=%d):\n", getpid());
        print_multiples_of_3();
        exit(EXIT_SUCCESS);
    }

    // create fourth child process
    pid4 = fork();

    if (pid4 < 0) {
        fprintf(stderr, "Error creating fourth child process\n");
        exit(EXIT_FAILURE);
    } else if (pid4 == 0) {
        // fourth child process
        printf("Fourth child process (pid=%d):\n", getpid());
        print_multiples_of_5();
        exit(EXIT_SUCCESS);
    }

    // wait for all child processes to finish
    wait(NULL);
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}
