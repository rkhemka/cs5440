#include <mpi.h>
#include<stdio.h>
int main(int argc, char** argv)
{
int size, node,x;
MPI_Status status;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size);
int a=0, b=0,s=98, sum=0, value=0;


if(node==9)
{

for(x=0;x<=8;x++){
MPI_Send(&value, 1, MPI_INT, x, 0, MPI_COMM_WORLD);
}
}
MPI_Recv(&value, 1, MPI_INT, 9, 0, MPI_COMM_WORLD,&status);

if(node%2 == 1)
{	
sum=value+5;
}
else if(node>0 && (node%2==0))
{
value+=10;
}


if(node==0)
    {
        printf("sum1 = %d \n",gs[0]);
        printf("sum2 = %d \n",gs[1]);
    }



MPI_Finalize();
}