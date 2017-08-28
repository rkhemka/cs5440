#include <mpi.h>
#include<stdio.h>
int main(int argc, char** argv)
{
int size, node;
MPI_Status status;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size);
int a=0, b=0, value=100;
float sum=0;

if(node==0)
MPI_Recv(&value, 1, MPI_INT, 9, 0, MPI_COMM_WORLD,&status);
else if(node==1)
MPI_Recv(&value, 1, MPI_INT, 9, 0, MPI_COMM_WORLD,&status);
else if(node==2)
MPI_Recv(&value, 1, MPI_INT, 9, 0, MPI_COMM_WORLD,&status);
else if(node==3)
MPI_Recv(&value, 1, MPI_INT, 9, 0, MPI_COMM_WORLD,&status);
else if(node==4)
MPI_Recv(&value, 1, MPI_INT, 9, 0, MPI_COMM_WORLD,&status);
else if(node==5)
MPI_Recv(&value, 1, MPI_INT, 9, 0, MPI_COMM_WORLD,&status);
else if(node==6)
MPI_Recv(&value, 1, MPI_INT, 9, 0, MPI_COMM_WORLD,&status);
else if(node==7)
MPI_Recv(&value, 1, MPI_INT, 9, 0, MPI_COMM_WORLD,&status);
else if(node==8)
MPI_Recv(&value, 1, MPI_INT, 9, 0, MPI_COMM_WORLD,&status);
else if(node==9)
{
value=200;
MPI_Send(&value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
MPI_Send(&value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
MPI_Send(&value, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
MPI_Send(&value, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
MPI_Send(&value, 1, MPI_INT, 4, 0, MPI_COMM_WORLD);
MPI_Send(&value, 1, MPI_INT, 5, 0, MPI_COMM_WORLD);
MPI_Send(&value, 1, MPI_INT, 6, 0, MPI_COMM_WORLD);
MPI_Send(&value, 1, MPI_INT, 7, 0, MPI_COMM_WORLD);
MPI_Send(&value, 1, MPI_INT, 8, 0, MPI_COMM_WORLD);
}
printf("Node %d has %d in value. \n", node,value);
MPI_Finalize();
}