vector1 <- c(4,44.7,2,40,54,1,3,4)
l <- length(vector1)

min1 = 10000
max1 = -10000

for(i in 1:l){
  if(min1>vector1[i]){
    min1 = vector1[i];
  }
  if(max1<vector1[i]){
    max1 = vector1[i];
  }
}

print(paste("Minimum is", min1))
print(paste("Maximum is", max1))
