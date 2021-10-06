#include "slice.h"
#include "graphics.h"

Slice::Slice() : Shape(), radius (0), startAngle(0), rotationAngle(0) {
}

Slice::Slice(double radius) : Shape(), startAngle(0), rotationAngle(0) {
    setRadius(radius);
}

Slice::Slice(color fill) : Shape(fill), radius(0), startAngle(0), rotationAngle(0) {
}

Slice::Slice(point2D center) : Shape(center), radius(0), startAngle(0), rotationAngle(0) {
}

Slice::Slice(double startAngle, double rotationAngle) : Shape(), radius(0) {
    setStartAngle(startAngle);
    setRotationAngle(rotationAngle);
}

Slice::Slice(double radius, double startAngle, double rotationAngle) : Shape() {
    setRadius(radius);
    setStartAngle(startAngle);
    setRotationAngle(rotationAngle);
}

Slice::Slice(color fill, point2D center, double startAngle, double rotationAngle) : Shape(fill, center), radius(0) {
    setStartAngle(startAngle);
    setRotationAngle(rotationAngle);
}

Slice::Slice(double red, double green, double blue, double alpha, double startAngle, double rotationAngle) : Shape(red, green, blue, alpha), radius(0) {
    setStartAngle(startAngle);
    setRotationAngle(rotationAngle);
}

Slice::Slice(double red, double green, double blue, double alpha, double x, double y, double startAngle, double rotationAngle) : Shape(red, blue, green, alpha, x, y), radius(0) {
    setStartAngle(startAngle);
    setRotationAngle(rotationAngle);
}

Slice::Slice(color fill, double x, double y, double startAngle, double rotationAngle) : Shape(fill, x, y), radius(0) {
    setStartAngle(startAngle);
    setRotationAngle(rotationAngle);
}

Slice::Slice(double red, double green, double blue, double alpha, point2D center, double startAngle, double rotationAngle) : Shape(red, green, blue, alpha, center), radius(0) {
    setStartAngle(startAngle);
    setRotationAngle(rotationAngle);
}

Slice::Slice(color fill, double radius, double startAngle, double rotationAngle) : Shape(fill) {
    setRadius(radius);
    setStartAngle(startAngle);
    setRotationAngle(rotationAngle);
}

Slice::Slice(point2D center, double radius, double startAngle, double rotationAngle) : Shape(center) {
    setRadius(radius);
    setStartAngle(startAngle);
    setRotationAngle(rotationAngle);
}

Slice::Slice(color fill, point2D center, double radius, double startAngle, double rotationAngle) : Shape(fill, center) {
    setRadius(radius);
    setStartAngle(startAngle);
    setRotationAngle(rotationAngle);
}

Slice::Slice(double red, double green, double blue, double alpha, double radius, double startAngle, double rotationAngle) : Shape(red, green, blue, alpha) {
    setRadius(radius);
    setStartAngle(startAngle);
    setRotationAngle(rotationAngle);
}
Slice::Slice(double red, double green , double blue, double alpha, double x, double y, double radius, double startAngle, double rotationAngle) : Shape(red, green, blue, alpha, x, y) {
    setRadius(radius);
    setStartAngle(startAngle);
    setRotationAngle(rotationAngle);
}

Slice::Slice(color fill, double x, double y, double radius, double startAngle, double rotationAngle) : Shape(fill, x, y) {
    setRadius(radius);
    setStartAngle(startAngle);
    setRotationAngle(rotationAngle);
}
Slice::Slice(double red, double green, double blue, double alpha, point2D center, double radius, double startAngle, double rotationAngle) : Shape(red, green, blue, alpha, center) {
    setRadius(radius);
    setStartAngle(startAngle);
    setRotationAngle(rotationAngle);
}

double Slice::getRadius() const {
    return radius;
}

double Slice::getStartAngle() const {
    return startAngle;
}

double Slice::getRotationAngle() const {
    return rotationAngle;
}

void Slice::setRadius(double r) {
    radius = r;
}

void Slice::changeRadius(double delta) {
    setRadius(radius + delta);
}

void Slice::setStartAngle(double angle) {
    if (angle <= 2*PI && angle >= 0) {
        startAngle =  angle;
    } else if(angle > 2*PI) {
        startAngle = angle - 2*PI;
    } else if(angle < 0) {
        startAngle = 2*PI + angle;
    }
}

void Slice::changeStartAngle(double phi) {
    setStartAngle(startAngle + phi);
}

void Slice::setRotationAngle(double angle) {
    if (angle <= 2*PI && angle >= 0) {
        rotationAngle =  angle;
    } else if(angle > 2*PI) {
        rotationAngle = angle - 2*PI;
    } else if(angle < 0) {
        rotationAngle = 2*PI + angle;
    }
}

void Slice::draw() const {
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(center.x, center.y);
    for (double i = startAngle; i <= startAngle+rotationAngle; i += (2.0*PI)/360.0) {
        glVertex2i(center.x + (radius * cos(i)),
                   center.y + (radius * sin(i)));
    }
    glEnd();
}