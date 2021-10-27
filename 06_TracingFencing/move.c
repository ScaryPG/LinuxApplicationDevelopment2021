#include <stdio.h>

int
main(const int argc, const char **argv)
{
    FILE *infile, *outfile;
    int c;
    long int infile_size, outfile_size;

    if (argc != 3) {
        fprintf(stderr, "Incorrect number of arguments\n");
        return 1;
    }

    if ((infile = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Failed to open infile\n");
        return 2;
    }

    if (fseek(infile, 0, SEEK_END) != 0) {
        fprintf(stderr, "Failed to fseek infile\n");
        return 3;
    }

    if ((infile_size = ftell(infile)) == -1) {
        fprintf(stderr, "Failed to ftell infile\n");
        return 4;
    }

    if (fseek(infile, 0, SEEK_SET)) {
        fprintf(stderr, "Failed to fseek infile\n");
        return 5;
    }

    if ((outfile = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "Failed to open outfile\n");
        return 6;
    }

    while ((c = fgetc(infile)) != EOF) {
        fputc(c, outfile);
    }

    if (fseek(outfile, 0, SEEK_END) != 0) {
        fprintf(stderr, "Failed to fseek outfile\n");
        return 7;
    }

    if ((outfile_size = ftell(outfile)) == -1) {
        fprintf(stderr, "Failed to ftell outfile\n");
        return 8;
    }

    if (infile_size != outfile_size) {
        fprintf(stderr, "File sizes don't match\n");
        return 9;
    }

    if (fclose(outfile) != 0) {
        fprintf(stderr, "Failed to close outfile\n");
        return 10;
    }

    if (fclose(infile) != 0) {
        fprintf(stderr, "Failed to close infile\n");
        return 11;
    }

    if (remove(argv[1]) != 0) {
        fprintf(stderr, "Failed to remove infile\n");
        return 12;
    }

    return 0;
}
