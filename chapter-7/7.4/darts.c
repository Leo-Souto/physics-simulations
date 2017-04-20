#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define pi M_PI
#define inf INFINIT
#define N 1000
#define n 100

int factorial(int x){
	int factorial = 1, i;
	for (i=1; i <= x; i++){
		factorial *= i;
	}
	return factorial;
}



int main(void){
	double H_n[n+1] = {0}, B[N] = {0}, P_n[n+1] = {0}, soma = 0, avg = 0;
	int i, k, r, j;
	FILE *graf, *graf2;

	graf = fopen("graf6.dat", "w");
	graf2 = fopen("graf7.dat", "w");

	srand(time(NULL));
	for (i = 0; i< 1000; i++){

		for(j = 0; j < n; j++){
			r = (int) floor(rand()*1.0*N/RAND_MAX);
			B[r]++;
		}
		for (k = 0; k <= n; k++){
			for (j = 0; j < N; j++){
				if (B[j] == k){
					H_n[k]++;
				}
			}
		}
		for (j = 0; j < N; j++){
				B[j] = 0;
			}
					

	}
	for (j = 0; j < n; j++){
		soma += H_n[j];
	}
	for(j = 0; j<= n; j++){
		P_n[j] = H_n[j]*1.0/soma;
		avg += j*P_n[j];
	}
	for (j = 0; j< n/10; j++){
		fprintf(graf, "%d\t %f\n",j, P_n[j] );
		fprintf(graf2, "%d\t %f\n",j, pow(avg, j)*1.0/factorial(j)*exp(-avg) );
	}
	fclose(graf);
	fclose(graf2);
	system("gnuplot -persist plot.gnu");
	return 0;
}
