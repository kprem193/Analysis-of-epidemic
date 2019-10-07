# Analysis-of-epidemic
This can be used to simulate the spreading of a disease or rumor, which can be helpful to analyze these processes. 

In our datasets we have three types of people(nodes).

Susceptible - who are prone to the disease.
Infected - Who have the disease and can spread it.
Recovered - Who either got vaccinated after having the disease or have died.

Susceptibles which are connected to Infected nodes have lambda probability of getting infected if they remain connected for 1 timestamp.

An infected person has a beeta probability of getting recovered in 1 timestamp.

#Description of files

PowerData.csv - It contains the details of edges.

Susceptible.txt - It contains the details that which nodes are susceptible (1 for susceptible 0 for not).

Infected.txt -  It contains the details that which nodes are infected(1 for infected 0 for not).

Recovered.txt -  It contains the details that which nodes are recovered (1 for recovered 0 for not).

Day3.cpp - It is the main program which takes the data from Powerdata.csv, Susceptible.txt, Infected.txt, Recovered.txt and produces result.txt.

Average.cpp - It takes the result.txt as input, averages the data and generate sResult.dat, iResult.dat, rResult.dat to make it plottable on gnuplot.

sResult.dat - This file is generated to plot the curve between time and no of people susceptible. It contains two columns, timestamp and no of people susceptible.

iResult.dat - This file is generated to plot the curve between time and no of people Infected. It contains two columns, timestamp and no of people Infected.

rResult.dat - This file is generated to plot the curve between time and no of people recovered. It contains two columns, timestamp and no of people recovered.



