// #include <stdlib.h>
// #include <R.h>
// #include <Rinternals.h>

void swap(int *arr, int a, int b){
  int x = arr[a];
  arr[a] = arr[b];
  arr[b] = x;
}

int equals(double a, double b, double c, double d){
  if(a!=b || b!=c || c!=d)
    return 0;
  return 1;
}

double max(double a, double b, double c){
  if(a>b){
    if(a>c)
      return a;
    if(c>a)
      return c;
  }
  if(b>c)
    return b;
  return c;
}

double med(double a, double b, double c){
  if(a>b){
    if(a>c){
      if(b>c)
        return b;
      return c;
    }
    return a;
  }
  if(b>c){
    if(a>c)
      return a;
    return c;
  }
  return b;
}

void perm_unoptimized(int arr[], int n, int k, double *perm_arr, int *sum) {
  int i;
  int max_pom;
  int med_pom;

  if(k == n){
    max_pom = max(perm_arr[arr[1]-1],perm_arr[arr[2]-1],perm_arr[arr[3]-1]) < perm_arr[arr[4]-1] ? 1 : 0;
    med_pom = perm_arr[arr[0]-1] + med(perm_arr[arr[1]-1],perm_arr[arr[2]-1],perm_arr[arr[3]-1]) < perm_arr[arr[4]-1] ? 1 : 0;

    *sum += max_pom - med_pom;
  }
  else
    for (i=k; i<n; i++) {
      swap(arr, k, i);
      perm_unoptimized(arr, n, k+1, perm_arr, sum);
      swap(arr, k, i);
    }
}

int optimize_comb (int a, int b, int c, int d, int e, int *skip_perm, double *params) {
  int povratna = 120;
  int new[] = {0,0,0,0,0};
  int niz[] = {a,b,c,d,e};

  int i;
  for (i=0;i<5;i++) {
    if (niz[i]==a)
      new[0]+=1;
    if (niz[i]==b)
      new[1]+=1;
    if (niz[i]==c)
      new[2]+=1;
    if (niz[i]==d)
      new[3]+=1;
    if (niz[i]==e)
      new[4]+=1;
  }
  // ako ima 5 istih
  // vrati nulu, stara optimizacija
  int max=0;
  int max_pos=0;
  for(i=0;i<5;i++){
    if(new[i]>max){
      max = new[i];
      max_pos = i;
    }
  }

  if(max==5){
    *skip_perm = 1;
    return 0;
  }

  int once;
  if(max==4){
    for(i=0;i<5;i++){
      if(niz[i]!=niz[max_pos]){
        once = i;
        break;
      }
    }
    if(params[niz[once]] < params[niz[max_pos]]){//4 ista, peti manji
      *skip_perm = 1;
      return 0;
    }
    return 5;
  }

  if(max==3){
    povratna/=6;
    int br = 1;
    int old = -1; // HACK, eksponencijalna vraca pozitivne vrednosti
    for(i=0;i<5;i++){
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

  if(max==2){
    povratna/=2;
    int br = 1;
    int old = -1; // HACK, eksponencijalna vraca pozitivne vrednosti
    for(i=0;i<5;i++){
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

  return 120;
}

void perm(double perm_arr[], int *sum, int comb) {
  int n=5;
  int i,j,k,l;

  int counter;
  int max_pom;
  int med_pom;
  //med_max_arr racunamo med i max, a gen_1 i gen_2 su izgenerisani brojevi u odnosu na koje racunamo
  double med_max_arr[3],gen_1,gen_2;

  for (i=0;i<n;i++) {
    gen_1=perm_arr[i];
    for (j=i+1;j<n;j++) {
      gen_2=perm_arr[j];

      counter=0;
      for (k=0;k<n;k++) {
        if (k==i || k==j){
          continue;
        }
        med_max_arr[counter]=perm_arr[k];
        counter++;
      }

      double maxD = max(med_max_arr[0],med_max_arr[1],med_max_arr[2]);
      double medD = med(med_max_arr[0],med_max_arr[1],med_max_arr[2]);

      max_pom = maxD < gen_1 ? comb*6 : 0;
      med_pom = gen_2 + medD  < gen_1 ? comb*6 : 0;
      *sum += max_pom - med_pom;

      max_pom = maxD < gen_2 ? comb*6 : 0;
      med_pom = gen_1 + medD < gen_2 ? comb*6 : 0;
      *sum += max_pom - med_pom;
    }
  }
}


void funkcija(int *input_n, double* params, double *summ_out) {
  int perm_arr_helper[5];
  double perm_arr[5];
  int n = input_n[0];

  int i,j,k,l,m;
  // int ii; unoptimized
  int sum = 0;
  for (i=0; i<n; i++) {
    for (j=i; j<n; j++) {
      for (k=j; k<n; k++) {
        for (l=k; l<n; l++) {
          for (m=l; m<n; m++) {

            // optimizacija za 4 jednaka i 5. manji, i za pet jednakih
            // suma im je nula u tom slucaju
            // if(
            // (equals(j,k,l,m) && params[j]>=params[i]) ||
            // (equals(i,k,l,m) && params[k]>=params[j]) ||
            // (equals(i,j,l,m) && params[l]>=params[k]) ||
            // (equals(i,j,k,m) && params[m]>=params[l]) ||
            // (equals(i,j,k,l) && params[i]>=params[m]))
            //   continue;

            int skip_perm=0;
            int comb = optimize_comb(i,j,k,l,m,&skip_perm,params);

            if(!skip_perm){
              perm_arr[0] = params[i];
              perm_arr[1] = params[j];
              perm_arr[2] = params[k];
              perm_arr[3] = params[l];
              perm_arr[4] = params[m];

              // unoptimized
              // for(ii=0;ii<5;ii++){
              //   perm_arr_helper[ii] = ii+1;
              // }
              // perm_unoptimized(perm_arr_helper,5,0,perm_arr,&sum);
              perm(perm_arr,&sum,comb);
            }
          }
        }
      }
    }
  }
   *summ_out = (double)sum/(120*n*n*n*n*n);
}
