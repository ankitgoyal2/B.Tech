library(readr)
library(arules)
dataset <- read_excel(file.choose())

rules=apriori(data= dataset, parameter = list(support=0.7,confidence=0.85))
rules