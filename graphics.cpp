#include "graphics.h"
#include "shape.h"
#include "Button.h"
#include "rect.h"
#include "slice.h"
#include "wheel.h"
#include <iostream>
#include <vector>
using namespace std;

GLdouble width, height;
int wd;

// General colors
const color orangeRed(255/255.0, 94/255.0, 91/255.0);
const color lightGray(216/255.0, 216/255.0, 216/255.0);
const color robinEggBlue(0/255.0, 206/255.0, 203/255.0);
const color corn(255/255.0, 237/255.0, 102/255.0);
const color ivory(255/255.0, 255/255.0, 234/255.0);

// Colors
const color darkOliveGreen(96/255.0, 108/255.0, 56/255.0);
const color kombuGreen(40/255.0, 54/255.0, 24/255.0);
const color cornsilk(254/255.0, 250/255.0, 224/255.0);
const color fawn(221/255.0, 161/255.0, 94/255.0);
const color liverDog(188/255.0, 108/255.0, 37/255.0);

// Love colors
const color persianPlum(102/255.0, 16/255.0, 31/255.0);
const color paradisePink(238/255.0, 66/255.0, 102/255.0);
const color melon(255/255.0, 174/255.0, 163/255.0);
const color violetRed(239/255.0, 88/255.0, 148/255.0);
const color peachPuff(241/255.0, 214/255.0, 184/255.0);

// Family colors
const color charcoal(38/255.0, 70/255.0, 83/255.0);
const color persianGreen(42/255.0, 157/255.0, 143/255.0);
const color orangeYellow(233/255.0, 196/255.0, 106/255.0);
const color shandyBrown(244/255.0, 162/255.0, 97/255.0);
const color burntSienna(231/255.0, 111/255.0, 81/255.0);

const vector<color> financeColors = {darkOliveGreen, kombuGreen, cornsilk, fawn, liverDog};
const vector<color> loveColors = {persianPlum, paradisePink, melon, violetRed, peachPuff};
const vector<color> familyColors = {charcoal, persianGreen, orangeYellow, shandyBrown, burntSienna};
const vector<vector<color>> palettes = {financeColors, loveColors, familyColors};
vector<Button> categoryButtons;
Wheel fortuneWheel;

enum screenMode{
    intro,
    categoryChoice,
    spin,
    presentFortune
};

screenMode screen = intro;
Categories category;
string fileName = "Default_file.txt";
vector<Rect> background;
bool turn = true;
string fortune;
Rect pin;

void initCategoryButtons() {
    dimensions size{width/4, height/4};
    point2D center1 {width/4, height/4};
    point2D center2 {2*width/4, 2*height/4};
    point2D center3 {3*width/4, 3*height/4};
    categoryButtons.push_back(Button(financeColors[0], center1, size, "Finance"));
    categoryButtons.push_back(Button(loveColors[0], center2, size, "Love"));
    categoryButtons.push_back(Button(familyColors[0], center3, size, "Family"));

}

void initWheel() {
    fortuneWheel.setCenter(width/2, height/2);
    fortuneWheel.setPallets(palettes);
    fortuneWheel.setRadius(height/3);
    fortuneWheel.setFilename(fileName);
    fortuneWheel.setCategory(category);
    fortuneWheel.setNumFortunes();
    fortuneWheel.populate();
}

void initPin() {
    pin.setColor(lightGray);
    pin.setSize(50, 100);
    pin.setCenter(width/2, height/6);
}

void initBackground() {
    point2D center = {width/2, height/2};
    background.push_back(Rect(orangeRed, center, {width, height}));
    background.push_back(Rect(lightGray, center, {width-50, height-50}));
    background.push_back(Rect(robinEggBlue, center, {width-100,height-100}));
    background.push_back(Rect(corn, center, {width-150, height-150}));
    background.push_back(Rect(ivory, center, {width-200, height-200}));
}

void init() {
    width = 800;
    height = 800;
    initCategoryButtons();
    initBackground();
    initPin();
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(227/255.0, 181/255.0, 164/255.0, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // Tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE (unless you're on a Mac running Catalina)
    
    // Do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

    // Clear the color buffer with current clearing color
    glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE
    
    /*
     * Draw here
     */
    vector<string> message;
    int hChange = - 120;
    switch (screen) {
        case intro:
            for (Rect r : background) {
                r.draw();
            }
            message.push_back("Welcome to the Fortune Teller!");
            message.push_back("");
            message.push_back("Your fortune, in the category of your choosing, ");
            message.push_back("will be predicted by the fortune teller.");
            message.push_back("Please do not hold the fortune teller accountable");
            message.push_back("for any misfortune or inconsistencies.");
            message.push_back("Thank you.");
            message.push_back("");
            message.push_back("Press the spacebar to continue.");
            glColor3f(0.0, 0.0, 40 / 255.0);
            for (string s : message) {
                glRasterPos2i(width / 2 - (4.5 * s.length()), height / 2 + hChange);
                for (const char &letter : s) {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
                }
                hChange += 24;
            }
            break;
        case categoryChoice:
            message.clear();
            hChange = 0;
            message.push_back("You may choose a category for your fortune. ");
            message.push_back("Click on any of the buttons to continue to");
            message.push_back("THE WHEEL OF FORTUNE!");
            glColor3f(0.0, 0.0, 40 / 255.0);
            for (string s : message) {
                glRasterPos2i( 2 * width / 5, height / 6 + hChange);
                for (const char &letter : s) {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
                }
                hChange += 24;
            }
            for (Button b : categoryButtons) {
                b.draw();
            }
            break;
        case spin:
            message.clear();
            hChange = 0;
            message.push_back("THE WHEEL OF FORTUNE is thinking.");
            message.push_back("");
            message.push_back("Right-click to make the wheel decide.");
            message.push_back("Then left-click to reveal your future.");
            glColor3f(0.0, 0.0, 40 / 255.0);
            for (string s : message) {
                glRasterPos2i( 10, height / 10 + hChange);
                for (const char &letter : s) {
                    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
                }
                hChange += 18;
            }
            fortuneWheel.draw();
            pin.draw();
            break;
        case presentFortune:
            for (Rect r : background) {
                r.draw();
            }
            message.clear();
            hChange = -24;
            message.push_back("THE WHEEL OF FORTUNE has predicted your future!");
            message.push_back("");
            message.push_back(fortune);
            glColor3f(0.0, 0.0, 40 / 255.0);
            for (string s : message) {
                glRasterPos2i( width / 2 - (6 * s.length()), height / 2 + hChange);
                for (const char &letter : s) {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
                }
                hChange += 24;
            }
            break;
    }
    
    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }
    switch (screen) {
        case intro:
            if (key == 32) {
                screen = categoryChoice;
            }
            break;
    }
    
    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            
            break;
        case GLUT_KEY_LEFT:
            
            break;
        case GLUT_KEY_RIGHT:
            
            break;
        case GLUT_KEY_UP:
            
            break;
    }
    
    glutPostRedisplay();
}

void cursor(int x, int y) {
    int index = 0;
    switch (screen) {
        case intro:

            break;
        case categoryChoice:
            if (categoryButtons[0].isOverlapping(x, y)) {
                categoryButtons[0].hover();
            } else {
                categoryButtons[0].release();
            }
            if (categoryButtons[1].isOverlapping(x, y)) {
                categoryButtons[1].hover();
            } else {
                categoryButtons[1].release();
            }
            if (categoryButtons[2].isOverlapping(x, y)) {
                categoryButtons[2].hover();
            } else {
                categoryButtons[2].release();
            }
            break;
        case spin:
            break;
        case presentFortune:

            break;
    }
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    switch (screen) {
        case intro:

            break;
        case categoryChoice:
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
                if (categoryButtons[0].isOverlapping(x, y)) {
                    categoryButtons[0].pressDown();
                    category = Finance;
                    initWheel();
                    screen = spin;
                } else {
                    categoryButtons[0].release();
                }
                if (categoryButtons[1].isOverlapping(x, y)){
                    categoryButtons[1].pressDown();
                    category = Love;
                    initWheel();
                    screen = spin;
                } else {
                    categoryButtons[1].release();
                }
                if (categoryButtons[2].isOverlapping(x, y)){
                    categoryButtons[2].pressDown();
                    category = Family;
                    initWheel();
                    screen = spin;
                } else {
                    categoryButtons[2].release();
                }
            }
            break;
        case spin:
            if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
                turn = false;
                fortune = fortuneWheel.chooseFortune();
            }
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
                screen = presentFortune;
            }
            break;
        case presentFortune:

            break;
    }
    glutPostRedisplay();
}

void timer(int dummy) {
    switch(screen) {
        case spin:
            if (turn == true) {
                fortuneWheel.spin(PI / 100);
            }
            break;
    }
    glutPostRedisplay();
    glutTimerFunc(1, timer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    
    init();
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(350, 0); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Fortune Teller" /* title */ );
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    
    // Our own OpenGL initialization
    initGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    
    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);
    
    // handles mouse movement
    glutPassiveMotionFunc(cursor);
    
    // handles mouse click
    glutMouseFunc(mouse);
    
    // handles timer
    glutTimerFunc(0, timer, 0);
    
    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
