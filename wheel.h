#ifndef FINAL_PROJEC_WHEEL_H
#define FINAL_PROJEC_WHEEL_H

#include "FortuneTeller.h"
#include "shape.h"
#include "slice.h"
#include <vector>

class Wheel : public FortuneTeller, public Shape {
private:
    int numFortunes;
    std::vector<Slice> slices;
    Categories category;
    std::vector<std::vector<color>> paletteColors;
    double radius;
public:
    /* Constructors */
    Wheel();
    Wheel(Categories category);
    Wheel(point2D center);
    Wheel(double x, double y);
    Wheel(std::vector<std::vector<color>> palettes);
    Wheel(Categories category, point2D center);
    Wheel(Categories category, double x, double y);
    Wheel(Categories category, point2D center, std::vector<std::vector<color>> palettes);
    Wheel(Categories category, double x, double y, std::vector<std::vector<color>> palettes);

    /* Destructor */
    virtual ~Wheel() = default;

    /* Getters */
    int getNumFortunes() const;
    Categories getCategory() const;
    std::vector<std::vector<color>> getPallets() const;

    /* Setters */
    void setNumFortunes();
    void setCategory(Categories c);
    void setPallets(std::vector<std::vector<color>> p);
    void setRadius(double r);

    /* Populate wheel */
    void populate();

    /* Spin */
    void spin(float phi);

    /* chooseFortune */
    std::string chooseFortune();

    /* Draw */
    void draw() const override;
};

#endif //FINAL_PROJEC_WHEEL_H
