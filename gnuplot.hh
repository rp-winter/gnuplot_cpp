#pragma once

#include <iostream>
#include <string>
#include <fstream>

class Gnuplot
{
    public:
    std::string cmd;
    std::string set_cmd = "";
    int keepSet = 0;
    std::string t = "";
    std::string w = "lp";
    int lw = 2;
    int dt = 1;
    std::string dataPoints = "";
    int no_arrPlot = 0;
    Gnuplot(std::string t) {
        cmd = t;
    }
    void fplot(std::string filename, int x = 1, int y = 2) {
        std::string name;
        if(t.empty()) {
            name = filename+"["+std::to_string(x)+":"+std::to_string(y)+"]";
        }
        else {
            name = this->t;
        }
        this->cmd += " \"" + filename + "\" using " + std::to_string(x) + ":" + std::to_string(y) + 
        " t '" + name + "' w " + w + " lw "+std::to_string(lw)+
        " dt "+std::to_string(dt)+",";
        if (!keepSet) {
            this->t = "";
            this->w = "lp";
            this->lw = 2;
            this->dt = 1;
        }

    }
    void yplot(std::string equation) {
        this->cmd += " "+equation+",";
    }

    void arrPlot2d(int n, double x[], double y[]) {
        std::string name;
        int i;
        if(this->t.empty()) {
            name = "Arr"+std::to_string(this->no_arrPlot);
        }
        else {
            name = this->t;
        }
        this->cmd += " '-' t '" + name + "' w " + w + " lw "+std::to_string(lw)+
        " dt "+std::to_string(dt)+",";
        for (i=0; i<n; i++) {
            this->dataPoints += std::to_string(x[i]) + " " + std::to_string(y[i]) + "\n";
        }
        this->dataPoints += "e\n";
        this->no_arrPlot++;
    }

    void xrange(double a, double b) {
        this->set_cmd += "set xrange ["+std::to_string(a)+":"+std::to_string(b)+"]\n";
    }
    
    void yrange(double a, double b) {
        this->set_cmd += "set yrange ["+std::to_string(a)+":"+std::to_string(b)+"]\n";
    }

    void xlabel(std::string s) {
        this->set_cmd += "set xlabel \"" + s + "\"\n";
    }

    void ylabel(std::string s) {
        this->set_cmd += "set ylabel \"" + s + "\"\n";
    }

    void title(std::string s) {
        this->set_cmd += "set title \"" + s + "\"\n";
    }

    void display() {
        this->cmd.pop_back();
        this->cmd += "\n";
        std::ofstream gp("gnuplot_cmd.gp");
        gp << this->set_cmd << this->cmd << this->dataPoints;
        gp.close();
        FILE *fp;
        fp = popen("gnuplot", "w");
        fprintf(fp, "load \"gnuplot_cmd.gp\"\n");
        fflush(fp);
        std::cout<<"\nPress Ctrl + C to exit!";
        getchar();
    }
};