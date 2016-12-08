#include <stdio.h>

int proveri_5 (int a, int b, int c, int d, int e) {
  if (a!=b || a!=c || a!=d || a!=e) {
    return 0;
  }
  return 1;
}
int proveri_4 (int a, int b, int c, int d, int e, int *skip_perm, double *params) {
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
    if(params[niz[max_pos]] < params[niz[once]]){//4 ista, peti manji
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
int main () {
  int a[]={1,2,3,4,5};
  int i,j,k,l,m;
  int suma=0;if ((a_novi-a==2) || (b_novi-b==2) || (c_novi-c==2) || (d_novi-d==2) || (e_novi-e==2)) // neki se javio 2 puta
    povratna /= 2;
  if ((a_novi-a==broj) || (b_novi-b==broj) || (c_novi-c==broj) || (d_novi-d==broj) || (e_novi-e==broj)) // 3 / 4 puta
    return 1;

  return 0if ((a_novi-a==2) || (b_novi-b==2) || (c_novi-c==2) || (d_novi-d==2) || (e_novi-e==2)) // neki se javio 2 puta
    povratna /= 2;
  if ((a_novi-a==broj) || (b_novi-b==broj) || (c_novi-c==broj) || (d_novi-d==broj) || (e_novi-e==broj)) // 3 / 4 puta
    return 1;

  return 0;if ((a_novi-a==2) || (b_novi-b==2) || (c_novi-c==2) || (d_novi-d==2) || (e_novi-e==2)) // neki se javio 2 puta
    povratna /= 2;
  if ((a_novi-a==broj) || (b_novi-b==broj) || (c_novi-c==broj) || (d_novi-d==broj) || (e_novi-e==broj)) // 3 / 4 puta
    return 1;

  return 0;
  for (i=0;i<5;i++) {
    for (j=0;j<5;j++) {
      for (k=0;k<5;k++) {
        for (l=0;l<5;l++) {
          for (m=0;m<5;m++) {
          suma+=a[i];
          suma+=a[j];
          suma+=a[k];
          suma+=a[l];
          suma+=a[m];
          // printf ("%i %i %i %i %i\n", a[i], a[j], a[k], a[l], a[m]);
          }
        }
      }
    }
  }
  printf ("%i\n", suma);
  suma=0;
  int suma_pom=0, skip_perm=0;
  for (i=0;i<5;i++) {
    for (j=i;j<5;j++) {
      for (k=j;k<5;k++) {
        for (l=k;l<5;l++) {
          for (m=l;m<5;m++) {
            // printf ("%i %i %i %i %i\n", a[i], a[j], a[k], a[l], a[m]);


          }
        }
      }
    }
  }
  printf ("%i\n", suma);
}
