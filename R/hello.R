# Hello, world!
#
# This is an example function named 'hello'
# which prints 'Hello, world!'.
#
# You can learn more about package authoring with RStudio at:
#
#
# Some useful keyboard shortcuts for package authoring:
#
#   Build and Reload Package:  'Ctrl + Shift + B'
#   Check Package:             'Ctrl + Shift + E'#   http://r-pkgs.had.co.nz/

#   Test Package:              'Ctrl + Shift + T'


generate_parameters = function(lambda,n){
  rexp(n,rep(lambda,n));
}

lambda = 3
n = 20
sum = 0

parameters = sort(generate_parameters(lambda,n))

dyn.load("Desktop/Faks/ViS/RPaket/ViS/funkcija.so")
ptm <- proc.time()
out = .C("funkcija", n=as.integer(n), x = as.double(parameters), sum = as.double(sum))
proc.time() - ptm
out$sum
