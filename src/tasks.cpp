// Copyright 2025 UNN-CS
#include "tasks.h"
#include "circle.h"
#include <cmath>

double calculateGap() {
    double earthRadius = 6378100;
    Circle earth(earthRadius);
    double ropeLength = earth.getFerence() + 1;
    earth.setFerence(ropeLength);
    double gap = earth.getRadius() - earthRadius;
    return gap;
}

double calculatePoolCost() {
    double poolRadius = 3;
    double pathWidth = 1;
    double concreteCostPerSquareMeter = 1000;
    double fenceCostPerMeter = 2000;

    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);

    double pathArea = poolWithPath.getArea() - pool.getArea();
    double fenceLength = poolWithPath.getFerence();

    double totalConcreteCost = pathArea * concreteCostPerSquareMeter;
    double totalFenceCost = fenceLength * fenceCostPerMeter;

    return totalConcreteCost + totalFenceCost;
}
