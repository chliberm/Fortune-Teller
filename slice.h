#ifndef FINAL_PROJECT_SLICE_H
#define FINAL_PROJECT_SLICE_H

#include "shape.h"
class Slice : public Shape {
private:
    double radius;
    double startAngle;
    double rotationAngle;
public:
    /* Constructors */
    Slice();
    explicit Slice(double radius);
    explicit Slice(color fill);
    explicit Slice(point2D center);
    Slice(double startAngle, double rotationAngle);
    Slice(double radius, double startAngle, double rotationAngle);
    Slice(color fill, point2D center, double startAngle, double rotationAngle);
    Slice(double red, double green, double blue, double alpha, double startAngle, double rotationAngle);
    Slice(double red, double green, double blue, double alpha, double x, double y, double startAngle, double rotationAngle);
    Slice(color fill, double x, double y, double startAngle, double rotationAngle);
    Slice(double red, double green, double blue, double alpha, point2D center, double startAngle, double rotationAngle);
    Slice(color fill, double radius, double startAngle, double rotationAngle);
    Slice(point2D center, double radius, double startAngle, double rotationAngle);
    Slice(color fill, point2D center, double radius, double startAngle, double rotationAngle);
    Slice(double red, double green, double blue, double alpha, double radius, double startAngle, double rotationAngle);
    Slice(double red, double green , double blue, double alpha, double x, double y, double radius, double startAngle, double rotationAngle);
    Slice(color fill, double x, double y, double radius, double startAngle, double rotationAngle);
    Slice(double red, double green, double blue, double alpha, point2D center, double radius, double startAngle, double rotationAngle);

    /* Destructor */
    virtual ~Slice() = default;

    /* Getters */
    double getRadius() const;
    double getStartAngle() const;
    double getRotationAngle() const;

    /* Setters */
    void setRadius(double r);
    void changeRadius(double delta);
    void setStartAngle(double angle);
    void changeStartAngle(double phi);
    void setRotationAngle(double angle);

    /* Draw */
    void draw() const override;
};

#endif //FINAL_PROJECT_SLICE_H
