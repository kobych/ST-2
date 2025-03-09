// Copyright 2022 UNN-CS
#include <cstdint>
#include "circle.h"
#include <cmath>

Circle::Circle(double r) {
    setRadius(r);
}

void Circle::setRadius(double r) {
    radius = r;
    updateFerence();
    updateArea();
}

void Circle::setFerence(double f) {
    ference = f;
    updateRadius();
    updateArea();
}

void Circle::setArea(double a) {
    area = a;
    updateRadius();
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
