#include<stdio.h>
#include <mpi.h>
int main(int argc, char** argv)
{
int size, node;
MPI_Status status;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size);
int a=0, b=0, value=100;
float sum=0;
if(node == 1){
MPI_Recv(&value, 1, MPI_FLOAT, 9, 0, MPI_COMM_WORLD,&status);
b=10.8+value;
MPI_Recv(&a, 1, MPI_INT, 9, 0, MPI_COMM_WORLD,&status);
MPI_Send(&b, 1, MPI_FLOAT, 9, 0, MPI_COMM_WORLD);

}else if(node == 9)
{
MPI_Bcast(&value, 1, MPI_FLOAT, 9, MPI_COMM_WORLD);
a=9;
MPI_Send(&a, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);	
 
MPI_Recv(&b, 1, MPI_FLOAT, 1, 0, MPI_COMM_WORLD,&status);
sum= 25.5;
}
printf("The sum is %f ",sum);
printf("Node %d has %d in value. \n", node,value);
MPI_Finalize();
}