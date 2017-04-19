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
	double r, error = 0;
	FILE *graf;
	graf = fopen("graf4.dat", "w");

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
		error += (nleft - N/2)*(nleft - N/2);
		fprintf(graf, "%d\t %d\n", t, nleft - N/2); /*to plot in gnuplot use this command: plot 'graf4.dat' u 1:2 w l, '' u 1:3 w l*/
		}
	}
	printf("%f\n", sqrt(error/(85000))/3600);
	return 0;
}
