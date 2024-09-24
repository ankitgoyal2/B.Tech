print("Arrange : ")
arrange(mtcars, desc(disp))

print("Group By : ")
group_by(mtcars,drat)

print("Summarise : ")
summarise(mtcars,mean(disp))

print("Select : ")
select(mtcars,qsec)

print("Intersect :")
A<- subset(mtcars,disp==160)
B<- subset(mtcars,cyl=100)
intersect(A,B)

print("SetDiff :")
setdiff(B,A)
