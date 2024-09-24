library(readxl)
my_data=read_excel(file.choose())

#my_data <- read_excel('DMDW_LAB4.xlsx')
View(my_data)

#check and display ordered levels
my_data$group <- ordered(my_data$group, levels = c("Group1", "Group2", "Group3"))

#compute summary statistics by group
library(dplyr)
group_by(my_data, group) %>%
  summarise(
    count = n(),mean = mean(values, na.rm = TRUE),
    sd = sd(values, na.rm = TRUE)
  )

#compute one way ANOVA
#compute analysis of variance
res.aov <- aov(values ~ group, data = my_data)
#summary of analysis
summary(res.aov)

#interpret result of ANOVA
#multiple pairwise comparison
TukeyHSD(res.aov)
#homogeneity
plot(res.aov,1)
#normality
plot(res.aov,2)
