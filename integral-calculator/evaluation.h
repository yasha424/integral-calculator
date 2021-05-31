#ifndef EVALUATION_H
#define EVALUATION_H

#pragma once
#include <cmath>
#include <iostream>
#include <tree.h>

double Riemann(Tree*, double, double, double, bool&, size_t, size_t&, size_t&);

double Trapezoidal(Tree*, double, double, double, bool&, size_t, size_t&, size_t&);

double Simpson(Tree*, double, double, double, bool&, size_t, size_t&, size_t&);

double sub_simpson(Tree*, double, double);

#endif // EVALUATION_H
