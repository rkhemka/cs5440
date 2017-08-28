#include <mpi.h>
#include<stdio.h>
int main(int argc, char** argv)
{
int size, node;
MPI_Status status;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size);

printf("Node %d has %d in a and %d in b. \n", node,a,b);
 MPI_Finalize();
}