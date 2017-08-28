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
double v=0, r=2,sum=0,sum1=0, t;
for (double i=0;i<=100;i=i+size)
{
	sum1= pow(r,i);
	sum=sum1/fact(i);
	v=v+sum;
	cout<<" "<<i<<"has Value"<<sum<<""<<endl;

}
cout<<"Node has  " <<node<<"value "<<v<<endl;
MPI_Reduce(&v,&t,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
if(node==0)
	cout<<"Total Value is " <<t<<endl;
MPI_Finalize();
return 0;
}
double fact(double x){
	double fact=1;
	while(x>=1){
		fact=fact*x;
		x--;
	}
	return fact;
}