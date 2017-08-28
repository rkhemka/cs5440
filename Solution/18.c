#include <mpi.h>
#include<stdio.h>
int main(int argc, char** argv)
{
int size, node,a;
MPI_Status status;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size);
 if(node == 0)
     scanf("Enter a value fir A %d ", &a);
 MPI_Bcast(&a, 1, MPI_INT, 0, MPI_COMM_WORLD);
 printf("Node %d has %d in value. \n", node,a);
}