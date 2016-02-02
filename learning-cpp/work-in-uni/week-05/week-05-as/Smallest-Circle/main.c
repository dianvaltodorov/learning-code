#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#include <argp.h>
#include <time.h>

const char *argp_program_version =
        "matrix-multiplication 1.0";
const char *argp_program_bug_address =
        "<dianvaltodorov@gmail.com>";

/* Program documentation. */
static char doc[] =
        "Calculate the product of two of matrix A(m, n) and matrix B(n, k).\
        Specify the number of threads for the computation to run on.";

        /* Used by main to communicate with parse_opt. */
        struct arguments
{
        int m;
        int n;
        int k;
        char *output_file;
        char *input_file;
        int tasks;
        int range;
        int quiet;
        };

/* The options we understand. */
static struct argp_option options[] =
{
{0,0,0,0, "Matrix dimensions :"},
{"mdim",     'm', "M",      0,  "Set the m dimension to M" },
{"ndim",     'n', "N",      0,  "Set the n dimension to N" },
{"kdim",     'k', "K",      0,  "Set the k dimension to K" },

{0,0,0,0, "Running options :" },
{"range",    'r', "RANGE",  0,
    "Set the range [-RANGE; RANGE] for generating  the random numbers(default = INT_MAX)" },
{"tasks",    't', "T",      0,  "Run computations on T number of threads (default = INT_MAX)." },

{0,0,0,0, "General Input Control : " },
{"input",    'i', "FILE",   0,  "Read input from FILE. "},

{0,0,0,0, "General Output Control :" },
{"output",   'o', "FILE",   0,  "Place output in file FILE." },
{"quiet",    'q', 0,        0,  "Print only time of execution on the standard output" },
{"silent",   's', 0,        OPTION_ALIAS },

{0,0,0,0, "Generic Program information :", 0},
{ 0 }
};

int* a;
int* b;
int* c;
int m;
int n;
int k;

struct matrix_portion_bounds
{
    int from;
    int to;
};

/*Solve the problem on task number of tasks*/
void solve(const int tasks);

double measure_execution_time(const int tasks);

/*Process the iutput*/
void process_output(const double time_spent, const int quiet, const char * output_file);

/*Allocate memory for a matrix with dimension (m, n) */
int* init_mat(const int n, const int m);

/*Allocate memory for a matrix with dimension (m, n) */
int* init_mat_with_random_nums(const int m, const int n, const int range);

/*Print a matrix with dimension (m, n) */
void print_mat(int* mat, const int m, const int n);

/*Print a matrix with dimension (m, n) to a output_file*/
void print_mat_to_file(const char* output_file, int* M, const int m, const int n);

/*Calculate matrix portion*/
void* calculate_mat_portion(void* parameters);

/*Generate a random number*/
int random_number(const int limit);

static error_t parse_opt (int key, char *arg, struct argp_state *state);

/* argp parser. */
static struct argp argp = { options, parse_opt, 0, doc };

main (int argc, char **argv)
{
    /*Default values*/
    struct arguments arguments;
    arguments.m = 0;
    arguments.n = 0;
    arguments.k = 0;
    arguments.output_file = 0;
    arguments.input_file = 0;
    arguments.tasks = 1;
    arguments.range = INT_MAX;
    arguments.quiet = 0;

    /* Parse the arguments; every option seen by parse_opt will
  be reflected in arguments. */
    argp_parse (&argp, argc, argv, 0, 0, &arguments);

    double time_spent;
    if(arguments.m || arguments.n || arguments.k)
    {
        srand(time(0));

        if(arguments.m == 0)
            m = 1024;
        else
            m = arguments.m;


        if(arguments.n == 0)
            n = 512;

        else
            n = arguments.n;


        if(arguments.k == 0)
            k = 512;

        else
            k = arguments.k;


        a = init_mat_with_random_nums(arguments.m, arguments.n, arguments.range);
        b = init_mat_with_random_nums(arguments.n, arguments.k, arguments.range);
        time_spent = measure_execution_time(arguments.tasks);
    }
    else if(arguments.input_file)
    {
        FILE* ifp, *ofp;
        ifp = fopen (arguments.input_file, "r");
        fscanf (ifp, "%d", &m);
        fscanf (ifp, "%d", &n);
        fscanf (ifp, "%d", &k);

        int i, j;

        a = init_mat(m, n);
        b = init_mat(n, k);

        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                fscanf(ifp, "%d", &a[i * n + j]);
            }
        }

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < k; j++)
            {
                fscanf (ifp, "%d", &b[i * k + j]);
            }
        }
        time_spent = measure_execution_time(arguments.tasks);
    }
    process_output(time_spent, arguments.quiet, arguments.output_file);
    exit(0);
}


double measure_execution_time(const int tasks)
{
    clock_t begin, end;
    double time_spent;
    begin = clock();
    solve(tasks);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    return time_spent;
}

struct matrix_portion_bounds* get_matrix_portion_bounds(int m, int n, int tasks)
{
    int cells = m * n;
    int cells_per_thread = cells / tasks;
    int remainder_cells = cells % tasks;

    int pos = 0;
    int i;
    struct matrix_portion_bounds* threads_args = malloc(sizeof(struct matrix_portion_bounds) * tasks);

    for( i = 0; i < tasks; i++)
    {
        if(i < remainder_cells)
        {
            threads_args[i].from = pos;
            threads_args[i].to = pos + cells_per_thread + 1;
            pos = pos + cells_per_thread + 1;
        }
        else
        {
            threads_args[i].from = pos;
            threads_args[i].to = pos + cells_per_thread;
            pos = pos + cells_per_thread;
        }
    }
    return threads_args;
}


void solve(const int tasks)
{
    c = init_mat(m, k);

    pthread_t* thread_ids = malloc(sizeof(pthread_t) * tasks);
    struct matrix_portion_bounds* matrix_portion_bounds = get_matrix_portion_bounds(m, k, tasks);

    int i;
    for(i = 0; i < tasks; i++)
    {
        pthread_create(&thread_ids[i], NULL, &calculate_mat_portion, &matrix_portion_bounds[i]);
    }

    for(i = 0; i < tasks; i++)
    {
        pthread_join(thread_ids[i], NULL);
    }
    free(thread_ids);
    free(matrix_portion_bounds);
}

void* calculate_mat_portion(void* parameters)
{
    struct matrix_portion_bounds* p = (struct matrix_portion_bounds*) parameters;
    int i, j;
    for(i = p->from; i < p->to; i++)
    {
        int row = i / k;
        int col = i % k;
        c[row * k + col] =  0;
        for (j = 0; j < n; j++)
        {
            c[row * k + col] += a[row * n + j] * b[j * k + col];
        }
    }
}

void process_output(const double time_spent, const int quiet, const char * output_file)
{
    printf("%f\n", time_spent);
    if(quiet)
    {
        return;
    }

    if(output_file)
    {
        print_mat_to_file(output_file, c, m, k);
    }
    else
    {
        print_mat(c, m, k);
    }
}

static error_t parse_opt (int key, char *arg, struct argp_state *state)
{
    /* Get the input argument from argp_parse, which we
  know is a pointer to our arguments structure. */
    struct arguments *arguments = state->input;

    switch (key)
    {
    case 'm':
        arguments->m = arg ? atoi (arg) : 0;
        break;
    case 'n':
        arguments->n = arg ? atoi (arg) : 0;
        break;
    case 'k':
        arguments->k = arg ? atoi (arg) : 0;
        break;
    case 't':
        arguments->tasks = arg ? atoi (arg) : 1;
        break;
    case 'r':
        arguments->range = arg ? atoi (arg) : INT_MAX;
        break;
    case 'i':
        arguments->input_file = arg;
        break;
    case 'o':
        arguments->output_file = arg;
        break;
    case 'q': case 's':
        arguments->quiet = 1;
        break;
    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

int random_number(const int limit) {
    int divisor = RAND_MAX/(2*limit+1);
    int val;
    do {
        val = rand() / divisor;
    } while (val > 2*limit);
    return val - limit;
}

int* init_mat(const int m,const int n)
{
    int *arr = (int *)malloc(m * n * sizeof(int));
    return arr;
}

int* init_mat_with_random_nums(int m, int n, int range)
{
    int i, j;
    int *arr = (int *)malloc(m * n * sizeof(int));
    for(i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            arr[i*n + j] = random_number(range);;
        }
    }
    return arr;
}

void print_mat(int* mat, const int m, const int n)
{
    int i, j;
    for(i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", mat[i * n + j]);
        }
        printf("\n");
    }
}

void print_mat_to_file(const char* output_file_name, int* mat, const int m, const int n)
{
    FILE *fp;
    fp = fopen(output_file_name, "w+");
    fprintf(fp, "%d %d\n", m, n);
    int i, j;
    for(i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            fprintf(fp, "%d ", mat[i * n + j]);
        }
        fprintf(fp, "\n");
    }
}
