#include <stdio.h>
#include <omp.h>


static long num_steps = 100000;
static double step;
#define NUM_THREADS 8


int main ()
{
	int i, nthreads; double pi, sum[NUM_THREADS];
	step = 1.0/(double) num_steps;
	omp_set_num_threads(NUM_THREADS);

	#pragma omp parallel
 	{ // fork
		int i, id, nthrds;
		double x;
		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		if (id == 0) nthreads = nthrds;
		for (i=id, sum[id]=0.0;i< num_steps; i=i+nthrds) {
			x = (i+0.5)*step;
			sum[id] += 4.0/(1.0+x*x); // False Sharing nessa linha.
			// Toda vez que uma thread alterar um valor do vetor, a flag "alterada"
			// na cache será passada para true, de forma que a thread seguinte terá
			// de recarregar todo o vetor novamente, mesmo que a célula que vai mexer
			// não tenha propriamente uma alteração.
		}

	} // join

	for(i=0, pi=0.0;i<nthreads;i++)
		pi += sum[i] * step;

 	printf("%lf\n", pi);
 	return 0;
}
