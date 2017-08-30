#include <stdio.h>
#include <omp.h>

static long num_steps = 100000;
double step;

int main () 
{ 
	long num_threads = omp_get_num_threads();
 	double sum[num_threads];
 	double pi;
 	
	#pragma omp parallel
 	{
 		int i; 
 		double x;
 		long threadno = omp_get_thread_num();
 		long range = num_steps / num_threads; 
 		long min_range = threadno*range;
 		long max_range = (threadno+1) * range;
 		sum[threadno] = 0;

		step = 1.0/(double) num_steps;
 		for (i=0;i< num_steps; i++){
	 		x = (i+0.5)*step;
	 		sum[threadno] = sum[threadno] + 4.0/(1.0+x*x);
 		}
 		sum[threadno] = step * sum[threadno];
 	}

 	for(int i=0, pi=0.0; i<num_threads; i++)
 		pi += sum[i];
 	printf("%lf\n", pi);
}