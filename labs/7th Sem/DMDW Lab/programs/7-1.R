library(rpart.plot)
library(rpart)
dataset <- read_csv("austin_weather.csv")
head(dataset)
shuffle_index<-sample(1:nrow(dataset))
dataset <- dataset[shuffle_index,]
ls(dataset)
sum(is.na(dataset$Events))
dim(dataset)

sum(is.na(dataset$DewPointAvgF))
summary(dataset$TempHighF)

dataset = subset(dataset, select = -c(Date,Events,TempAvgF, DewPointAvgF, HumidityAvgPercent,SeaLevelPressureAvgInches, VisibilityAvgMiles, WindAvgMPH ))

str(dataset)
dataset[] <- lapply(dataset, as.numeric)



dataset <- dataset %>%
  mutate(TempHighF = case_when(
    TempHighF < 40          ~ "<40",
    TempHighF >= 40 & TempHighF < 60 ~ "40-60",
    TempHighF >= 60 & TempHighF < 80 ~ "60-80",
    TempHighF >= 80 & TempHighF < 100 ~ "80-100",
    TempHighF >= 100                 ~ ">100",
    TRUE                             ~ "NA"
  ))

fit <- rpart(TempHighF~., data = dataset, method = 'class')
rpart.plot(fit, extra = 106)


