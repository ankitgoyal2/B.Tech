# Installing Packages 
install.packages("e1071") 
install.packages("caTools") 
install.packages("caret") 

# Loading package 
library(e1071) 
library(caTools) 
library(caret) 
library(dplyr)

dataset = read_csv("Mall_Customers.csv")

dataset$Gender <- factor(dataset$Gender, levels = c("Male", "Female"), labels = c(0,1))

dataset <- dataset %>%
  mutate(Age = case_when(
    Age < 30                  ~ "<30",
    Age >= 30 & Age < 45      ~ "30-45",
    Age >= 45 & Age < 60      ~ "45-60",
    Age >= 60                 ~ ">60",
    TRUE                      ~ "NA"
  ))


dataset <- dataset %>%
  mutate(Income = case_when(
    Income <40                   ~ "<40",
    Income >= 40 & Income < 60      ~ "40-60",
    Income >= 60                 ~ ">60",
    TRUE                      ~ "NA"
  ))

dataset <- dataset %>%
  mutate(Score = case_when(
    Score < 30                  ~ "<20",
    Score >= 20 & Score < 40      ~ "20-40",
    Score >= 40 & Score < 60      ~ "40-60",
    Score >= 60 & Score < 80      ~ "60-80",
    Score >= 80                 ~ ">80",
    TRUE                      ~ "NA"
  ))

trainIndex <- createDataPartition(dataset$Score, p = .7,
                                  list = FALSE,
                                  times = 1)

Train <- dataset[ trainIndex,]
Valid <- dataset[-trainIndex,]

# Fitting Naive Bayes Model 
# to training dataset 

classifier_cl <- naiveBayes(Score ~ ., data = Train) 
classifier_cl 
