#include "wheel.h"
#include "graphics.h"

using namespace std;

Wheel::Wheel() : Shape(), numFortunes(0), slices(), category(InvalidCategory), paletteColors() {
}

Wheel::Wheel(Categories category) :  Shape(), numFortunes(0), slices(), paletteColors() {
    setCategory(category);
}

Wheel::Wheel(point2D center) :  Shape(center), numFortunes(0), slices(), category(InvalidCategory), paletteColors() {
}

Wheel::Wheel(double x, double y) :  Shape(x, y), numFortunes(0), slices(), category(InvalidCategory), paletteColors() {
}

Wheel::Wheel(vector<vector<color>> palettes) :  Shape(), numFortunes(0), slices(), category(InvalidCategory) {
    setPallets(palettes);
}

Wheel::Wheel(Categories category, point2D center) : Shape(center), numFortunes(0), slices(), paletteColors() {
    setCategory(category);
}

Wheel::Wheel(Categories category, double x, double y) : Shape(x, y), numFortunes(0), slices(), paletteColors(){
   setCategory(category);
}

Wheel::Wheel(Categories category, point2D center, vector<vector<color>> palettes) : Shape(center), numFortunes(0), slices() {
    setCategory(category);
    setPallets(palettes);
}

Wheel::Wheel(Categories category, double x, double y, vector<vector<color>> palettes) : Shape(x, y), numFortunes(0), slices() {
    setCategory(category);
    setPallets(palettes);
}

int Wheel::getNumFortunes() const {
    return numFortunes;
}

Categories Wheel::getCategory() const {
    return category;
}

vector<vector<color>> Wheel::getPallets() const {
    return paletteColors;
}

void Wheel::setNumFortunes() {
    getFortune(category, 0);
    switch (category) {
        case Finance: {
            numFortunes = financeFortunes.size();
            break;
        }

        case Love: {
            numFortunes = loveFortunes.size();
            break;
        }

        case Family: {
            numFortunes = familyFortunes.size();
            break;
        }
    }
}

void Wheel::setCategory(Categories c) {
    category = c;
}

void Wheel::setPallets(vector<vector<color>> p) {
    paletteColors = p;
}

void Wheel::setRadius(double r) {
    radius = r;
}

void Wheel::populate() {
    vector<color> palette = {};
    int index = 0;
    float initAngle = 0;
    float rotateAngle = 2*PI/numFortunes;
    switch(category) {
        case Finance: {
            palette = paletteColors[0];
            break;
        }

        case Love: {
            palette = paletteColors[1];
            break;
        }

        case Family: {
            palette = paletteColors[2];
            break;
        }
    }
    for (int i = 0; i < numFortunes; i++) {
        slices.push_back(Slice(palette[index], getCenter(), radius, initAngle, rotateAngle));
        initAngle += rotateAngle;
        index++;
    }
}

void Wheel::spin(float phi) {
    for (Slice &s : slices) {
        s.changeStartAngle(phi);
    }
}

string Wheel::chooseFortune() {
    int index = 0;
    for (Slice s : slices) {
        if (cos(s.getStartAngle()) <= 0 && cos(s.getStartAngle() + s.getRotationAngle()) >= 0) {
            //return getFortune(category, index);
            switch (category) {
                case Finance: {
                    return financeFortunes[index];
                }

                case Love: {
                    return loveFortunes[index];
                }

                case Family: {
                    return familyFortunes[index];
                }
            }
        }
        index++;
    }
    return "Error, no fortune.";
}

void Wheel::draw() const {
    for (Slice s : slices) {
        s.draw();
    }
}

