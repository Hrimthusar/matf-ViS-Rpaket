# Hello, world!
#
# This is an example function named 'hello'
# which prints 'Hello, world!'.
#
# You can learn more about package authoring with RStudio at:
#
#   http://r-pkgs.had.co.nz/
#
# Some useful keyboard shortcuts for package authoring:
#
#   Build and Reload Package:  'Ctrl + Shift + B'
#   Check Package:             'Ctrl + Shift + E'
#   Test Package:              'Ctrl + Shift + T'

hello <- function() {
  print("Hello, world!")
}

roll_dices <- function(dice_sides, roll_number) {
  if(missing(dice_sides)){
    N = 6
  }
  if(dice_sides<1){
    return(0)
  }

  if(missing(roll_number)){
    roll_number = 1
  }
  if(roll_number<1){
    return(0)
  }

  x = ceiling( runif(roll_number, 0, dice_sides) )

  return(x)
}

draw_card <- function(){

}
