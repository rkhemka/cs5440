#include<stdio.h>
#include <mpi.h>
#include<iostream>
using namespace std;
int main(int argc, char** argv) 
{
int size, node,i;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size);
for(i=node; i< size; i++){
cout<<node<<” “ <<i<<” <<endl;
}
MPI_Finalize();
return 0;
}
