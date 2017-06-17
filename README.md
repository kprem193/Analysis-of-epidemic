# Analysis-of-epidemic
It shows the variation of no of people susceptible,infected and recovered of a disease. 

In our datasets we have three types of people(nodes).

Susceptible - who are prone to the disease.
Infected - Who have the disease and can spread it.
Recovered - Who either got vaccinated after having the disease or have died.

In our data set we had 4920 nodes and there were 13688 edges between them.

The susceptible who are connected to Infected have the 0.6 probability of getting infected if they remain connected for 1 timestamp.

An infected person has a 0.85 probability of getting recovered in 1 timestamp.

#Description of files

PowerData.csv - It contains the details of edges.

Susceptible.txt - It contains the details that which node is susceptible and which node is not(1 for susceptible 0 for not).

Infected.txt -  It contains the details that which node is infected and which node is not(1 for infected 0 for not).

Recovered.txt -  It contains the details that which node is recovered and which node is not(1 for recovered 0 for not).

Day3.cpp - It is the main program which takes the data from Powerdata.csv, Susceptible.txt, Infected.txt, Recovered.txt and produce result.txt.

Average.cpp - It takes the result.txt as input average the data and generate sResult.dat, iResult.dat, rResult.dat to make it plottable on gnuplot.

sResult.dat - This file is generated to plot the curve between time and no of people susceptible. It contains two columns, first timestamp and second no of people susceptible.

iResult.dat - This file is generated to plot the curve between time and no of people Infected. It contains two columns, first timestamp and second no of people Infected.

rResult.dat - This file is generated to plot the curve between time and no of people recovered. It contains two columns, first timestamp and second no of people recovered.



