mtcars
mtcars$mpg = ifelse(is.na(mtcars$mpg),ave(mtcars$mpg, FUN = function(x) mean(x,na.rm='TRUE')),mtcars$mpg)
mtcars
