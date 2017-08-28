#include <stdio.h>
#include <iostream>
#include <mpi.h>
using namespace std;
int main(int argc, char** argv) 
{
int size, node,i,sum=0, n1=0;
MPI_Status status;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size);
int a[]= {23,32,0,2,45,67,90,76,212};
int g= sizeof(a)/sizeof(a[1]);
int b[g];
int rank=0;
for(int x=0;x<g;x++)
{
	rank=0;
	for(int y=0;y<g;y++)
	if(a[x]>a[y])
		rank++;
	b[rank]=a[x];

}
for(i=0; i< g; i=i++)
{
cout<<"Node has Sum "<<b[i]<<endl;
}

MPI_Finalize();
return 0;
}

