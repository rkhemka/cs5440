#include <iostream>
#include <mpi.h>
using namespace std;
int main(int argc, char** argv) 
{
 int size, node, value1=1, value2=2; 
 MPI_Status status;
 MPI_Init(&argc, &argv); 
 MPI_Comm_rank(MPI_COMM_WORLD, &node); 
 MPI_Comm_size(MPI_COMM_WORLD, &size);
 if(node>0)
  MPI_Recv(&value1, 1, MPI_INT, node-1, 0, MPI_COMM_WORLD, &status);
 cout<<"Hello World"<<" "<<node<<endl;
 if(node<size-1)
  MPI_Send(&value2, 1, MPI_INT, node+1, 0, MPI_COMM_WORLD); 
 MPI_Finalize(); 
 return 0;
}