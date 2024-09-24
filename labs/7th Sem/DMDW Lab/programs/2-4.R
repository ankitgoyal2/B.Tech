data <- data.frame(x1 = c(9, 8, 3, 4, 8),         
                   x2 = c(5, 4, 7, 1, 1),
                   x3 = c(1, 2, 3, 4, 5))
data
x1 #give error
attach(data)
x1 #run
detach(data)
x1 # give error


