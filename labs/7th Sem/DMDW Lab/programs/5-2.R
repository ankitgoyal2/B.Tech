library(arules)
library(readr)
groceries2 <- read_excel("LAB5-2.csv")

rules=apriori(data= groceries2, parameter = list(support=0.6,confidence=0.8))
rules
