/**
 * @file
 * @author cpieloth
 *
 * Best practice for parsing command line arguments with getopt.
 * http://www.gnu.org/software/libc/manual/html_node/Getopt.html
 */

#include <ctype.h> // isprint
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE
#include <unistd.h> // getopt
#ifdef __GNUC__
// workaround for errors with getopt, opterr, optarg, optopt
#include <getopt.h>
#endif // __GNUC__

/**
 * Prints a help messages.
 */
static void print_help()
{
    printf("Best practice for parsing command line arguments with getopt.\n");
    printf("Usage: $ ./getopt_cli [-a] [-b] [-c <val>] [-d[<val>]] [-h]\n");
    printf("\n");
    printf("Arguments:\n");
    printf("   -a   Sets flag a to true.\n");
    printf("   -b   Sets flag b to true.\n");
    printf("   -c   Sets value c.\n");
    printf("   -d   Sets value d (optional, default: 42).\n");
    printf("   -h   Prints a help message.\n");
}

/**
 * Structure for all command line interface arguments.
 */
struct cli_args
{
    bool aflag;
    bool bflag;
    char* cvalue;
    long int dvalue;
    bool dflag;
};

/**
 * Parses and sets the command line interface arguments.
 *
 * @param argc Number of provided arguments.
 * @param argv Pointers to provided arguments.
 * @param args Structure which holds the CLI arguments.
 * @return True if all required values are set.
 */
static bool parse_arguments(int argc, char* const *argv, struct cli_args* const args)
{
    // set default values
    args->aflag = false;
    args->bflag = false;
    args->cvalue = NULL;
    args->dvalue = 42;
    args->dflag = false;

    int c;
    opterr = 0;

    while ((c = getopt(argc, argv, "abc:d::h")) != -1)
    {
        switch (c)
        {
        case 'a':
            args->aflag = true;
            break;
        case 'b':
            args->bflag = true;
            break;
        case 'c':
            args->cvalue = optarg;
            break;
        case 'd':
            args->dflag = true;
            if (optarg != NULL)
            {
                errno = 0;
                args->dvalue = strtol(optarg, NULL, 0);
                if(errno)
                {
                    fprintf(stderr, "Could not parse value of d: %s\n", optarg);
                    return false;
                }
            }
            break;
        case 'h':
            print_help();
            return false;
        case '?':
            if (optopt == 'c')
            {
                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                print_help();
            }
            else if (isprint(optopt))
            {
                fprintf(stderr, "Unknown option '-%c'.\n", optopt);
                print_help();
            }
            else
            {
                fprintf(stderr, "Unknown option character '\\x%x'.\n", optopt);
                print_help();
            }
            return false;
        default:
            abort();
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    struct cli_args args;
    if (parse_arguments(argc, argv, &args) != true)
    {
        return EXIT_FAILURE;
    }

    printf("aflag = %d, bflag = %d, cvalue = %s, ", args.aflag, args.bflag, args.cvalue);
    printf("dflag = %d, dvalue = %ld\n", args.dflag, args.dvalue);

    return EXIT_SUCCESS;
}
