// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"
#include <cmath>

TEST(CircleTest, Initialization) {
    Circle c(5);
    EXPECT_NEAR(c.getRadius(), 5, 1e-6);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 5, 1e-6);
    EXPECT_NEAR(c.getArea(), M_PI * 25, 1e-6);
}

TEST(CircleTest, SetRadius) {
    Circle c(5);
    c.setRadius(10);
    EXPECT_NEAR(c.getRadius(), 10, 1e-6);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 10, 1e-6);
    EXPECT_NEAR(c.getArea(), M_PI * 100, 1e-6);
}

TEST(CircleTest, SetFerence) {
    Circle c(5);
    c.setFerence(2 * M_PI * 15);
    EXPECT_NEAR(c.getRadius(), 15, 1e-6);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 15, 1e-6);
    EXPECT_NEAR(c.getArea(), M_PI * 225, 1e-6);
}

TEST(CircleTest, SetArea) {
    Circle c(5);
    c.setArea(M_PI * 400);
    EXPECT_NEAR(c.getRadius(), 20, 1e-6);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 20, 1e-6);
    EXPECT_NEAR(c.getArea(), M_PI * 400, 1e-6);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0);
    EXPECT_NEAR(c.getRadius(), 0, 1e-6);
    EXPECT_NEAR(c.getFerence(), 0, 1e-6);
    EXPECT_NEAR(c.getArea(), 0, 1e-6);
}

TEST(CircleTest, NegativeRadius) {
    EXPECT_THROW(Circle(-1), std::invalid_argument);
}

TEST(CircleTest, NegativeFerence) {
    Circle c(5);
    EXPECT_THROW(c.setFerence(-1), std::invalid_argument);
}

TEST(CircleTest, NegativeArea) {
    Circle c(5);
    EXPECT_THROW(c.setArea(-1), std::invalid_argument);
}

TEST(RopeGapTest, BasicTest) {
    double gap = calculateGap();
    EXPECT_NEAR(gap, 0.159, 1e-3);
}

TEST(RopeGapTest, ZeroGap) {
    double earthRadius = 6378100;
    Circle earth(earthRadius);
    double ropeLength = earth.getFerence();
    earth.setFerence(ropeLength);
    double gap = earth.getRadius() - earthRadius;
    EXPECT_NEAR(gap, 0, 1e-6);
}

TEST(PoolCostTest, BasicTest) {
    double cost = calculatePoolCost();
    double expectedCost = (M_PI * (16 - 9) * 1000) + (2 * M_PI * 4 * 2000);
    EXPECT_NEAR(cost, expectedCost, 1e-6);
}

TEST(PoolCostTest, ZeroWidthPath) {
    double poolRadius = 3;
    double pathWidth = 0;
    double concreteCostPerSquareMeter = 1000;
    double fenceCostPerMeter = 2000;

    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);

    double pathArea = poolWithPath.getArea() - pool.getArea();
    double fenceLength = poolWithPath.getFerence();

    double totalConcreteCost = pathArea * concreteCostPerSquareMeter;
    double totalFenceCost = fenceLength * fenceCostPerMeter;

    EXPECT_NEAR(totalConcreteCost, 0, 1e-6);
    EXPECT_NEAR(totalFenceCost, 2 * M_PI * 3 * 2000, 1e-6);
}

TEST(PoolCostTest, NegativeRadius) {
    EXPECT_THROW(Circle(-1), std::invalid_argument);
}

TEST(PoolCostTest, NegativePathWidth) {
    EXPECT_THROW(Circle(3).setRadius(-1), std::invalid_argument);
}

TEST(PoolCostTest, LargeRadius) {
    Circle c(1e6);
    EXPECT_NEAR(c.getRadius(), 1e6, 1e-6);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e6, 1e-6);
    EXPECT_NEAR(c.getArea(), M_PI * 1e12, 1e-6);
}

TEST(PoolCostTest, SmallRadius) {
    Circle c(1e-6);
    EXPECT_NEAR(c.getRadius(), 1e-6, 1e-6);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e-6, 1e-6);
    EXPECT_NEAR(c.getArea(), M_PI * 1e-12, 1e-6);
}

TEST(PoolCostTest, ZeroArea) {
    Circle c(0);
    EXPECT_NEAR(c.getArea(), 0, 1e-6);
}

TEST(PoolCostTest, ZeroFerence) {
    Circle c(0);
    EXPECT_NEAR(c.getFerence(), 0, 1e-6);
}

TEST(PoolCostTest, LargeFerence) {
    Circle c(1e6);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e6, 1e-6);
}

TEST(PoolCostTest, SmallFerence) {
    Circle c(1e-6);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e-6, 1e-6);
}

TEST(PoolCostTest, LargeArea) {
    Circle c(1e6);
    EXPECT_NEAR(c.getArea(), M_PI * 1e12, 1e-6);
}

TEST(PoolCostTest, SmallArea) {
    Circle c(1e-6);
    EXPECT_NEAR(c.getArea(), M_PI * 1e-12, 1e-6);
}
