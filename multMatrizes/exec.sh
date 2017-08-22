gcc -o mat multMatrix.c
./mat

sudo apt-get install linux-tools-common
sudo apt-get install linux-tools-generic
sudo apt-get install linux-tools-4.4.0.83-generic

# como usar o comando perf
perf list

# calcula a quantidade de Cache misses do programa
perf record -e LLC-load-misses ./mat
perf report -v

# Procurar STRIDE
