#include <stdio.h>
#include <iostream>
#include <mpi.h>
using namespace std;
int main(int argc, char** argv) 
{
int size, node,sum=0, n1=0;
MPI_Status status;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size);
int a[]= {23,32,0,2,45,67,90,76,212};
int g= sizeof(a)/sizeof(a[1]);
int rank=0;
for (int i = 0; i < g; i++)
{
	if(a[node]>a[i])
		rank++;
}
if(node!=0)
MPI_Send(&rank,1,MPI_INT,0,0,MPI_COMM_WORLD);
else{
	int b[9];
	b[rank]=a[node];
	for(int x=1;x<g;x++)
	{
		MPI_Recv(&rank,1,MPI_INT,x,0,MPI_COMM_WORLD,&status);
		b[rank]=a[x];
	}
	cout<<"Sorted Array ";
	for (int r = 0; r < g; r++)
	
		cout<<b<<" ";
		
	
}
MPI_Finalize();
return 0;

}