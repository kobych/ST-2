// Copyright 2022 UNN-CS
#include "circle.h"
#include <cstdint>
#include <stdexcept>
#include <cmath>

Circle::Circle(double r) {
    if (r < 0) {
        throw std::invalid_argument("Radius cannot be negative");
    }
    setRadius(r);
}

void Circle::setRadius(double r) {
    if (r < 0) {
        throw std::invalid_argument("Radius cannot be negative");
    }
    radius = r;
    updateFerence();
    updateArea();
}

void Circle::setFerence(double f) {
    if (f < 0) {
        throw std::invalid_argument("Ference cannot be negative");
    }
    ference = f;
    updateRadius();
    updateArea();
}

void Circle::setArea(double a) {
    if (a < 0) {
        throw std::invalid_argument("Area cannot be negative");
    }
    area = a;
    radius = std::sqrt(area / M_PI);
    updateFerence();
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}

void Circle::updateFerence() {
    ference = 2 * M_PI * radius;
}

void Circle::updateArea() {
    area = M_PI * radius * radius;
}

void Circle::updateRadius() {
    radius = ference / (2 * M_PI);
}
