//http://www.codeincodeblock.com/2012/05/simple-method-for-texture-mapping-on.html

#ifndef IMAGE_LOADER_H_INCLUDED
#define IMAGE_LOADER_H_INCLUDED

//Represents an image
class Image {
public:
	Image(char* ps, int w, int h);
	~Image(); // Deconstructor
	char* pixels;
	int width;
	int height;
};

//Reads a bitmap image from file.
Image* loadBMP(const char* filename);

#endif
