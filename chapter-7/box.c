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
	graf = fopen("graf.dat", "w");

	srand(time(NULL));
	while (nleft != N/2){
		r = rand()*1.0/RAND_MAX;
		if (r <= nleft*1.0/N){
			nleft--;
		}
		else {
			nleft++;
		}
		t++;
		fprintf(graf, "%d\t %d\t %d\n", t, nleft, N-nleft); /*to plot in gnuplot use this command: plot 'graf.dat' u 1:2 w l, '' u 1:3 w l*/
	}
	return 0;
}
