#include <stdio.h>
#include <iostream>
#include <mpi.h>
#include <math.h>
using namespace std;
int main(int argc, char** argv) 
{
int size, node;
MPI_Status status;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size);
double v=0, r=2,sum=0,sum1=0;
for (double i=0;i<=100;i++)
{
	sum1= pow(r,i);
	sum=sum1/fact1(i);
	v=v+sum;
	cout<<" "<<i<<"has Value"<<sum<<""<<endl;

}
cout<<"Total Value is " <<v<<endl;
MPI_Finalize();
return 0;
}
double fact1(double x){
	double fact=1;
	while(x>=1){
		fact=fact*x;
		x--;
	}
	return fact;
}