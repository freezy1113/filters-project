#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];

void loadImage();
void saveImage();
void doSomethingForImage();
void filterblackandwhite();
void filterinvertimage();
void filtermergeimage();
void filterrotateimage();
void filterflipimage();

int main(){
    cout << "ahlan ya user ya habibi :)" << endl ;
    loadImage();
    cout << "pls enter file name of the image to process :" << endl;
    cout << "1- black and white filter" << endl ;
    cout << "2- invert filter" << endl ;
    cout << "3- merge filter" << endl ; 
    cout << "4- flip iamge" << endl ;
    cout << "5- rotate image " << endl ;
    int choice ;
    cin >> choice ;
    switch (choice){

        case 1 :
            filterblackandwhite() ;
            saveImage() ;
            break;

        case 2 :
            filterinvertimage() ;
            saveImage() ;
            break;

        case 3 :
            filtermergeimage() ;
            saveImage() ;
            break;

        case 4 : 
            filterflipimage() ;
            saveImage() ;
            break;

        case 5 :
            filterrotateimage() ;
            saveImage() ;
            break;
    } 

}

void loadImage(){
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void loadMERGEImage(){
    char imageFileName2[100];

    // Get gray scale image file name
    cout << "Enter the source image2 file name: ";
    cin >> imageFileName2;

    // Add to it .bmp extension and load image
    strcat(imageFileName2, ".bmp");
    readGSBMP(imageFileName2, image2);
}

//_________________________________________
void saveImage(){
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

//_________________________________________
void doSomethingForImage(){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            image[i][j] = 255;
        }
    }
}

void filterblackandwhite(){
    for(int i = 0 ; i < SIZE ; i++){
        for(int j = 0 ; j < SIZE ; j++){
            if( image[i][j] <= 127 ){
                image[i][j] = 0 ;
            }
            else {
                image[i][j] = 255 ; 
            }
        }
    }
}

void filterinvertimage(){
    for(int i = 0 ; i < SIZE ; i++){
        for (int j = 0 ; j < SIZE ; j++){
            image[i][j] = 255 - image[i][j] ;
        }
    }
}

void filtermergeimage(){
    
    loadMERGEImage() ;
    for(int i = 0 ; i < SIZE ;i++){
        for(int j = 0 ; j < SIZE ; j++){
            image[i][j] = ( image[i][j] + image2[i][j] ) * 0.5;
        }
    }
}

void filterrotateimage(){
    cout << "90" << endl ;
    cout << "180" << endl ;
    cout << "270" << endl ;
    unsigned char image2[SIZE][SIZE];
    int caserotate ;
    cin >> caserotate;

    switch(caserotate){

        case 90 :
            for(int i = 0 ; i < SIZE ; i++){
                for(int j = 0 ; j < SIZE ; j++){
                    image2[i][j] = image[i][j] ;
                }
            }
            for(int i = 0 ; i <  SIZE ; i++){
                for(int j = 0 ; j < SIZE ; j++){
                    image[i][j] = image2[255-j][i] ;
                }
            }


        case 180 :
            for(int i = 0 ; i < SIZE ; i++){
                for(int j = 0 ; j <  SIZE ; j++){
                    image2[i][j] = image[i][j] ;
                }
            }
            for(int i = 0 ; i <   SIZE ; i++){
                for(int j = 0 ; j < SIZE ; j++){
                    image[i][j] = image2[255-i][255-j] ;
                }
            }

        case 270 :
            for(int i = 0 ; i < SIZE ; i++){
                for(int j = 0 ; j < SIZE ; j++){
                    image2[i][j] = image[i][j] ;
                }
            }
            for(int i = 0 ; i <  SIZE ; i++){
                for(int j = 0 ; j < SIZE ; j++){
                    image[i][j] = image2[j][255 - i] ;
                }
            }
    }
}

void filterflipimage(){
    cout << "horizontally << 1 " << endl ;
    cout << "vertically << 2 " << endl ;
    unsigned char image2[SIZE][SIZE];
    int caseflipimage ;
    cin >> caseflipimage ;
    switch(caseflipimage){

        case 1 : 
            for(int i = 0 ; i < 255 ; i++){
                for(int j = 0 ; j < 255 ; j++){
                    image2[i][j] = image[i][j] ;
                }
            }
            for(int i = 0 ; i <  255 ; i++){
                for(int j = 0 ; j < 255 ; j++){
                    image[i][j] = image2[i][256-j] ;
                }
            }

        case 2 :
            for(int i = 0 ; i < 255 ; i++){
                for(int j = 0 ; j < 255 ; j++){
                    image2[i][j] = image[i][j] ;
                }
            }
            for(int i = 0 ; i <  255 ; i++){
                for(int j = 0 ; j < 255 ; j++){
                    image[i][j] = image2[256-i][j] ;
                }
            }
    }
}
