#include <iostream>
#include <string>
#include <algorithm> 
#include "bmplib.cpp"
#include "bmplib.h"

using namespace std ;

int main(){
    unsigned char image [256][256] ;
    char inputname[100] ;
    string outputname ; 
    cout << "enter the target image " ;
    cin >> inputname ;
    strcat (inputname, ".bmp");
    while(true){
        if (readGSBMP(inputname,image) == 0 ){
            break;
        }
        else{
            cout << "ERROR enter file name again " ;
        }
    }
    cout << "ahlan ya user ya habibi :)" << endl ;
    cout << "pls enter file name of the image to process :" << endl;
    cout << "1- black and white filter" << endl ;
    cout << "2- invert filter" << endl ;
    cout << "3- merge filter" << endl ; 
    cout << "4- flip iamge" << endl ;
    cout << "5- darken and lighten image " << endl ;

     int choice ;
     cin >> choice ;
    switch (choice){

        case 1 :
            for(int i = 0 ; i < SIZE ; i++){
                for(int j = 0 ; j < 256 ; j++){
                    if( image[i][j] <= 127 ){
                        image[i][j] = 0 ;
                        
                    }
                    else {
                        image[i][j] = 256 ; 
                        cout << image[i][j] ;
                    }
                }
            }
            break;


            case 2 :
            for (int i = 0 ; i < 256 ; i++){
                for (int j = 0 ; j < 256 ; j++){
                    image[i][j] == image[256-i][256-j] ;
                    cout << image[i][j] ;
                }
            }
            break;

    }   
}
