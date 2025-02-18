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
void filterDarkenandLightenImage();
void filterdetectimage();
void filterEnlargeImage();
void filterblurimage();

int main(){ 
    cout << "ahlan ya user ya habibi :)" << endl ;
    loadImage();
    cout << "pls enter file name of the image to process :" << endl;
    cout << "1- black and white filter" << endl ;
    cout << "2- invert filter" << endl ;
    cout << "3- merge filter" << endl ; 
    cout << "4- flip iamge" << endl ;
    cout << "5- rotate image " << endl ;
    cout << "6- darken and lighten image " << endl ;
    cout << "7- detect image edges " << endl ;
    cout << "8- enlarge image " << endl ;
    cout << "9- blur image " << endl ;
    cout << "exit >> 0 " ;
    int choice ;
    cin >> choice ;
    switch (choice){

        case 1 :
            filterblackandwhite() ;
            break;

        case 2 :
            filterinvertimage() ;
            break;

        case 3 :
            filtermergeimage() ;
            break;

        case 4 : 
            filterflipimage() ;
            break;

        case 5 :
            filterrotateimage() ;
            break;

        case 6 :
            filterDarkenandLightenImage() ;
            break;

        case 7 : 
            filterdetectimage() ;
            break;

        case 8 : 
            filterEnlargeImage() ;
            break;

        case 9 :
            filterblurimage() ;
            break;
    } 
    saveImage() ;

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

void filterDarkenandLightenImage(){
    int choice ;
    cout << "MAKE IT DARKER ---> 1" << endl ;
    cout << "MAKE IT LIGHTER ----> 2" << endl ;
    cin >> choice ;
    switch (choice){
        case 1 :
            for(int i = 0 ; i < SIZE ; i++){
                for(int j = 0 ; j < SIZE ; j++){
                    image[i][j] = image[i][j] / 2 ;
                }
            }
            break;
        case 2 :
            for(int i = 0 ; i < SIZE ; i++){
                for(int j = 0 ; j < SIZE ; j++){
                    if(image[i][j] <= 163){
                        image[i][j] = 255 ;
                    }
                    else{
                        image[i][j] = image[i][j] + 90 ;
                    }
                }
            }
            break;
    }

}

void filterdetectimage(){
    unsigned char detectimage[SIZE][SIZE] ;
    filterblackandwhite();
    for(int i = 0 ; i < SIZE ; i++){
        for(int j = 0 ; j < SIZE ; j++){
            detectimage[i][j] = 255 ;
        }
    }
    for (int i = 1; i < 255 ; i++) {
        for (int j = 1; j < 255 ; j++) {
            if (image[i][j] == 0) {
                if (image[i][j + 1] == 255 || image[i][j - 1] == 255 || image[i + 1][j] == 255 || image[i - 1][j] == 255) {
                    detectimage[i][j] = 0 ;
                }
            }
        }
    }
    for(int i = 0 ; i < SIZE ; i++){
        for(int j = 0 ; j < SIZE ; j++){
            image[i][j] = detectimage[i][j] ;
        }
    }
}

void filterEnlargeImage(){
    cout << "Which quarter do you want to enlarge 1 , 2 , 3 , 4 : ";
    int quarter;
    cin >> quarter;

    unsigned char enlargedImage[SIZE][SIZE];

    int rows , col ;
    switch (quarter) {
        case 1:
            rows = 0;
            col = 0;
            break;

        case 2: 
            rows = 0;
            col = SIZE / 2;
            break;

        case 3: 
            rows = SIZE / 2;
            col = 0;
            break;

        case 4:
            rows = SIZE / 2;
            col = SIZE / 2;
            break;

        default:
            cout << "Invalid quarter" << endl;
            break;
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            enlargedImage[i][j] = image[rows + i / 2][col + j / 2];
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = enlargedImage[i][j];
        }
    }
}

void filterblurimage(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = ( image [i][j] + image[i-1][j-1] + image[i-1][j] + image[i][j] + image[i-1][j+1] + image[i][j-1] + image[i+1][j-1] + image[i+1][j] + image[i][j+1] + image[i+1][j+1]) / 9 ;
        }
    }
}