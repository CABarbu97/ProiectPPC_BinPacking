#include <iostream>
#include <ctime>
#include <mpich/mpi.h>

using namespace std;

// Global variables
int Ace = 1;
int J = 10;
int Q = 10;
int K = 10;
int deck[] = {Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K,
              Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K,
              Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K,
              Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K};

int main(int argc, char *argv[])
{
    int numtasks, rank, len, rc;
    char hostname[MPI_MAX_PROCESSOR_NAME];

    rc = MPI_Init(&argc, &argv);
    if (rc != MPI_SUCCESS)
    {
        printf("Error starting MPI program. Terminating.\n");
        MPI_Abort(MPI_COMM_WORLD, rc);
    }

    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
}
