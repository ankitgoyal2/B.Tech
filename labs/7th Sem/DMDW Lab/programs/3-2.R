library(dplyr)

#1 Show where gear attribute = 4,
gear_4 <- filter(mtcars, gear == 4)
head(gear_4)

#2 Show where disp = 160.
disp_160 <- filter(mtcars, disp == 160.0)
head(disp_160)

#3 Show different operations (and, or, not)
#AND
gear4_and_carb4 <- filter(mtcars, gear == 4 & carb == 4)
head(gear4_and_carb4)
#OR
gear4_or_hp110 <- filter(mtcars, gear == 4 | hp == 110)
head(gear4_or_hp110)
#Not
gearNot4 <- filter(mtcars, gear != 4)
head(gearNot4)


