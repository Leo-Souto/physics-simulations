#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define pi M_PI
#define inf INFINITY
#define N 7200


int main(void)
{
	int nleft = N, t = 0;
	double r;
	FILE *graf;
	graf = fopen("graf3.dat", "w");

	srand(time(NULL));
	while (t < 100000){
		r = rand()*1.0/RAND_MAX;
		if (r <= nleft*1.0/N){
			nleft--;
		}
		else {
			nleft++;
		}
		t++;
		if (t > 15000){
		fprintf(graf, "%d\t %d\n", t, nleft - N/2); /*to plot in gnuplot use this command: plot 'graf.dat' u 1:2 w lp*/
		}
	}
	return 0;
}
