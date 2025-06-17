#pragma once
#include <string>

class TParam {
private:
    std::string name;
    int x_start, x_end, dx;
    int val;

public:
    TParam(std::string name, int x_start, int x_end, int dx);
    int get_val() const;
    void set_val(int v);
    std::string get_name() const;
    int get_x_start() const;
    int get_x_end() const;
    int get_dx() const;
};