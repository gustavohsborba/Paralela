#include <stdio.h>
#include <omp.h> // necessário para omp_get_thread_num

int main()
{
	// a diretiva #pragma precisa das chaves para executar mais de uma instrução simultaneamente
	// Essa diretiva não precisa do include "omp.h" 
	#pragma omp parallel
	{ // aqui há um fork		
		int ID = omp_get_thread_num(); // pega o RANK da thread
		printf("hello(%d) ", ID);
		printf("world(%d) \n", ID);
	} // e aqui há um join
}