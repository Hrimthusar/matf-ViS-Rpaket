#include <stdlib.h>

void swap(int *arr, int a, int b){
  int x = arr[a];
  arr[a] = arr[b];
  arr[b] = x;
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
}

// Druga varijanta (u ovoj varijanti permutacije nisu poredane leksikografski):
void perm(int arr[], int n, int k, double *perm_arr, int *sum) {
  int i;
  int max_pom;
  int med_pom;

  if(k == n){
    // printf("(%i %i %i %i %i)\n",arr[0], arr[1], arr[2], arr[3], arr[4]);
    // printf("(%f %f %f %f %f)\n",perm_arr[arr[0]], perm_arr[arr[1]], perm_arr[arr[2]], perm_arr[arr[3]], perm_arr[arr[4]]);
    // -1 u arr[x], zato sto se u c-u broji od 0
    max_pom = max(perm_arr[arr[1]],perm_arr[arr[2]],perm_arr[arr[3]]) < perm_arr[arr[4]] ? 1 : 0;
    med_pom = perm_arr[arr[0]] + med(perm_arr[arr[1]],perm_arr[arr[2]],perm_arr[arr[3]]) < perm_arr[arr[4]] ? 1 : 0;

    *sum += max_pom - med_pom;
  }
  else
    for (i=k; i<n; i++) {
      swap(arr, k, i);
      perm(arr, n, k+1, perm_arr, sum);
      swap(arr, k, i);
    }
}


void funkcija(int *input_n, double* params, double *summ_out) {
  // ZA PERMUTACIJE
  int* perm_arr_helper = (int*) malloc(5*sizeof(int)); // da li je 120?
  double* perm_arr = (double*) malloc(5*sizeof(double)); // da li je 120?


  int n=input_n[0];

   int i,j,k,l,m,ii;
   int sum = 0;

for (i=0; i<n; i++) {
  perm_arr[0] = params[i];
  for (j=0; j<n; j++) {
    perm_arr[1] = params[j];
    for (k=0; k<n; k++) {
      perm_arr[2] = params[k];
      for (l=0; l<n; l++) {
        perm_arr[3] = params[l];
        for (m=0; m<n; m++) {
          perm_arr[4] = params[m];
          // optimizacija za 4 jednaka i 5. manji, i za pet jednakih
          // suma im je nula u tom slucaju
          if((j==k==l==m && params[j]<=params[i]) ||
          (i==k==l==m && params[k]<=params[j]) ||
          (i==j==l==m && params[l]<=params[k]) ||
          (i==j==k==m && params[m]<=params[l]) ||
          (i==j==k==l && params[i]<=params[m]))
            continue;

          for(ii=0;ii<5;ii++){
            perm_arr_helper[ii] = ii+1;
          }
          perm(perm_arr_helper,5,0,perm_arr,&sum);
        }
      }
    }
  }
}

   // ZA PERMUTACIJE
   free(perm_arr);

   *summ_out = (double)sum/(120*n*n*n*n*n);
}
