#include<stdio.h>
#include <mpi.h>
int main(int argc, char** argv) 
{
int size, node,i,sum=0, n1=0;
MPI_Status status;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size);
int a[]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
int g= sizeof(a)/sizeof(a[1]);
for(i=node; i< g; i++)
{
sum=sum+a[i];
}
printf("Node has sum %d of %d\n", node,sum);
MPI_Reduce(&sum,&n1,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
if(node==0)
printf("Total sum %d  %d\n", node,n1);
MPI_Finalize();
return 0;
}

