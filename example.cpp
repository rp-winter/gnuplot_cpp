#include <iostream>
#include <fstream>
#include <string>
#include "gnuplot.hh"

using namespace std;

int main() {
    float arr1x[] = {0.2, 0.25, 0.5, 1, 2, 3, 4};
    float arr1y[] = {0.04, 0.125, 0.25, 1, 4, 9, 16};
    Gnuplot a("plot"); // Creating object "a" for 2d plot using "plot"
    a.fplot("data.dat"); // Plotting data stored in file with column 1 as x values and column 2 as y values
    a.arrPlot2d(arr1x, arr1y); // Plotting Array
    a.w = "l"; // Changing style of plot to line plot
    a.fplot("data.dat", 2, 3); // Plotting data stored in file with column 2 as values and column 3 as y values
    a.dt = 3; // Changing the line type to dashed line
    a.yplot("cos(x)"); // Plotting y = cos(x)
    a.t = "x^2 + 1"; // Chaning the Legend title of the plot
    a.display(); // Displaying the plot
    return 0;
}