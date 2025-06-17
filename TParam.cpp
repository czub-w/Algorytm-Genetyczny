#include "TParam.h"

TParam::TParam(std::string name, int x_start, int x_end, int dx)
    : name(name), x_start(x_start), x_end(x_end), dx(dx), val(0) {
}

int TParam::get_val() const {
    return val;
}

void TParam::set_val(int v) {
    val = v;
}

std::string TParam::get_name() const {
    return name;
}

int TParam::get_x_start() const { return x_start; }
int TParam::get_x_end() const { return x_end; }
int TParam::get_dx() const { return dx; }

