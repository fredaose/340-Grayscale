# 340-Grayscale
Assignment 1 - Grayscale Image Converter


Due: February 6

Objective

To gain experience with C++ programming including classes, multi-dimensional arrays, program parameters, and the UNIX environment.

Task

For this program, you will write a program that converts images from full color into grayscale.

The PPM Image Format

Most image file formats write the image data in binary, and utilize compression in order to keep the file sizes small. Unfortunately, this makes reading them in quite difficult. In contrast, the PPM image format is textual and quite simple and easy to work with.

A PPM image file contains the following:

A line containing “P3”. This is a marker that identifies the file as being a PPM image.
A line contains two integers, separated by a space. These are the width and the height of the image. You can assume that the width and height will both be 500.
A line with one integer, the maximum color value for the image. This should be the value 255.
The rest of the file is composed of 3×W×H
3
×
W
×
H
 values which give the color data of the image. There is one set of three values for each pixel - each is an integer between 0 and 255. The first of these is the red component, the second is the green, and the third is the blue. Together these three values represent the color value for one pixel. The color values will be separated by whitespace.
Grayscale Conversion

To convert an image to grayscale, you can simply average the red, green and blue values for a given pixel, then write that value over the red, green and blue values.

For example, if a pixel has a red value of 250, a green value of 100, and a blue value of 10, it will be a bright orange color. If we wish to convert the color to grayscale, we average 250, 100 and 10 which gives us 120. If we set the red, green and blue values all to 120, we get a gray color roughly as bright as the orange.

If we apply this process to each of the pixels in the image, it will be grayscale.

Sample Images

Below are some sample images you can use to test your program:

Input Image	PNG Version	Expected Output	PNG Version
eagle.ppm	eagle.png	eagle-gray.ppm	eagle-gray.png
trinkle.ppm	trinkle.png	trinkle-gray.ppm	trinkle-gray.png
snow.ppm	snow.png	snow-gray.ppm	snow-gray.png
Program Details

Your program should take the input file name as a program parameter as discussed in class.
You will need to load a PPM image file into a 2D array. If the file is not found, print an error message and exit.
You should create a class to represent a single pixel. It should include the red, green and blue color components as member data.
You should store the image as a 2D array of these pixel objects.
You will then need to write code to apply the grayscale conversion to the 2D array of color objects.
You will then need to write the data back to a file named “grayscale.ppm”. You must make sure that you follow the PPM image format exactly when writing the file so it can be viewed correctly!
Testing

In order to test your program’s output, you will need to view the images. It will be easiest to first convert them from the PPM image format into a more common one, such as PNG. To do this on Linux, you can use the convert command:

$ convert grayscale.ppm grayscale.png
You can then do one of the following:

View Them in the B13 Lab

If you are in the B13 lab computers, you can simply open a file browser, navigate to the directory where your program is, and open the image file.

Copy Them to Your Local Machine

You can use a file transfer program (such as FileZilla) to connect to cs, and copy the files to your local machine to view them.

View Them Over the Web

You can create a directory in your home directory called ‘public_html’, and place the image files there. You can then view the image files with a web browser by navigating to “cs.umw.edu/~username/grayscale.png”.

If you have trouble with any of these, please let me know. It is heavily recommended to start the assignment early so that you can be sure you can test your program!

Extra Credit

For extra credit, you can perform any other kind of image manipulation effect you wish. Examples might include flipping the image, lightening, darkening, applying Instagram-like filters etc. If you complete an extra credit effect, you should write the modified image to a file called “extra.ppm”. You also must briefly describe the effect in your email submission.

General Requirements

No global variables other than constants.
All member data of a class must be private.
Your source code should be readable and reasonably indented.
You must provide comments in your code.
