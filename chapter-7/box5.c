#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define pi M_PI
#define inf INFINIT
#define N 800

int main(void)
{
	int nleft = N, t = 0;
	double r, error_bar, error = 0, sigma;
	FILE *graf;
	graf = fopen("graf5.dat", "w");

	srand(time(NULL));
	while (t < 100000){
		r = rand()*1.0/RAND_MAX;
		if (r <= 0.5 & nleft > 0){
			nleft--;
		}
		else if (r >= .5 & (N - nleft) > 0){
			nleft++;
		}
		t++;
		fprintf(graf, "%d\t %d\t %d\n", t, nleft, N - nleft); /*to plot in gnuplot use this command: plot 'graf5.dat' u 1:2 w l, '' u 1:3 w l*/
		
	}
	return 0;
}
