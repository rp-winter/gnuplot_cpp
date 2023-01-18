#include <iostream>
#include <fstream>
#include <string>
#include "gnuplot.hh"

using namespace std;

int main() {
    float arr1x[] = {0.2, 0.25, 0.5, 1, 2, 3, 4};
    float arr1y[] = {0.04, 0.125, 0.25, 1, 4, 9, 16};
    Gnuplot a("plot");
    a.fplot("data.dat");
    a.arrPlot2d(arr1x, arr1y);
    a.w = "l";
    a.fplot("data.dat", 1, 3);
    a.dt = 3;
    a.yplot("cos(x)");
    a.t = "x^2 + 1";
    float arr2x[] = {0.2, 0.5, 1, 2, 3, 4};
    float arr2y[] = {1.04, 1.25, 2, 5, 10, 17};
    a.arrPlot2d(arr2x, arr2y);
    a.display();
    return 0;
}