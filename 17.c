#include <mpi.h>
int main(int argc, char** argv)
{
int size, node;
MPI_Status status;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size);
int a=0, b=0, sum=0, value=100;
if(node == 9)
{
MPI_Bcast(&value, 1, MPI_FLOAT, 9, MPI_COMM_WORLD);

sum= 25.5+value;

}
printf("The sum is %d ",sum);
printf("Node %d has %d in value. \n", node,value);
MPI_Finalize();
}