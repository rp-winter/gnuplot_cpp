# gnuplot_cpp
A C++ header (gnuplot.hh) to plot graph using gnuplot.

Created By: Ritik Pal, rp.ritikpalavatar@gmail.com  
Created On: 17 Jan 2023.  

# Requirements
Gnuplot must be installed on your machine, and the application directory must be included in PATH environment variables, so that you can call gnuplot through the terminal.

# Getting Started
To be able to plot graph using the header file, you can:
1. Either copy the gnuplot.hh to the system header files directory.  
2. Or copy the gnuplot.hh inside the folder containing the codes you would like to use the header file with.  
After that, in your code you can include the header file using  
```
#include <gnuplot.hh>
```
or
```
#include "gnuplot.hh"
```
This will allow you to use the functions and objects defined in the header file.  

# Plotting Graph
To plot a graph, you will need to create a new Gnuplot object and specify the type of plot. This object will store the different options (like linewidth, title etc) for plotting the graph.   
```
Gnuplot a("plot");
```
After the Gnuplot object has been constructed, you can use several other functions and options to plot graph. After specifying all the plots and its options you can display the graph at the end of your code.  
To display the graph, display() function is used. The use of display function is explained below.

## Plotting graph using array
If you have two arrays x[] and y[], you can plot the points using the command arrPlot2d(). This function takes the argument (1) array x[] and (2) array y[].
```
double arrx[] = {1, 2, 3, 4};
double arry[] = {1, 4, 9, 16};
a.arrPlot2d(arrx, arry);
```

## Plotting function of the form y = f(x).
We can plot function of the form y = f(x) using yplot(). This function takes the argument a string with functional form.
```
a.yplot("cos(x)");
```
## Plotting graph from a data file.
We can plot data stored in data file using fplot(). This function takes the argument a string containing the name of the data file along with extension.  
There are two optional arguments, (1) column position of the x data in the data file, and (2) column position of the y data.  
For example, if the data file named "data.txt" is as shown:
```
0 0 1
1 0.84 0.54
2 0.9 -0.4
3 0.14 -0.98
4 -0.75 -0.65
5 -0.95 0.28
```
We can plot graph with x data in column 1 (1, 2, 3, 4, 5) and y data in column 2 (0, 0.84, 0.9, 0.14, -0.75, -0.95) using the command,
```
a.fplot("data.txt");
```
This will plot the data contained in column 1 as x values and column 2 as y values.
To plot column 2 as x values and column 3 as y values, you can use the optional argumnets.
```
a.fplot("data.dat", 2, 3);
```
## Displaying the Graph
Finally after specifying all the plots you can display the graph using display() function.
```
a.display();
```

# Changing the style and other options

1) Legend Title:
To change the legend title of a graph.
```
a.t = "title of the graph";
```

2) Style of graph: 
To change the style of graph (line, linepoints, point):
```
a.w = "lp"; //linepoints
a.w = "p"; //points
a.w = "l"; //line
```
Details of different style of graph can be obtained in Gnuplot documentation.  

3) Line width: 
Line width of a line graph can be set using,
```
a.lw = 2;
```

4) Dash Type: 
To plot dashed line, or dotted lines.
```
a.dt = 3;
```
The type of lines corresponding to different values can be found in gnuplot documentation.

# PS
Currently only these functionalities has been added. I plan to add more functionalities if time permits.
