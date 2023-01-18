#include <iostream>
#include <fstream>
#include <string>
#include "gnuplot.hh"

using namespace std;

int main() {
    float arr1x[] = {0.2, 0.5, 1};
    float arr1y[] = {0.04, 0.25, 1};
    Gnuplot a("plot");
    a.fplot("data.txt");
    a.arrPlot2d(arr1x, arr1y);
    a.fplot("data.txt", 1, 3);
    a.yplot("cos(x)");
    float arr2x[] = {0.2, 0.5, 1};
    float arr2y[] = {1.04, 1.25, 2};
    a.arrPlot2d(arr2x, arr2y);
    a.display();
    return 0;
}