#pragma once

#include <iostream>
#include <string>

class Gnuplot
{
    public:
    std::string cmd;
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

    void arrPlot2d(float x[], float y[]) {
        std::string name;
        int i;
        if(t.empty()) {
            name = "Arr"+std::to_string(this->no_arrPlot);
        }
        else {
            name = this->t;
        }
        this->cmd += " '-' t '" + name + "' w " + w + " lw "+std::to_string(lw)+
        " dt "+std::to_string(dt)+",";
        
        int n = -(*(&x + 1) - x);
        if (n>-(*(&y + 1) - y)) {
            n = -(*(&y + 1) - y);
        }
        for (i=0; i<n; i++) {
            this->dataPoints += std::to_string(x[i]) + " " + std::to_string(y[i]) + "\n";
        }
        this->dataPoints += "e\n";
        this->no_arrPlot++;
    }

    void display() {
        this->cmd.pop_back();
        this->cmd += "\n";
        FILE *fp;
        fp = popen("gnuplot", "w");
        FILE *gp;
        gp = fopen("gnuplot_cmd.gp", "w");
        fprintf(gp, this->cmd.c_str());
        fprintf(gp, this->dataPoints.c_str());
        fclose(gp);
        fprintf(fp, "load \"gnuplot_cmd.gp\"\n");
        fflush(fp);
        std::cout<<"Press Ctrl + C to exit!";
        getchar();
        delete this;
    }
};