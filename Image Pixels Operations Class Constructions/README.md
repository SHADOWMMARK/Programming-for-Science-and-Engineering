# Image Pixels Operations Class Constructions

this project will be using the object-oriented property of encapsulation using C++ classes. To be more specific, some classes abount image pixels operations would be constructed here for further use.

## Introductions
Colors are typically described as a combination of some amount of red, green, and blue (referred to as
“RGB” values). With different amounts of red, green, and blue, you can create any color. For example, the
color bright red would be represented as a full amount of red and no green and no blue, and a dimmer red
would be represented as less than a full amount of red with no green and no blue. Similarly, black is no red,
no green, and no blue, while white is full red, full green, and full blue. Other colors are obtained by mixing
the component colors, so yellow is obtained via full red, full green, and no blue, etc. The component color
values must be within a specified range, and the term “full red” (or green or blue) means the maximum
allowed color value, which for this project will be 1000, while the minimum allowed color value is 0.
An image is just a bunch of colors arranged in a rectangle. Because each individual color element (called a
pixel) is so small, your eyes and brain can interpret the rectangle of tiny pixel colors as an image. Since an
image is made up some number of rows and columns, the pixel color values are often stored as a twodimensional
array (rows being the first dimension, and columns being the second dimension).
Finally, we may want to refer to a specific pixel within the collection of pixels that make up an image. We
can do this with a row index and a column index to uniquely identify a specific pixel via its location.
For this project, you will implement the beginnings of three classes to represent colors, images, and
locations within an image. The classes are defined next.
