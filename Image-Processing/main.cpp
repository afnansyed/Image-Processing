
//Reference for reading data from file: Prof. Fox Reading complex binary file Lecture; LAB 4&5
//Reference for writing to a file: Prof. Fox writing complex binary file Lecture; LAB 5

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ostream>
#include "Pixel.h"

using namespace std;
bool TestOne();
bool TestTwo();
bool TestThree();
bool TestFour();
bool TestFive();
bool TestSix();
bool TestSeven();
bool TestEightRed();
bool TestEightGreen();
bool TestEightBlue();
bool TestNine();
bool TestTen();

struct Header{
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;
    int numPixels;


};

//Read image data; Reference for this function: Prof. Fox Reading complex binary file Lecture
void readImage(string file, Header& headerObject, vector<Pixel>& pixel){
    ifstream inFile(file, ios_base::binary);

    inFile.read(&headerObject.idLength, sizeof(headerObject.idLength));
    inFile.read(&headerObject.colorMapType, sizeof(headerObject.colorMapType));
    inFile.read(&headerObject.dataTypeCode, sizeof(headerObject.dataTypeCode));

    inFile.read((char*)&headerObject.colorMapOrigin, sizeof(headerObject.colorMapOrigin));
    inFile.read((char*)&headerObject.colorMapLength, sizeof(headerObject.colorMapLength));
    inFile.read(&headerObject.colorMapDepth, sizeof(headerObject.colorMapDepth));

    inFile.read((char*)&headerObject.xOrigin, sizeof(headerObject.xOrigin));
    inFile.read((char*)&headerObject.yOrigin, sizeof(headerObject.yOrigin));
    inFile.read((char*)&headerObject.width, sizeof(headerObject.width));
    inFile.read((char*)&headerObject.height, sizeof(headerObject.height));

    inFile.read(&headerObject.bitsPerPixel, sizeof( headerObject.bitsPerPixel));
    inFile.read(&headerObject.imageDescriptor, sizeof(headerObject.imageDescriptor));

    headerObject.numPixels = (int) headerObject.width*headerObject.height;

    //read pixels
    for ( int i = 0; i < (headerObject.numPixels); i++) {
        unsigned char blue;
        inFile.read((char*)&blue, sizeof(blue));

        unsigned char green;
        inFile.read((char*)&green, sizeof(green));

        unsigned char red;
        inFile.read((char*)&red, sizeof(red));

        Pixel p(blue, green, red);

        pixel.push_back(p);  //store values in vector
    }
    inFile.close();
}


int main() {


    //---------------------TASK 1-------------------------//
    Header headerObject_1;
    vector<Pixel> pixel_1;

    readImage("input/layer1.tga", headerObject_1, pixel_1);

    Header headerObject_1p;
    vector<Pixel> pixel_1p;
    readImage("input/pattern1.tga", headerObject_1p, pixel_1p);

   //Write new image file; Reference for writing a file: Prof. Fox writing complex binary file Lecture
    ofstream out_1("output/part1.tga", ios_base::binary);

    out_1.write(&headerObject_1.idLength, sizeof(headerObject_1.idLength));
    out_1.write(&headerObject_1.colorMapType, sizeof(headerObject_1.colorMapType));
    out_1.write(&headerObject_1.dataTypeCode, sizeof(headerObject_1.dataTypeCode));

    out_1.write((char*)&headerObject_1.colorMapOrigin, sizeof(headerObject_1.colorMapOrigin));
    out_1.write((char*)&headerObject_1.colorMapLength, sizeof(headerObject_1.colorMapLength));
    out_1.write(&headerObject_1.colorMapDepth, sizeof(headerObject_1.colorMapDepth));

    out_1.write((char*)&headerObject_1.xOrigin, sizeof(headerObject_1.xOrigin));
    out_1.write((char*)&headerObject_1.yOrigin, sizeof(headerObject_1.yOrigin));
    out_1.write((char*)&headerObject_1.width, sizeof(headerObject_1.width));
    out_1.write((char*)&headerObject_1.height, sizeof(headerObject_1.height));

    out_1.write(&headerObject_1.bitsPerPixel, sizeof(headerObject_1.bitsPerPixel));
    out_1.write(&headerObject_1.imageDescriptor, sizeof(headerObject_1.imageDescriptor));

    for (int i = 0; i < (headerObject_1.numPixels); i++) {
        float blue_1 = (float) pixel_1[i].getBlue();
        float blue_2 = (float) pixel_1p[i].getBlue();
        float bs = blue_1/255;
        float bs_2 = blue_2/255;
        float bm = bs*bs_2;
        float b = (bm*255)+0.5f;
        unsigned char blue = (unsigned char) b;
        out_1.write((char*)&blue, sizeof(blue));

        float green_1 = (float) pixel_1[i].getGreen();
        float green_2 = (float) pixel_1p[i].getGreen();
        float gs = green_1/255;
        float gs_2 = green_2/255;
        float gm = gs*gs_2;
        float g = (gm*255)+0.5f;
        unsigned char green = (unsigned char) g;
        out_1.write((char*)&green, sizeof(green));

        float red_1 = (float) pixel_1[i].getRed();
        float red_2 = (float) pixel_1p[i].getRed();
        float rs = red_1/255;
        float rs_2 = red_2/255;
        float rm = rs*rs_2;
        float r = (rm*255)+0.5f;
        unsigned char red = (unsigned char) r;
        out_1.write((char*)&red, sizeof(red));

    }
    out_1.close();





    //--------------------------------TASK 2-----------------------//
    Header headerObject_2;
    vector<Pixel> pixel_2;
    readImage("input/layer2.tga", headerObject_2, pixel_2);

    Header headerObject_2p;
    vector<Pixel> pixel_2p;
    readImage("input/car.tga", headerObject_2p, pixel_2p);


    ofstream out_2("output/part2.tga", ios_base::binary);

    out_2.write(&headerObject_2p.idLength, sizeof(headerObject_2p.idLength));
    out_2.write(&headerObject_2p.colorMapType, sizeof(headerObject_2p.colorMapType));
    out_2.write(&headerObject_2p.dataTypeCode, sizeof(headerObject_2p.dataTypeCode));

    out_2.write((char*)&headerObject_2p.colorMapOrigin, sizeof(headerObject_2p.colorMapOrigin));
    out_2.write((char*)&headerObject_2p.colorMapLength, sizeof(headerObject_2p.colorMapLength));
    out_2.write(&headerObject_2p.colorMapDepth, sizeof(headerObject_2p.colorMapDepth));

    out_2.write((char*)&headerObject_2p.xOrigin, sizeof(headerObject_2p.xOrigin));
    out_2.write((char*)&headerObject_2p.yOrigin, sizeof(headerObject_2p.yOrigin));
    out_2.write((char*)&headerObject_2p.width, sizeof(headerObject_2p.width));
    out_2.write((char*)&headerObject_2p.height, sizeof(headerObject_2p.height));

    out_2.write(&headerObject_2p.bitsPerPixel, sizeof(headerObject_2p.bitsPerPixel));
    out_2.write(&headerObject_2p.imageDescriptor, sizeof(headerObject_2p.imageDescriptor));

    for ( int i = 0; i < (headerObject_2p.numPixels); i++) {
        float b_top = (float)pixel_2[i].getBlue();
        float b_bottom = (float)pixel_2p[i].getBlue();
        float b_sub = (b_bottom - b_top)+0.5f;
        if(b_sub < 0){
            b_sub = 0;
        }
        else if(b_sub > 255){
            b_sub = 255;
        }
        unsigned char blue = (unsigned char) b_sub;
        out_2.write((char*)&blue, sizeof(blue));


        float g_top = (float)pixel_2[i].getGreen();
        float g_bottom = (float)pixel_2p[i].getGreen();
        float g_sub = (g_bottom - g_top)+0.5f;
        if(g_sub < 0){
            g_sub = 0;
        }
        else if(g_sub > 255){
            g_sub = 255;
        }
        unsigned char green = (unsigned char) g_sub;
        out_2.write((char*)&green, sizeof(green));

        float r_top = (float)pixel_2[i].getRed();
        float r_bottom = (float)pixel_2p[i].getRed();
        float r_sub = (r_bottom - r_top)+0.5f;
        if(r_sub < 0){
            r_sub = 0;
        }
        else if(r_sub > 255){
            r_sub = 255;
        }
        unsigned char red = (unsigned char) r_sub;
        out_2.write((char*)&red, sizeof(red));

    }
    out_2.close();





//---------------------TASK 3--------------------------//


    Header headerObject_3p;
    vector<Pixel> pixel_3p;
    readImage("input/pattern2.tga", headerObject_3p, pixel_3p);

    ofstream out_3("output/part3a.tga", ios_base::binary);

    out_3.write(&headerObject_3p.idLength, sizeof(headerObject_3p.idLength));
    out_3.write(&headerObject_3p.colorMapType, sizeof(headerObject_3p.colorMapType));
    out_3.write(&headerObject_3p.dataTypeCode, sizeof(headerObject_3p.dataTypeCode));

    out_3.write((char*)&headerObject_3p.colorMapOrigin, sizeof(headerObject_3p.colorMapOrigin));
    out_3.write((char*)&headerObject_3p.colorMapLength, sizeof(headerObject_3p.colorMapLength));
    out_3.write(&headerObject_3p.colorMapDepth, sizeof(headerObject_3p.colorMapDepth));

    out_3.write((char*)&headerObject_3p.xOrigin, sizeof(headerObject_3p.xOrigin));
    out_3.write((char*)&headerObject_3p.yOrigin, sizeof(headerObject_3p.yOrigin));
    out_3.write((char*)&headerObject_3p.width, sizeof(headerObject_3p.width));
    out_3.write((char*)&headerObject_3p.height, sizeof(headerObject_3p.height));

    out_3.write(&headerObject_3p.bitsPerPixel, sizeof(headerObject_3p.bitsPerPixel));
    out_3.write(&headerObject_3p.imageDescriptor, sizeof(headerObject_3p.imageDescriptor));

    for ( int i = 0; i < (headerObject_3p.numPixels); i++) {
        float blue_1 = (float) pixel_1[i].getBlue();
        float blue_2 = (float) pixel_3p[i].getBlue();
        float bs = blue_1/255;
        float bs_2 = blue_2/255;
        float bm = bs*bs_2;
        float b = (bm*255)+0.5f;
        unsigned char blue = (unsigned char) b;
        out_3.write((char*)&blue, sizeof(blue));

        float green_1 = (float) pixel_1[i].getGreen();
        float green_2 = (float) pixel_3p[i].getGreen();
        float gs = green_1/255;
        float gs_2 = green_2/255;
        float gm = gs*gs_2;
        float g = (gm*255)+0.5f;
        unsigned char green = (unsigned char) g;
        out_3.write((char*)&green, sizeof(green));

        float red_1 = (float) pixel_1[i].getRed();
        float red_2 = (float) pixel_3p[i].getRed();
        float rs = red_1/255;
        float rs_2 = red_2/255;
        float rm = rs*rs_2;
        float r = (rm*255)+0.5f;
        unsigned char red = (unsigned char) r;
        out_3.write((char*)&red, sizeof(red));

    }
    out_3.close();

    Header headerObject_3t;
    vector<Pixel> pixel_3t;
    readImage("input/text.tga", headerObject_3t, pixel_3t);


    Header headerObject_3a;
    vector<Pixel> pixel_3a;
    readImage("output/part3a.tga", headerObject_3a, pixel_3a);


    ofstream out_3t("output/part3.tga", ios_base::binary);

    out_3t.write(&headerObject_3a.idLength, sizeof(headerObject_3a.idLength));
    out_3t.write(&headerObject_3a.colorMapType, sizeof(headerObject_3a.colorMapType));
    out_3t.write(&headerObject_3a.dataTypeCode, sizeof(headerObject_3p.dataTypeCode));

    out_3t.write((char*)&headerObject_3a.colorMapOrigin, sizeof(headerObject_3a.colorMapOrigin));
    out_3t.write((char*)&headerObject_3a.colorMapLength, sizeof(headerObject_3a.colorMapLength));
    out_3t.write(&headerObject_3a.colorMapDepth, sizeof(headerObject_3a.colorMapDepth));

    out_3t.write((char*)&headerObject_3a.xOrigin, sizeof(headerObject_3a.xOrigin));
    out_3t.write((char*)&headerObject_3a.yOrigin, sizeof(headerObject_3a.yOrigin));
    out_3t.write((char*)&headerObject_3a.width, sizeof(headerObject_3a.width));
    out_3t.write((char*)&headerObject_3a.height, sizeof(headerObject_3a.height));

    out_3t.write(&headerObject_3a.bitsPerPixel, sizeof(headerObject_3a.bitsPerPixel));
    out_3t.write(&headerObject_3a.imageDescriptor, sizeof(headerObject_3a.imageDescriptor));

    for ( int i = 0; i < (headerObject_3a.numPixels); i++) {
        float blue_1 = (float) pixel_3a[i].getBlue();
        float blue_2 = (float) pixel_3t[i].getBlue();
        float bs = blue_1/255;
        float bs_2 = blue_2/255;
        float bm = 1-(1-bs)*(1-bs_2);
        float b = (bm*255)+0.5f;
        unsigned char blue = (unsigned char) b;
        out_3t.write((char*)&blue, sizeof(blue));

        float green_1 = (float) pixel_3a[i].getGreen();
        float green_2 = (float) pixel_3t[i].getGreen();
        float gs = green_1/255;
        float gs_2 = green_2/255;
        float gm = 1-(1-gs)*(1-gs_2);
        float g = (gm*255)+0.5f;
        unsigned char green = (unsigned char) g;
        out_3t.write((char*)&green, sizeof(green));

        float red_1 = (float) pixel_3a[i].getRed();
        float red_2 = (float) pixel_3t[i].getRed();
        float rs = red_1/255;
        float rs_2 = red_2/255;
        float rm = 1-(1-rs)*(1-rs_2);
        float r = (rm*255)+0.5f;
        unsigned char red = (unsigned char) r;
        out_3t.write((char*)&red, sizeof(red));

    }
    out_3t.close();






    //--------------------------------TASK 4--------------------------

    Header headerObject_4;
    vector<Pixel> pixel_4;
    readImage("input/circles.tga", headerObject_4, pixel_4);

    ofstream out_4("output/part4a.tga", ios_base::binary);

    out_4.write(&headerObject_4.idLength, sizeof(headerObject_4.idLength));
    out_4.write(&headerObject_4.colorMapType, sizeof(headerObject_4.colorMapType));
    out_4.write(&headerObject_4.dataTypeCode, sizeof(headerObject_4.dataTypeCode));

    out_4.write((char*)&headerObject_4.colorMapOrigin, sizeof(headerObject_4.colorMapOrigin));
    out_4.write((char*)&headerObject_4.colorMapLength, sizeof(headerObject_4.colorMapLength));
    out_4.write(&headerObject_4.colorMapDepth, sizeof(headerObject_4.colorMapDepth));

    out_4.write((char*)&headerObject_4.xOrigin, sizeof(headerObject_4.xOrigin));
    out_4.write((char*)&headerObject_4.yOrigin, sizeof(headerObject_4.yOrigin));
    out_4.write((char*)&headerObject_4.width, sizeof(headerObject_4.width));
    out_4.write((char*)&headerObject_4.height, sizeof(headerObject_4.height));

    out_4.write(&headerObject_4.bitsPerPixel, sizeof(headerObject_4.bitsPerPixel));
    out_4.write(&headerObject_4.imageDescriptor, sizeof(headerObject_4.imageDescriptor));

    for ( int i = 0; i < (headerObject_4.numPixels); i++) {
        float blue_1 = (float) pixel_2[i].getBlue();
        float blue_2 = (float) pixel_4[i].getBlue();
        float bs = blue_1/255;
        float bs_2 = blue_2/255;
        float bm = bs*bs_2;
        float b = (bm*255)+0.5f;
        unsigned char blue = (unsigned char) b;
        out_4.write((char*)&blue, sizeof(blue));

        float green_1 = (float) pixel_2[i].getGreen();
        float green_2 = (float) pixel_4[i].getGreen();
        float gs = green_1/255;
        float gs_2 = green_2/255;
        float gm = gs*gs_2;
        float g = (gm*255)+0.5f;
        unsigned char green = (unsigned char) g;
        out_4.write((char*)&green, sizeof(green));

        float red_1 = (float) pixel_2[i].getRed();
        float red_2 = (float) pixel_4[i].getRed();
        float rs = red_1/255;
        float rs_2 = red_2/255;
        float rm = rs*rs_2;
        float r = (rm*255)+0.5f;
        unsigned char red = (unsigned char) r;
        out_4.write((char*)&red, sizeof(red));
    }
    out_4.close();


    Header headerObject_4a;
    vector<Pixel> pixel_4a;
    readImage("output/part4a.tga", headerObject_4a, pixel_4a);

    ofstream out_4m("output/part4.tga", ios_base::binary);

    out_4m.write(&headerObject_4.idLength, sizeof(headerObject_4.idLength));
    out_4m.write(&headerObject_4.colorMapType, sizeof(headerObject_4.colorMapType));
    out_4m.write(&headerObject_4.dataTypeCode, sizeof(headerObject_4.dataTypeCode));

    out_4m.write((char*)&headerObject_4.colorMapOrigin, sizeof(headerObject_4.colorMapOrigin));
    out_4m.write((char*)&headerObject_4.colorMapLength, sizeof(headerObject_4.colorMapLength));
    out_4m.write(&headerObject_4.colorMapDepth, sizeof(headerObject_4.colorMapDepth));

    out_4m.write((char*)&headerObject_4.xOrigin, sizeof(headerObject_4.xOrigin));
    out_4m.write((char*)&headerObject_4.yOrigin, sizeof(headerObject_4.yOrigin));
    out_4m.write((char*)&headerObject_4.width, sizeof(headerObject_4.width));
    out_4m.write((char*)&headerObject_4.height, sizeof(headerObject_4.height));

    out_4m.write(&headerObject_4.bitsPerPixel, sizeof(headerObject_4.bitsPerPixel));
    out_4m.write(&headerObject_4.imageDescriptor, sizeof(headerObject_4.imageDescriptor));

    for ( int i = 0; i < (headerObject_4.numPixels); i++) {
        float b_top = (float)pixel_3p[i].getBlue();
        float b_bottom = (float)pixel_4a[i].getBlue();
        float b_sub = (b_bottom - b_top)+0.5f;
        if(b_sub < 0){
            b_sub = 0;
        }
        else if(b_sub > 255){
            b_sub = 255;
        }
        unsigned char blue = (unsigned char) b_sub;
        out_4m.write((char*)&blue, sizeof(blue));


        float g_top = (float)pixel_3p[i].getGreen();
        float g_bottom = (float)pixel_4a[i].getGreen();
        float g_sub = (g_bottom - g_top)+0.5f;
        if(g_sub < 0){
            g_sub = 0;
        }
        else if(g_sub > 255){
            g_sub = 255;
        }
        unsigned char green = (unsigned char) g_sub;
        out_4m.write((char*)&green, sizeof(green));

        float r_top = (float)pixel_3p[i].getRed();
        float r_bottom = (float)pixel_4a[i].getRed();
        float r_sub = (r_bottom - r_top)+0.5f;
        if(r_sub < 0){
            r_sub = 0;
        }
        else if(r_sub > 255){
            r_sub = 255;
        }
        unsigned char red = (unsigned char) r_sub;
        out_4m.write((char*)&red, sizeof(red));

    }
    out_4m.close();





    //----------------------TASK 5---------------------//


    ofstream out_5("output/part5.tga", ios_base::binary);

    out_5.write(&headerObject_1.idLength, sizeof(headerObject_1.idLength));
    out_5.write(&headerObject_1.colorMapType, sizeof(headerObject_1.colorMapType));
    out_5.write(&headerObject_1.dataTypeCode, sizeof(headerObject_1.dataTypeCode));

    out_5.write((char*)&headerObject_1.colorMapOrigin, sizeof(headerObject_1.colorMapOrigin));
    out_5.write((char*)&headerObject_1.colorMapLength, sizeof(headerObject_1.colorMapLength));
    out_5.write(&headerObject_1.colorMapDepth, sizeof(headerObject_1.colorMapDepth));

    out_5.write((char*)&headerObject_1.xOrigin, sizeof(headerObject_1.xOrigin));
    out_5.write((char*)&headerObject_1.yOrigin, sizeof(headerObject_1.yOrigin));
    out_5.write((char*)&headerObject_1.width, sizeof(headerObject_1.width));
    out_5.write((char*)&headerObject_1.height, sizeof(headerObject_1.height));

    out_5.write(&headerObject_1.bitsPerPixel, sizeof(headerObject_1.bitsPerPixel));
    out_5.write(&headerObject_1.imageDescriptor, sizeof(headerObject_1.imageDescriptor));

    for ( int i = 0; i < (headerObject_1.numPixels); i++) {
        float blue_1 = (float) pixel_1[i].getBlue();
        float blue_2 = (float) pixel_1p[i].getBlue();
        float bs = blue_1/255;
        float bs_2 = blue_2/255;
        float bm = 0.00f;
        if(bs_2 <= 0.5f){
            bm = 2*bs*bs_2;
        }
        else if (bs_2 > 0.5f){
            bm = 1-2*(1-bs)*(1-bs_2);
        }
        float b = (bm*255)+0.5f;
        unsigned char blue = (unsigned char) b;
        out_5.write((char*)&blue, sizeof(blue));

        float green_1 = (float) pixel_1[i].getGreen();
        float green_2 = (float) pixel_1p[i].getGreen();
        float gs = green_1/255;
        float gs_2 = green_2/255;
        float gm = 0.00f;
        if(gs_2 <= 0.5f){
            gm = 2*gs*gs_2;
        }
        else if (gs_2 > 0.5f){
            gm = 1-2*(1-gs)*(1-gs_2);
        }
        float g = (gm*255)+0.5f;
        unsigned char green = (unsigned char) g;
        out_5.write((char*)&green, sizeof(green));

        float red_1 = (float) pixel_1[i].getRed();
        float red_2 = (float) pixel_1p[i].getRed();
        float rs = red_1/255;
        float rs_2 = red_2/255;
        float rm = 0.00f;
        if(rs_2 <= 0.5f){
            rm = 2*rs*rs_2;
        }
        else if (rs_2 > 0.5f){
            rm = 1-2*(1-rs)*(1-rs_2);
        }
        float r = (rm*255)+0.5f;
        unsigned char red = (unsigned char) r;
        out_5.write((char*)&red, sizeof(red));

    }
    out_5.close();




    //----------------------TASK 6---------------------//

    Header headerObject_6;
    vector<Pixel> pixel_6;
    readImage("input/car.tga", headerObject_6, pixel_6);


    ofstream out_6("output/part6.tga", ios_base::binary);

    out_6.write(&headerObject_6.idLength, sizeof(headerObject_6.idLength));
    out_6.write(&headerObject_6.colorMapType, sizeof(headerObject_6.colorMapType));
    out_6.write(&headerObject_6.dataTypeCode, sizeof(headerObject_6.dataTypeCode));

    out_6.write((char*)&headerObject_6.colorMapOrigin, sizeof(headerObject_6.colorMapOrigin));
    out_6.write((char*)&headerObject_6.colorMapLength, sizeof(headerObject_6.colorMapLength));
    out_6.write(&headerObject_6.colorMapDepth, sizeof(headerObject_6.colorMapDepth));

    out_6.write((char*)&headerObject_6.xOrigin, sizeof(headerObject_6.xOrigin));
    out_6.write((char*)&headerObject_6.yOrigin, sizeof(headerObject_6.yOrigin));
    out_6.write((char*)&headerObject_6.width, sizeof(headerObject_6.width));
    out_6.write((char*)&headerObject_6.height, sizeof(headerObject_6.height));

    out_6.write(&headerObject_6.bitsPerPixel, sizeof(headerObject_6.bitsPerPixel));
    out_6.write(&headerObject_6.imageDescriptor, sizeof(headerObject_6.imageDescriptor));

    for ( int i = 0; i < (headerObject_6.numPixels); i++) {
        unsigned char blue = pixel_6[i].getBlue();
        out_6.write((char*)&blue, sizeof(blue));

        float g = (float)pixel_6[i].getGreen();
        float gAdd = g +200;
        if(gAdd < 0){
            gAdd = 0;
        }
        if(gAdd > 255){
            gAdd = 255;
        }
        unsigned char green = (unsigned char) gAdd;
        out_6.write((char*)&green, sizeof(green));

        unsigned char red = pixel_6[i].getRed();
        out_6.write((char*)&red, sizeof(red));

    }
    out_6.close();






//---------------------TASK 7------------------------//

    Header headerObject_7;
    vector<Pixel> pixel_7;

    readImage("input/car.tga", headerObject_7, pixel_7);

    ofstream out_7("output/part7.tga", ios_base::binary);

    out_7.write(&headerObject_7.idLength, sizeof(headerObject_7.idLength));
    out_7.write(&headerObject_7.colorMapType, sizeof(headerObject_7.colorMapType));
    out_7.write(&headerObject_7.dataTypeCode, sizeof(headerObject_7.dataTypeCode));

    out_7.write((char*)&headerObject_7.colorMapOrigin, sizeof(headerObject_7.colorMapOrigin));
    out_7.write((char*)&headerObject_7.colorMapLength, sizeof(headerObject_7.colorMapLength));
    out_7.write(&headerObject_7.colorMapDepth, sizeof(headerObject_7.colorMapDepth));

    out_7.write((char*)&headerObject_7.xOrigin, sizeof(headerObject_7.xOrigin));
    out_7.write((char*)&headerObject_7.yOrigin, sizeof(headerObject_7.yOrigin));
    out_7.write((char*)&headerObject_7.width, sizeof(headerObject_7.width));
    out_7.write((char*)&headerObject_7.height, sizeof(headerObject_7.height));

    out_7.write(&headerObject_7.bitsPerPixel, sizeof(headerObject_7.bitsPerPixel));
    out_7.write(&headerObject_7.imageDescriptor, sizeof(headerObject_7.imageDescriptor));

    for ( int i = 0; i < (headerObject_7.numPixels); i++) {
        float b = (float)pixel_7[i].getBlue()*0;
        unsigned char blue = (unsigned char) b;
        out_7.write((char*)&blue, sizeof(blue));

        unsigned char green = pixel_7[i].getGreen();
        out_7.write((char*)&green, sizeof(green));

        float r = (float)pixel_7[i].getRed();
        float rm = (r*4)+0.5f;
        if(rm < 0){
            rm = 0;
        }
        else if (rm > 255){
            rm = 255;
        }
        unsigned char red = (unsigned char) rm;
        out_7.write((char*)&red, sizeof(red));

    }
    out_7.close();





    //---------------------TASK 8------------------------//

    Header headerObject_8;
    vector<Pixel> pixel_8;
    readImage("input/car.tga", headerObject_8, pixel_8);

    ofstream out_8("output/part8_r.tga", ios_base::binary);

    out_8.write(&headerObject_8.idLength, sizeof(headerObject_8.idLength));
    out_8.write(&headerObject_8.colorMapType, sizeof(headerObject_8.colorMapType));
    out_8.write(&headerObject_8.dataTypeCode, sizeof(headerObject_8.dataTypeCode));

    out_8.write((char*)&headerObject_8.colorMapOrigin, sizeof(headerObject_8.colorMapOrigin));
    out_8.write((char*)&headerObject_8.colorMapLength, sizeof(headerObject_8.colorMapLength));
    out_8.write(&headerObject_8.colorMapDepth, sizeof(headerObject_8.colorMapDepth));

    out_8.write((char*)&headerObject_8.xOrigin, sizeof(headerObject_8.xOrigin));
    out_8.write((char*)&headerObject_8.yOrigin, sizeof(headerObject_8.yOrigin));
    out_8.write((char*)&headerObject_8.width, sizeof(headerObject_8.width));
    out_8.write((char*)&headerObject_8.height, sizeof(headerObject_8.height));

    out_8.write(&headerObject_8.bitsPerPixel, sizeof(headerObject_8.bitsPerPixel));
    out_8.write(&headerObject_8.imageDescriptor, sizeof(headerObject_8.imageDescriptor));

    for ( int i = 0; i < (headerObject_8.numPixels); i++) {
        unsigned char blue = pixel_8[i].getRed();
        out_8.write((char*)&blue, sizeof(blue));

        unsigned char green = pixel_8[i].getRed();
        out_8.write((char*)&green, sizeof(green));

        unsigned char red = pixel_8[i].getRed();
        out_8.write((char*)&red, sizeof(red));
    }
    out_8.close();


    ofstream out_8g("output/part8_g.tga", ios_base::binary);

    out_8g.write(&headerObject_8.idLength, sizeof(headerObject_8.idLength));
    out_8g.write(&headerObject_8.colorMapType, sizeof(headerObject_8.colorMapType));
    out_8g.write(&headerObject_8.dataTypeCode, sizeof(headerObject_8.dataTypeCode));

    out_8g.write((char*)&headerObject_8.colorMapOrigin, sizeof(headerObject_8.colorMapOrigin));
    out_8g.write((char*)&headerObject_8.colorMapLength, sizeof(headerObject_8.colorMapLength));
    out_8g.write(&headerObject_8.colorMapDepth, sizeof(headerObject_8.colorMapDepth));

    out_8g.write((char*)&headerObject_8.xOrigin, sizeof(headerObject_8.xOrigin));
    out_8g.write((char*)&headerObject_8.yOrigin, sizeof(headerObject_8.yOrigin));
    out_8g.write((char*)&headerObject_8.width, sizeof(headerObject_8.width));
    out_8g.write((char*)&headerObject_8.height, sizeof(headerObject_8.height));

    out_8g.write(&headerObject_8.bitsPerPixel, sizeof(headerObject_8.bitsPerPixel));
    out_8g.write(&headerObject_8.imageDescriptor, sizeof(headerObject_8.imageDescriptor));

    for ( int i = 0; i < (headerObject_8.numPixels); i++) {
        unsigned char blue = pixel_8[i].getGreen();
        out_8g.write((char*)&blue, sizeof(blue));

        unsigned char green = pixel_8[i].getGreen();
        out_8g.write((char*)&green, sizeof(green));

        unsigned char red = pixel_8[i].getGreen();
        out_8g.write((char*)&red, sizeof(red));

    }
    out_8g.close();



    ofstream out_8b("output/part8_b.tga", ios_base::binary);

    out_8b.write(&headerObject_8.idLength, sizeof(headerObject_8.idLength));
    out_8b.write(&headerObject_8.colorMapType, sizeof(headerObject_8.colorMapType));
    out_8b.write(&headerObject_8.dataTypeCode, sizeof(headerObject_8.dataTypeCode));

    out_8b.write((char*)&headerObject_8.colorMapOrigin, sizeof(headerObject_8.colorMapOrigin));
    out_8b.write((char*)&headerObject_8.colorMapLength, sizeof(headerObject_8.colorMapLength));
    out_8b.write(&headerObject_8.colorMapDepth, sizeof(headerObject_8.colorMapDepth));

    out_8b.write((char*)&headerObject_8.xOrigin, sizeof(headerObject_8.xOrigin));
    out_8b.write((char*)&headerObject_8.yOrigin, sizeof(headerObject_8.yOrigin));
    out_8b.write((char*)&headerObject_8.width, sizeof(headerObject_8.width));
    out_8b.write((char*)&headerObject_8.height, sizeof(headerObject_8.height));

    out_8b.write(&headerObject_8.bitsPerPixel, sizeof(headerObject_8.bitsPerPixel));
    out_8b.write(&headerObject_8.imageDescriptor, sizeof(headerObject_8.imageDescriptor));

    for ( int i = 0; i < (headerObject_8.numPixels); i++) {
        unsigned char blue = pixel_8[i].getBlue();
        out_8b.write((char*)&blue, sizeof(blue));

        unsigned char green = pixel_8[i].getBlue();
        out_8b.write((char*)&green, sizeof(green));

        unsigned char red = pixel_8[i].getBlue();
        out_8b.write((char*)&red, sizeof(red));
    }
    out_8b.close();






    //-----------------------TASK 9-----------------------//

    Header headerObject_9r;
    vector<Pixel> pixel_9r;
    readImage("input/layer_red.tga", headerObject_9r, pixel_9r);

    Header headerObject_9g;
    vector<Pixel> pixel_9g;
    readImage("input/layer_green.tga", headerObject_9g, pixel_9g);

    Header headerObject_9b;
    vector<Pixel> pixel_9b;
    readImage("input/layer_blue.tga", headerObject_9b, pixel_9b);

    ofstream out_9("output/part9.tga", ios_base::binary);

    out_9.write(&headerObject_9b.idLength, sizeof(headerObject_9b.idLength));
    out_9.write(&headerObject_9b.colorMapType, sizeof(headerObject_9b.colorMapType));
    out_9.write(&headerObject_9b.dataTypeCode, sizeof(headerObject_9b.dataTypeCode));

    out_9.write((char*)&headerObject_9b.colorMapOrigin, sizeof(headerObject_9b.colorMapOrigin));
    out_9.write((char*)&headerObject_9b.colorMapLength, sizeof(headerObject_9b.colorMapLength));
    out_9.write(&headerObject_9b.colorMapDepth, sizeof(headerObject_9b.colorMapDepth));

    out_9.write((char*)&headerObject_9b.xOrigin, sizeof(headerObject_9b.xOrigin));
    out_9.write((char*)&headerObject_9b.yOrigin, sizeof(headerObject_9b.yOrigin));
    out_9.write((char*)&headerObject_9b.width, sizeof(headerObject_9b.width));
    out_9.write((char*)&headerObject_9b.height, sizeof(headerObject_9b.height));

    out_9.write(&headerObject_9b.bitsPerPixel, sizeof(headerObject_9b.bitsPerPixel));
    out_9.write(&headerObject_9b.imageDescriptor, sizeof(headerObject_9b.imageDescriptor));

    for ( int i = 0; i < (headerObject_9b.numPixels); i++) {
        unsigned char blue = pixel_9b[i].getBlue();
        out_9.write((char*)&blue, sizeof(blue));

        unsigned char green = pixel_9g[i].getGreen();
        out_9.write((char*)&green, sizeof(green));

        unsigned char red = pixel_9r[i].getRed();
        out_9.write((char*)&red, sizeof(red));

    }
    out_9.close();






//-----------------------------TASK 10-------------------------------//

    Header headerObject_10;
    vector<Pixel> pixel_10;
    readImage("input/text2.tga", headerObject_10, pixel_10);

    ofstream out_10("output/part10.tga", ios_base::binary);

    out_10.write(&headerObject_10.idLength, sizeof(headerObject_10.idLength));
    out_10.write(&headerObject_10.colorMapType, sizeof(headerObject_10.colorMapType));
    out_10.write(&headerObject_10.dataTypeCode, sizeof(headerObject_10.dataTypeCode));

    out_10.write((char*)&headerObject_10.colorMapOrigin, sizeof(headerObject_10.colorMapOrigin));
    out_10.write((char*)&headerObject_10.colorMapLength, sizeof(headerObject_10.colorMapLength));
    out_10.write(&headerObject_10.colorMapDepth, sizeof(headerObject_10.colorMapDepth));

    out_10.write((char*)&headerObject_10.xOrigin, sizeof(headerObject_10.xOrigin));
    out_10.write((char*)&headerObject_10.yOrigin, sizeof(headerObject_10.yOrigin));
    out_10.write((char*)&headerObject_10.width, sizeof(headerObject_10.width));
    out_10.write((char*)&headerObject_10.height, sizeof(headerObject_10.height));

    out_10.write(&headerObject_10.bitsPerPixel, sizeof(headerObject_10.bitsPerPixel));
    out_10.write(&headerObject_10.imageDescriptor, sizeof(headerObject_10.imageDescriptor));

    for ( int i = (headerObject_10.numPixels-1); i >= 0; i--) {
        unsigned char blue = pixel_10[i].getBlue();
        out_10.write((char*)&blue, sizeof(blue));

        unsigned char green = pixel_10[i].getGreen();
        out_10.write((char*)&green, sizeof(green));

        unsigned char red = pixel_10[i].getRed();
        out_10.write((char*)&red, sizeof(red));

    }
    out_10.close();










    //----------------------TEST-----------------------//






    bool result = TestOne();
    if(result){
        cout << "Task 1 Passed" << endl;
    }

    result = TestTwo();
    if(result){
        cout << "Task 2 Passed" << endl;
    }

    result = TestThree();
    if(result){
        cout << "Task 3 Passed" << endl;
    }

    result = TestFour();
    if(result){
        cout << "Task 4 Passed" << endl;
    }

    result = TestFive();
    if(result){
        cout << "Task 5 Passed" << endl;
    }

    result = TestSix();
    if(result){
        cout << "Task 6 Passed" << endl;
    }

    result = TestSeven();
    if(result){
        cout << "Task 7 Passed" << endl;
    }

    result = TestEightRed();
    if(result){
        cout << "Task 8 Red Passed" << endl;
    }
    result = TestEightBlue();
    if(result){
        cout << "Task 8 Blue Passed" << endl;
    }
    result = TestEightGreen();
    if(result){
        cout << "Task 8 Green Passed" << endl;
    }
    result = TestNine();
    if(result){
        cout << "Task 9 Passed" << endl;
    }
    result = TestTen();
    if(result){
        cout << "Task 10 Passed" << endl;
    }



    return 0;
}

bool TestOne(){
    Header headerObject_test2;
    vector<Pixel> pixel_test2;
    readImage("output/part1.tga", headerObject_test2, pixel_test2);

    Header headerObject_test;
    vector<Pixel> pixel_test;
    readImage("examples/EXAMPLE_part1.tga", headerObject_test, pixel_test);

    bool s = true;



    for (int i = 0; i < (headerObject_test.numPixels); i++) {
        int red = (int) pixel_test[i].getRed();
        int red2 = (int) pixel_test2[i].getRed();

        int blue = (int) pixel_test[i].getBlue();
        int blue2 = (int) pixel_test2[i].getBlue();

        int green = (int) pixel_test[i].getGreen();
        int green2 = (int) pixel_test2[i].getGreen();

        if (red != red2) {

            s= false;
        }

        if (blue != blue2) {

            s= false;
        }

        if (green != green2) {

            s = false;
        }
    }

    return s;
}

bool TestTwo(){
    Header headerObject_test2;
    vector<Pixel> pixel_test2;
    readImage("output/part2.tga", headerObject_test2, pixel_test2);

    Header headerObject_test;
    vector<Pixel> pixel_test;
    readImage("examples/EXAMPLE_part2.tga", headerObject_test, pixel_test);

    bool s = true;


    for (int i = 0; i < (headerObject_test.numPixels); i++) {
        int red = (int) pixel_test[i].getRed();
        int red2 = (int) pixel_test2[i].getRed();

        int blue = (int) pixel_test[i].getBlue();
        int blue2 = (int) pixel_test2[i].getBlue();

        int green = (int) pixel_test[i].getGreen();
        int green2 = (int) pixel_test2[i].getGreen();

        if (red != red2) {

            s= false;
        }

        if (blue != blue2) {

            s= false;
        }

        if (green != green2) {

            s = false;
        }
    }

    return s;
}

bool TestThree(){
    Header headerObject_test2;
    vector<Pixel> pixel_test2;
    readImage("output/part3.tga", headerObject_test2, pixel_test2);

    Header headerObject_test;
    vector<Pixel> pixel_test;
    readImage("examples/EXAMPLE_part3.tga", headerObject_test, pixel_test);

    bool s = true;


    for (int i = 0; i < (headerObject_test.numPixels); i++) {
        int red = (int) pixel_test[i].getRed();
        int red2 = (int) pixel_test2[i].getRed();

        int blue = (int) pixel_test[i].getBlue();
        int blue2 = (int) pixel_test2[i].getBlue();

        int green = (int) pixel_test[i].getGreen();
        int green2 = (int) pixel_test2[i].getGreen();

        if (red != red2) {

            s= false;
        }

        if (blue != blue2) {

            s= false;
        }

        if (green != green2) {

            s = false;
        }
    }

    return s;
}

bool TestFour(){
    Header headerObject_test2;
    vector<Pixel> pixel_test2;
    readImage("output/part4.tga", headerObject_test2, pixel_test2);

    Header headerObject_test;
    vector<Pixel> pixel_test;
    readImage("examples/EXAMPLE_part4.tga", headerObject_test, pixel_test);

    bool s = true;

    for (int i = 0; i < (headerObject_test.numPixels); i++) {
        int red = (int) pixel_test[i].getRed();
        int red2 = (int) pixel_test2[i].getRed();

        int blue = (int) pixel_test[i].getBlue();
        int blue2 = (int) pixel_test2[i].getBlue();

        int green = (int) pixel_test[i].getGreen();
        int green2 = (int) pixel_test2[i].getGreen();

        if (red != red2) {

            s= false;
        }

        if (blue != blue2) {

            s= false;
        }

        if (green != green2) {

            s = false;
        }
    }

    return s;
}

bool TestFive(){
    Header headerObject_test2;
    vector<Pixel> pixel_test2;
    readImage("output/part5.tga", headerObject_test2, pixel_test2);

    Header headerObject_test;
    vector<Pixel> pixel_test;
    readImage("examples/EXAMPLE_part5.tga", headerObject_test, pixel_test);

    bool s = true;

    for (int i = 0; i < (headerObject_test.numPixels); i++) {
        int red = (int) pixel_test[i].getRed();
        int red2 = (int) pixel_test2[i].getRed();

        int blue = (int) pixel_test[i].getBlue();
        int blue2 = (int) pixel_test2[i].getBlue();

        int green = (int) pixel_test[i].getGreen();
        int green2 = (int) pixel_test2[i].getGreen();

        if (red != red2) {

            s= false;
        }

        if (blue != blue2) {

            s= false;
        }

        if (green != green2) {

            s = false;
        }
    }

    return s;
}

bool TestSix(){
    Header headerObject_test2;
    vector<Pixel> pixel_test2;
    readImage("output/part6.tga", headerObject_test2, pixel_test2);

    Header headerObject_test;
    vector<Pixel> pixel_test;
    readImage("examples/EXAMPLE_part6.tga", headerObject_test, pixel_test);

    bool s = true;

    for (int i = 0; i < (headerObject_test.numPixels); i++) {
        int red = (int) pixel_test[i].getRed();
        int red2 = (int) pixel_test2[i].getRed();

        int blue = (int) pixel_test[i].getBlue();
        int blue2 = (int) pixel_test2[i].getBlue();

        int green = (int) pixel_test[i].getGreen();
        int green2 = (int) pixel_test2[i].getGreen();

        if (red != red2) {

            s= false;
        }

        if (blue != blue2) {

            s= false;
        }

        if (green != green2) {

            s = false;
        }
    }

    return s;
}


bool TestSeven(){
    Header headerObject_test2;
    vector<Pixel> pixel_test2;
    readImage("output/part7.tga", headerObject_test2, pixel_test2);

    Header headerObject_test;
    vector<Pixel> pixel_test;
    readImage("examples/EXAMPLE_part7.tga", headerObject_test, pixel_test);

    bool s = true;



    for (int i = 0; i < (headerObject_test.numPixels); i++) {
        int red = (int) pixel_test[i].getRed();
        int red2 = (int) pixel_test2[i].getRed();

        int blue = (int) pixel_test[i].getBlue();
        int blue2 = (int) pixel_test2[i].getBlue();

        int green = (int) pixel_test[i].getGreen();
        int green2 = (int) pixel_test2[i].getGreen();

        if (red != red2) {

            s= false;
        }

        if (blue != blue2) {

            s= false;
        }

        if (green != green2) {

            s = false;
        }
    }

    return s;
}

bool TestEightRed(){
    Header headerObject_test2;
    vector<Pixel> pixel_test2;
    readImage("output/part8_r.tga", headerObject_test2, pixel_test2);

    Header headerObject_test;
    vector<Pixel> pixel_test;
    readImage("examples/EXAMPLE_part8_r.tga", headerObject_test, pixel_test);

    bool s = true;

    for (int i = 0; i < (headerObject_test.numPixels); i++) {
        int red = (int) pixel_test[i].getRed();
        int red2 = (int) pixel_test2[i].getRed();

        int blue = (int) pixel_test[i].getBlue();
        int blue2 = (int) pixel_test2[i].getBlue();

        int green = (int) pixel_test[i].getGreen();
        int green2 = (int) pixel_test2[i].getGreen();

        if (red != red2) {

            s= false;
        }

        if (blue != blue2) {

            s= false;
        }

        if (green != green2) {

            s = false;
        }
    }

    return s;
}

bool TestEightGreen(){
    Header headerObject_test2;
    vector<Pixel> pixel_test2;
    readImage("output/part8_g.tga", headerObject_test2, pixel_test2);

    Header headerObject_test;
    vector<Pixel> pixel_test;
    readImage("examples/EXAMPLE_part8_g.tga", headerObject_test, pixel_test);

    bool s = true;

    for (int i = 0; i < (headerObject_test.numPixels); i++) {
        int red = (int) pixel_test[i].getRed();
        int red2 = (int) pixel_test2[i].getRed();

        int blue = (int) pixel_test[i].getBlue();
        int blue2 = (int) pixel_test2[i].getBlue();

        int green = (int) pixel_test[i].getGreen();
        int green2 = (int) pixel_test2[i].getGreen();

        if (red != red2) {

            s= false;
        }

        if (blue != blue2) {

            s= false;
        }

        if (green != green2) {

            s = false;
        }
    }

    return s;
}


bool TestEightBlue(){
    Header headerObject_test2;
    vector<Pixel> pixel_test2;
    readImage("output/part8_b.tga", headerObject_test2, pixel_test2);

    Header headerObject_test;
    vector<Pixel> pixel_test;
    readImage("examples/EXAMPLE_part8_b.tga", headerObject_test, pixel_test);

    bool s = true;

    for (int i = 0; i < (headerObject_test.numPixels); i++) {
        int red = (int) pixel_test[i].getRed();
        int red2 = (int) pixel_test2[i].getRed();

        int blue = (int) pixel_test[i].getBlue();
        int blue2 = (int) pixel_test2[i].getBlue();

        int green = (int) pixel_test[i].getGreen();
        int green2 = (int) pixel_test2[i].getGreen();

        if (red != red2) {

            s= false;
        }

        if (blue != blue2) {

            s= false;
        }

        if (green != green2) {

            s = false;
        }
    }

    return s;
}

bool TestNine(){
    Header headerObject_test2;
    vector<Pixel> pixel_test2;
    readImage("output/part9.tga", headerObject_test2, pixel_test2);

    Header headerObject_test;
    vector<Pixel> pixel_test;
    readImage("examples/EXAMPLE_part9.tga", headerObject_test, pixel_test);

    bool s = true;

    for (int i = 0; i < (headerObject_test.numPixels); i++) {
        int red = (int) pixel_test[i].getRed();
        int red2 = (int) pixel_test2[i].getRed();

        int blue = (int) pixel_test[i].getBlue();
        int blue2 = (int) pixel_test2[i].getBlue();

        int green = (int) pixel_test[i].getGreen();
        int green2 = (int) pixel_test2[i].getGreen();

        if (red != red2) {

            s= false;
        }

        if (blue != blue2) {

            s= false;
        }

        if (green != green2) {

            s = false;
        }
    }

    return s;
}


bool TestTen(){
    Header headerObject_test2;
    vector<Pixel> pixel_test2;
    readImage("output/part10.tga", headerObject_test2, pixel_test2);

    Header headerObject_test;
    vector<Pixel> pixel_test;
    readImage("examples/EXAMPLE_part10.tga", headerObject_test, pixel_test);

    bool s = true;

    for (int i = 0; i < (headerObject_test.numPixels); i++) {
        int red = (int) pixel_test[i].getRed();
        int red2 = (int) pixel_test2[i].getRed();

        int blue = (int) pixel_test[i].getBlue();
        int blue2 = (int) pixel_test2[i].getBlue();

        int green = (int) pixel_test[i].getGreen();
        int green2 = (int) pixel_test2[i].getGreen();

        if (red != red2) {

            s= false;
        }

        if (blue != blue2) {

            s= false;
        }

        if (green != green2) {

            s = false;
        }
    }

    return s;
}

