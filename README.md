# Benfords-Law
  This simple code uses Benford's Law to detect which list is fake (only one is fake - r08.txt)
  
  Benford's law basically says that if a random number is selected randomly from "a table of physical constants or statistical data" the leading digit is more likely to be the number "1" about 30% of the time. The higher the leading digit(1-9) is, the less likely it is to appear. 

  This program determines, from the list of files given, if that file contains a set of fake data. The fake data set contains numbers that were equally generated. Given Benford's law, we know that real data contains leading numbers that appear a certain amount of time. Using this information, we can determine if the file is fake or not.
