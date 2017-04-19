#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define pi M_PI
#define inf INFINITY


int main(void)
{
	int nleft, N, t;
	double r;
	FILE *graf;
	graf = fopen("graf2.dat", "w");

	srand(time(NULL));
	for (N = 8; N <=10000000; N = N*2){
		nleft = N;
		t = 0;
		while (nleft != N/2){
			r = rand()*1.0/RAND_MAX;
			if (r <= nleft*1.0/N){
				nleft--;
			}
			else {
				nleft++;
			}
			t++;
		}
		fprintf(graf, "%d\t %d\n", N, t); /*to plot in gnuplot use this command: plot 'graf2.dat' u 1:2 w l*/
	}
	return 0;
}
