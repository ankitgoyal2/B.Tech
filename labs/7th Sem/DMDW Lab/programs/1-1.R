A <- rbind(c(3,-2,1),c(-1,4,-2))
B <- rbind(c(-7,4),c(9,5),c(2,-1))

print("Matrix A : ")
print(A)
print("Matrix B :")
print(B)

#AB
C <-A%*%B
print("Multiplication AB :")
print(C)

#T(AB)
T <-t(C)
print("Transpose of Matrix AB :")
print(T)

#I(AB)
I <- solve(C)
print("Inverse of Matrix AB :")
print(I)

#Mean
print("Mean of Matrix A :")
#Row
mean(A[1,])
mean(A[2,])
#column
mean(A[,1])
mean(A[,2])
mean(A[,3])

print("Mean of Matrix B :")
#Row
mean(B[1,])
mean(B[2,])
mean(B[3,])
#column
mean(B[,1])
mean(B[,2])

print("Mean of Matrix AB :")
#Row
mean(C[1,])
mean(C[2,])
#column
mean(C[,1])
mean(C[,2])

print("Mean of Matrix Inverse of AB :")
#Row
mean(I[1,])
mean(I[2,])
#column
mean(I[,1])
mean(I[,2])

#Standard Deviations 
print("Standard deviation of matrix A :")
sd(A,na.rm=TRUE)
print("Standard deviation of matrix B :")
sd(B,na.rm=TRUE)
print("Standard deviation of matrix AB :")
sd(C,na.rm=TRUE)
print("Standard deviation of matrix inverse of AB :")
sd(I,na.rm=TRUE)
