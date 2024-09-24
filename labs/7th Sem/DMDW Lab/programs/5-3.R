library(arules)
library(readr)
titanic <- read_csv("titanic.csv")
data(titanic)
rules=apriori(data= titanic, parameter = list(support=0.6,confidence=0.8))
rules
inspect(rules[1:5])
