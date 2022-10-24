#include "../cs225/HSLAPixel.h"
#include "../Point.h"

#include "ColorPicker.h"
#include "MyColorPicker.h"

using namespace cs225;

/**
 * Picks the color for pixel (x, y).
 * Using your own algorithm
 */
MyColorPicker::MyColorPicker(HSLAPixel color1, HSLAPixel color2,int percent):
color1(color1),color2(color2),percent(percent){}
HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
  color1.s=((color1.s*percent)+(color2.s*(100-percent)))/100;
  color1.l=((color1.l*percent)+(color2.l*(100-percent)))/100;
  color1.h=((color1.h*percent)+(color2.h*(100-percent)))/100;
  return color1;
}
