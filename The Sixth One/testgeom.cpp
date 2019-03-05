 //  File testgeom.cpp

#include <iostream>
#include <cmath>
#include <sstream>

#include "geometry.h"   // Our new header file

// Test the distance function
void do_distance(double x1, double y1, double x2, double y2) {
    std::cout << "The distance between ";
    print_point(x1, y1, std::cout);
    std::cout << " and ";
    print_point(x2, y2, std::cout);
    std::cout << " is " << distance(x1, y1, x2, y2) << '\n';      
}

// Test the slope function
void do_slope(double x1, double y1, double x2, double y2) {
    std::cout << "The slope of the line between ";
    print_point(x1, y1, std::cout);
    std::cout << " and ";
    print_point(x2, y2, std::cout);
    std::cout << " is ";
    double m = slope(x1, y1, x2, y2);
    if (m == INFINITY)
        std::cout << "undefined";
    else
        std::cout << m;
    std::cout << '\n';
}

// Test the intercept function
void do_intercept(double x1, double y1, double x2, double y2) {
    if (slope(x1, y1, x2, y2) == INFINITY)
        std::cout << "The x-";
    else
        std::cout << "The y-";
    std::cout << "intercept of the line between ";
    print_point(x1, y1, std::cout);
    std::cout << " and ";
    print_point(x2, y2, std::cout);
    std::cout << " is " << intercept(x1, y1, x2, y2) << '\n';
}

// Test the print_line function
void do_equation(double x1, double y1, double x2, double y2) {
    std::cout << "The equation of the line between ";
    print_point(x1, y1, std::cout);
    std::cout << " and ";
    print_point(x2, y2, std::cout);
    std::cout << " is ";
    print_line(slope(x1, y1, x2, y2), intercept(x1, y1, x2, y2),
               std::cout);
    std::cout << '\n';
}

int main() {
    for (;;) {  //  Infinite loop, use Control-C to quit
        double p_x1, p_y1, p_x2, p_y2;
        char paren, comma;
        std::cout << "Enter the point coordinates (x1, y1) and (x2, y2) "
                  << "(Control-C quits): ";
        std::cin >> paren >> p_x1 >> comma >> p_y1 >> paren
                 >> paren >> p_x2 >> comma >> p_y2 >> paren;
        do_distance(p_x1, p_y1, p_x2, p_y2);
        do_slope(p_x1, p_y1, p_x2, p_y2);
        do_intercept(p_x1, p_y1, p_x2, p_y2);
        do_equation(p_x1, p_y1, p_x2, p_y2);
        std::cout << "-----------------" << '\n';
    }
}
