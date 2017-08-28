#include<stdio.h>
#include <mpi.h>
int main(int argc, char** argv) 
{
int size, node;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size);
printf("Hello from node %d / %d nodes\n", node,(size-1));
MPI_Finalize();
return 0;

}

