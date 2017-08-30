#include <stdio.h>
#include <omp.h>


static long num_steps = 100000; 
static double step;
#define NUM_THREADS 8


int main ()
{ 
	int i, nthreads; double pi;
	step = 1.0/(double) num_steps;
	omp_set_num_threads(NUM_THREADS);
	
	#pragma omp parallel
 	{
		int i, id, nthrds;
		double x, sum;
		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		if (id == 0) nthreads = nthrds;
		for (i=id, sum=0.0;i< num_steps; i=i+nthrds) {
			x = (i+0.5)*step;
			sum += 4.0/(1.0+x*x);
		}
		
		// A única condição de corrida ocorre aqui.
		// OU seja, só uma linha precisa de sincronização
		// SEÇÃO CRÍTICA: Área do código que só é executada por uma trhead de cada vez.
		#pragma omp critical
 			pi += sum * step; 
	}
	
 	printf("%lf\n", pi);
 	return 0;
}