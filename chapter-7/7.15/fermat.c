#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define pi M_PI
#define inf INFINITY
#define N 10

double change_path(int x, double y[N], double v[N]){
double delta = 0.25, y_trial, dy2, dist, t_init, t_trial;
y_trial = y[x] + (2*rand()*1.0/RAND_MAX)*delta;
dy2 = pow(y[x]-y[x+1],2);
dist = sqrt(1 + dy2);
t_init = dist/v[x+1];
dy2 = pow(y[x]-y[x-1],2);
dist = sqrt(1 + dy2);
t_init += dist/v[x];
dy2 = pow(y_trial - y[x+1],2);
dist = sqrt(1 + dy2);
t_trial = dist/v[x+1];
dy2 = pow(y_trial - y[x-1],2);
dist = sqrt(1 + dy2);
t_trial += dist/v[x];


if (t_trial < t_init)
	return y_trial;
else
	return y[x];

}

int main(void){
	double v1, index = 1.0, index2 = 1.5, v2, v[N], y[N], rnd, y2[N], t_final = 0, dy2, dist;
	int i,j,k;
	FILE *graf;

	srand(time(NULL));
	graf = fopen("fermat.dat", "w");
	v1 = 1.0/index;
	v2 = 1.0/index2;
	y[0] = y2[0] = 2.0;	
	y[N-1] = y2[N-1] = 8.0;

	for( i = 0; i < N/2; i++)
		v[i] = v1;
	for( i = N/2; i < N; i++)
		v[i] = v2;
	for(i = 1; i < N-1; i++)
		y[i] = y2[i] = (y[N-1] - y[1])*rand()*1.0/RAND_MAX + y[0];

	for (j = 0; j < 100000; j++){
		rnd = rand()*1.0/RAND_MAX;
		i = (N-2)*rnd + 1;

		y[i] = change_path(i, y, v);

	}

	for (i = 0 ; i < N; i++){
		fprintf(graf, "%d\t %f\t %f\n", i+1, y2[i], y[i]);
	}
	for (i = 1; i < N; i++){
		dy2 = pow(y[i] - y[i-1], 2);
		dist = sqrt(i + dy2);
		t_final += dist/v[i-1];
	}
	fclose(graf);
	printf("theta1 = %f radians\ntheta2 = %f radians\ny = %f\ntotal time = %f\n", atan(y[4]- y[3]), atan(y[5]-y[4]), y[4], t_final);

	return 0;
}
