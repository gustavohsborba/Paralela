#!/bin/bash

more /proc/cpuinfo
# Verifica quantos núcleos tem seu computador.
# siblings: 4
# cpu cores : 2
# Significa que há 4 hiperthreads em 2 processadores


# Para compilar com o OpenMPI, é necessário adicionar -fopenmp no g++
g++ helloWorldMP.c -fopenmp -o hello
./hello # executará 4 threads

# Executará várias threads, eventualmente ficará bagunçado devido ao escalonamento
OMP_NUM_THREADS=16 ./hello

# Para que fique fixo no terminal:
EXPORT OMP_NUM_THREADS=16

# Cálculo de PI serial:
g++ serial_pi.c -o pi
./pi

# Cálculo de PI paralelo:
g++ paralell_pi.c -fopenmp -o pi
./pi

# Cálculo de PI paralelo - Solução SPMD = Single Program Multiple Data
g++ paralell_pi_spmd.c -fopenmp -o pi
./pi

# Solução do falso compartilhamento
# Pesquisar False Sharing e linha de cache
g++ paralell_pi_spmd_no_false_sharing.c -fopenmp -o pi
./pi
