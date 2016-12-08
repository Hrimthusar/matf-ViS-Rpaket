# Some useful keyboard shortcuts for package authoring:
#
#   Build and Reload Package:  'Ctrl + Shift + B'
#   Check Package:             'Ctrl + Shift + E'#   http://r-pkgs.had.co.nz/

#   Test Package:              'Ctrl + Shift + T'

generate_parameters = function(lambda,n){
  rexp(n,rep(lambda,n));
}

dyn.load("Desktop/Faks/ViS/RPaket/ViS/funkcija.so")

#TEST1
lambda = 1.1
n = 50
parameters = generate_parameters(lambda,n)
#parameters = c(1.5654707, 1.3357677, 0.3068612, 1.0476455, 1.4116881, 0.7479037, 6.0386922, 0.1116368, 0.3521352, 1.3572822)
sum = 0

ptm <- proc.time()
out = .C("funkcija", n=as.integer(n), x = as.double(parameters), sum = as.double(sum))
print(proc.time() - ptm)

print(out$sum)

# TEST2
lambda = 1.1

for (i in c(5:30)) {
  n = i
  parameters = generate_parameters(lambda,n)
  
  ptm <- proc.time()
  out = .C("funkcija", n=as.integer(n), x = as.double(parameters), sum = as.double(sum))
  print(c(out$n, out$sum, proc.time() - ptm))
}

