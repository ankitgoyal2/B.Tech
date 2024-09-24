#build data
my_data<- PlantGrowth

#check data and display ordered levels
sample_n(my_data,10)

#show levels
levels(my_data$group)

#compute summary statistics
library(dplyr)
group_by(my_data, group) %>%
  summarise(
    count = n(),
    mean = mean(weight, na.rm = TRUE),
    sd = sd(weight, na.rm = TRUE)
  )

#compute anova test
# Compute the analysis of variance
res.aov <- aov(weight ~ group, data = my_data)
# Summary of the analysis
summary(res.aov)

#Interpret the result of one-way ANOVA tests
#multiple pairwise comparison
TukeyHSD(res.aov)
#Homogeneity of variances
plot(res.aov, 1)
#Normality
plot(res.aov, 2)
