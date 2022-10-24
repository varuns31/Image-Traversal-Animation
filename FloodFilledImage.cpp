#include "cs225/PNG.h"
#include <list>
#include <iostream>

#include "colorPicker/ColorPicker.h"
#include "imageTraversal/ImageTraversal.h"

#include "Point.h"
#include "Animation.h"
#include "FloodFilledImage.h"

using namespace cs225;

/**
 * Constructs a new instance of a FloodFilledImage with a image `png`.
 * 
 * @param png The starting image of a FloodFilledImage
 */
FloodFilledImage::FloodFilledImage(const PNG & png) {
  /** @todo [Part 2] */
  this->png=png;
}

/**
 * Adds a FloodFill operation to the FloodFillImage.  This function must store the operation,
 * which will be used by `animate`.
 * 
 * @param traversal ImageTraversal used for this FloodFill operation.
 * @param colorPicker ColorPicker used for this FloodFill operation.
 */
void FloodFilledImage::addFloodFill(ImageTraversal & traversal, ColorPicker & colorPicker) {
  /** @todo [Part 2] */
  pickertraversal add;
  add.colorptr=&colorPicker;
  add.traversalptr=&traversal;
  flood.push_back(add);
}

/**
 * Creates an Animation of frames from the FloodFill operations added to this object.
 * 
 * Each FloodFill operation added by `addFloodFill` is executed based on the order
 * the operation was added.  This is done by:
 * 1. Visiting pixels within the image based on the order provided by the ImageTraversal iterator and
 * 2. Updating each pixel to a new color based on the ColorPicker
 * 
 * While applying the FloodFill to the image, an Animation is created by saving the image
 * after every `frameInterval` pixels are filled.  To ensure a smooth Animation, the first
 * frame is always the starting image and the final frame is always the finished image.
 * 
 * (For example, if `frameInterval` is `4` the frames are:
 *   - The initial frame
 *   - Then after the 4th pixel has been filled
 *   - Then after the 8th pixel has been filled
 *   - ...
 *   - The final frame, after all pixels have been filed)
 */ 
Animation FloodFilledImage::animate(unsigned frameInterval) const {
  Animation animation;
  /** @todo [Part 2] */
  animation.addFrame(png);
  PNG temp=png;
   unsigned j = 0;
   Point pt;

  for (unsigned i = 0; i < flood.size(); i++) 
  {

    for(ImageTraversal::Iterator ptr=flood[i].traversalptr->begin();ptr!=flood[i].traversalptr->end();++ptr) 
    {
      pt=*(ptr); 
      if(j == frameInterval) 
      {
        animation.addFrame(temp);
        j = 0;
      }

      HSLAPixel& original = temp.getPixel(pt.x, pt.y);
      HSLAPixel pixel = flood[i].colorptr->getColor(pt.x, pt.y);

      original.h = pixel.h;
      original.s = pixel.s;
      original.l = pixel.l;
      original.a = pixel.a;

      j++;

    }

    animation.addFrame(temp);

  }

  return animation;
}