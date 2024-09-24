dataset <- read_csv("WA_Fn-UseC_-Telco-Customer-Churn.csv")
dim(dataset)
ls(dataset)

dataset = subset(dataset, select = -c(customerID ))


fit <- rpart(Churn~., data = dataset, method = 'class')
rpart.plot(fit, extra = 106)
