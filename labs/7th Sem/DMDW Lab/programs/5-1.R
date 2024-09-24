library(arules)
groceries <- read_excel("LAB5.csv")
rules=apriori(data= groceries, parameter = list(support=0.001,confidence=0.9))
inspect(rules[1:5])