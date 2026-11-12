/*
Author: Owen Murphy
Assignment Title: Sphere Class
Assignment Description: Write a program that creates a Sphere object and
    has mutliple useful functions
Due Date: 11/18/2019
Date Created: 11/08/2019
Date Last Modified: 11/18/2019
*/

#include "Sphere.h"

Sphere::Sphere() {
    radius = 1;
    color = "green";
}

Sphere::Sphere(double r) {
    radius = r;
    color = "green";
}

Sphere::Sphere(double r, string c) {
    radius = r;
    color = c;
}

void Sphere::setRadius(double r) {
    radius = r;
}

double Sphere::getRadius() const {
    return radius;
}

void Sphere::setColor(string c) {
    color = c;
}

string Sphere::getColor() const {
    return color;
}

double Sphere::area() const {
    return (4 * PI * radius * radius);
}

double Sphere::volume() const {
    return ((static_cast<double>(4) / 3) * PI * pow(radius, 3));
}

bool Sphere::isEqual(const Sphere other) const {
    return (radius == other.radius && color == other.color);
}
