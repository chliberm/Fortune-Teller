# The Fortune Telling Wheel 
## The Classes anf files
This program includes several class that inherit from the super class
"Shape". These classes include: the rectangle ("Rect) class, the "Button" class (which inherits from "Rect"),
the "Slice" class, and the "Wheel" class (inherits from "FortuneTeller" as well as shape). The program also 
contains a FortuneTeller class that mainly reads the fortunes given from a text file into the vector of strings 
corresponding to the specified category of fortune. A graphics source and header file are also included in the program,
and are used to execute the drawing and visual functionalities of the different shape classes. A default text file 
containing some fortunes is also included in the scope of this program. It is formatted in such a way that the category
is the first line, then the number of fortunes is listed, followed by all the fortunes in that category. Each category is
separated by an empty line.

## How the program 
There are four screen include. The user initially interacts with the introduction screen, where a short welcome message, along 
with simple instructions, is presented to the user. The user is then instructed to press the space-bar to continue to the next 
screen where they get to choose which category they would like to receive a fortune for. This page includes basic instructions 
and three buttons, one for each category (Finance, Love, and Family). Once the user left-clicks on a button, they are then brought
to THE WHEEL OF FORTUNE. This is where the different categories have an effect. First and foremost, the color palette changes 
based on the category. The number of "slices" in the wheel is also determine based on the number of fortunes, provided by the file,
for each category (which can be different). The wheel is already spinning when the user is moved to this screen, and it is their 
job to decide when to stop the wheel. The user is told to do so by right-clicking (anywhere). This will only stop the wheel, in 
order to see the fortune, the user must left-click the mouse to continue to the next screen, where the fortune corresponding to the 
slice that the pin is on, is presented to the user. 