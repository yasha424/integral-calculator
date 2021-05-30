#ifndef EVALUATION_H
#define EVALUATION_H

#pragma once
#include <cmath>
#include <iostream>
#include <tree.h>

double Riemann(Tree*, double, double, double, bool&);

double Trapezoidal(Tree*, double, double, double, bool&);

double Simpson(Tree*, double, double, double, bool&);

double sub_simpson(Tree*, double, double);

#endif // EVALUATION_H