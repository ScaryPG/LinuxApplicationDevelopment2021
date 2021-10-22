#include <stdio.h>

int
main(const int argc, const char **argv)
{
    int start, stop, step;

    switch (argc) {
        case 2:
            start = 0;
            sscanf(argv[1], "%d", &stop);
            step = 1;
            break;
        case 3:
            sscanf(argv[1], "%d", &start);
            sscanf(argv[2], "%d", &stop);
            step = 1;
            break;
        case 4:
            sscanf(argv[1], "%d", &start);
            sscanf(argv[2], "%d", &stop);
            sscanf(argv[3], "%d", &step);
            break;
        default:
            printf("./range N – print numbers from 0 to N - 1 inclusive with a step of 1");
            printf("./range M N – print numbers from M to N - 1 inclusive with a step of 1");
            printf("./range M N S – print numbers from M to N - 1 inclusive with a step of S");
            break;
    }

    for (int i = start; i < stop; i += step) {
        printf("%d\n", i);
    }

    return 0;
}
