#include <stdio.h>
#include <iostream>
#include <mpi.h>
using namespace std;
int main(int argc, char** argv) 
{
int size, node;
MPI_Status status;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size);
double sum=0, v=0, r, sum1=0;
cout<<"node: "<<node<<endl;
for (int i = 0; i < 1/0.02; i=i+size)
{
	r=0.02*i;
	sum1=(1/(1+(r*r)));
	v=v+sum1;
	cout<<"Value of X: "<<r<<" "<<sum1<<endl;
}
cout<<"Node "<<node<<" has Sum"<<v<<endl;
MPI_Reduce(&v,&sum,1,MPI_Double,MPI_Sum,0,MPI_COMM_WORLD);
if(node==0)
cout<<"Total Sum = "<<sum<<endl;
MPI_Finalize();
return 0;
}	