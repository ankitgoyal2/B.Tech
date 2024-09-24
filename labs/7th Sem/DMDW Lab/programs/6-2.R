dataset <- read_excel("Lung Capacity.xls")
summary(dataset)
cor(dataset$Height, dataset$LungCapacity)
cor(dataset$Age, dataset$LungCapacity)
plot(dataset$Exercise, dataset$LungCapacity,data = dataset)


dataset.lm <- lm(dataset$LungCapacity ~ dataset$Gender + dataset$Height + dataset$Smoker  +dataset$Exercise, data= dataset)
summary(dataset.lm)
