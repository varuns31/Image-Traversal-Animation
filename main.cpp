#include "cs225/PNG.h"
#include "FloodFilledImage.h"
#include "Animation.h"

#include "imageTraversal/DFS.h"
#include "imageTraversal/BFS.h"

#include "colorPicker/RainbowColorPicker.h"
#include "colorPicker/GradientColorPicker.h"
#include "colorPicker/GridColorPicker.h"
#include "colorPicker/SolidColorPicker.h"
#include "colorPicker/MyColorPicker.h"

using namespace cs225;

int main() {

  // @todo [Part 3]
  // - The code below assumes you have an Animation called `animation`
  // - The code provided below produces the `myFloodFill.png` file you must
  //   submit Part 3 of this assignment -- uncomment it when you're ready.
  
  PNG myPNG;
  myPNG.readFromFile("tests/pacman.png");

  DFS myDFS(myPNG, Point(0,0), 0.5);
  BFS myBFS(myPNG, Point(50, 90), 0.3);

  HSLAPixel bluecolor(239,1,0.5);
  HSLAPixel orangecolor(18,0.88,0.5);
  MyColorPicker myColorPicker(bluecolor,orangecolor,55);
  FloodFilledImage myFloodFill(myPNG);

  myFloodFill.addFloodFill(myDFS, myColorPicker);
  myFloodFill.addFloodFill(myBFS, myColorPicker);

  Animation animation = myFloodFill.animate(1000);

  PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  lastFrame.writeToFile("myFloodFill.png");
  animation.write("myFloodFill.gif");

  return 0;

}