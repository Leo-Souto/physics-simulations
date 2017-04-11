#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define pi M_PI
#define inf INFINITY



void  Euler(double *x, double *y, double *vx, double *vy, double GM, double dt, double *ratio)
{
  double  dx, dy, dr, dr2, dr3, ax, ay, r, r2, r3;
  int i;
  dx = x[1] - x[0];
  dy = y[1] - y[0];
  dr2 = (dx*dx + dy*dy);
  dr = sqrt(dr2);
  dr3 = dr*dr2;
  for (i= 0; i < 2;i++){
    r2 = x[i]*x[i]+y[i]*y[i];
    r = sqrt(r2);
    r3 = r2*r;
    ax = -GM*x[i]/r3 + ratio[i]*dx/dr3;
    ay = -GM*y[i]/r3 + ratio[i]*dy/dr3;
    vx[i] += ax*dt;
    vy[i] += ay*dt;
    x[i] += vx[i]*dt;
    y[i] += vy[i]*dt;
  }
}



int main(void) {
  double t=0, dt = 0.001, ratio[2];
  FILE *graf;
  double GM = 4*pi*pi, x[2] = {2.52, 5.24};
  double y[2] = {0,0}, vx[2] ={0, 0}, vy[2];
  ratio[0] = 0.04*GM;
  ratio[1] = -0.001*GM;
  vy[0] = sqrt(GM/x[0]);
  vy[1] = sqrt(GM/x[1]);
  graf = fopen("graf.dat", "w");
  for(t = 0; t<= 100; t += dt){
    Euler(x, y, vx, vy, GM, dt, ratio);
    fprintf(graf, "%f\t %f\t %f\t %f\n", x[0], y[0], x[1], y[1]);
  }
  fclose(graf);

  return 0;
}
