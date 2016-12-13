// #include <stdlib.h>
// #include <R.h>
// #include <Rinternals.h>

#define MAX(a,b,c) c
#define MED(a,b,c) b

int optimize_comb (int a, int b, int c, int d, double *params) {
  int povratna = 24;
  int new[] = {0,0,0,0};
  int niz[] = {a,b,c,d};

  int i;
  for (i=0;i<4;i++) {
    if (niz[i]==a)
      new[0]+=1;
    if (niz[i]==b)
      new[1]+=1;
    if (niz[i]==c)
      new[2]+=1;
    if (niz[i]==d)
      new[3]+=1;
  }

  // ako ima 5 istih
  // vrati nulu, stara optimizacija
  int max=0;
  int max_pos=0;
  for(i=0;i<4;i++){
    if(new[i]>max){
      max = new[i];
      max_pos = i;
    }
  }

  if(max==4){
    return 1;
  }

  if(max==3){
    return 4;
  }

  if(max==2){
    povratna/=2;
    int br = 1;
    int old = -1; // HACK, indeksi su pa vraca pozitivne vrednosti
    for(i=0;i<4;i++){
      if(niz[i] != niz[max_pos]){
        if(old == niz[i]){
          br++;
        }
        old = niz[i];
      }
    }
    if(br == 2)
      povratna/=2;
    return povratna;
  }

  return 24;
}

void perm(double perm_arr[], int *sum, int comb, double t) {
  int n=4;
  int i,k,l;

  int counter;
  int max_pom;
  int med_pom;
  //med_max_arr racunamo med i max, a gen_1 je izgenerisani brojevi u odnosu na koje racunamo
  double med_max_arr[3],gen_1;

  for (i=0;i<n;i++) {
    gen_1=perm_arr[i];

    counter=0;
    for (k=0;k<n;k++) {
      if (k==i){
        continue;
      }
      med_max_arr[counter]=perm_arr[k];
      counter++;
    }

    double maxD = MAX(med_max_arr[0],med_max_arr[1],med_max_arr[2]);
    double medD = MED(med_max_arr[0],med_max_arr[1],med_max_arr[2]);

    // Rprintf("%.2f\n",gen_1);

    // max_pom = maxD < gen_1 ? comb*6 : 0;
    // med_pom = t + medD  < gen_1 ? comb*6 : 0;
    // *sum += max_pom - med_pom;
    max_pom = maxD < t ? comb*6 : 0;
    med_pom = gen_1 + medD < t ? comb*6 : 0;
    *sum += max_pom - med_pom;
  }
}


void funkcija(int *input_n, double* params, double *summ_out, double *input_t) {
  int perm_arr_helper[4];
  double perm_arr[4];
  int n = input_n[0];
  double t = input_t[0];

  int i,j,k,l;

  int sum = 0;
  for (i=0; i<n; i++) {
    for (j=i; j<n; j++) {
      for (k=j; k<n; k++) {
        for (l=k; l<n; l++) {
          int comb = optimize_comb(i,j,k,l,params);
          perm_arr[0] = params[i];
          perm_arr[1] = params[j];
          perm_arr[2] = params[k];
          perm_arr[3] = params[l];
          perm(perm_arr,&sum,comb,t);
          // Rprintf("%d\n",sum);
        }
      }
    }
  }
  *summ_out = (double)sum/(24*n*n*n*n);
}
