#include<stdio.h>
#include <mpi.h>
int main(int argc, char** argv)
{
int size, node;
MPI_Status status;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size);
int a=0, b=0, sum=0, value=100;
if(node == 1){
MPI_Recv(&a, 1, MPI_FLOAT, 9, 0, MPI_COMM_WORLD,&status);
b=3+4;
MPI_Send(&b, 1, MPI_FLOAT, 9, 0, MPI_COMM_WORLD);

}else
if(node == 9)
{
a=1+2;
MPI_Bcast(&value, 1, MPI_FLOAT, 9, MPI_COMM_WORLD);

MPI_Recv(&b, 1, MPI_FLOAT, 1, 0, MPI_COMM_WORLD,&status);

sum= a+b+value;

}
printf("The sum is %d ",sum);
MPI_Finalize();
}