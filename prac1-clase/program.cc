
/*#include <stdint.h>
#include <iostream>


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main() {
    int width, height, bpp;

    uint8_t* rgb_image = stbi_load("image.png", &width, &height, &bpp, 3);

    stbi_image_free(rgb_image);
    std::cout<<"Hello"<<std::endl;
    return 0;
}*/
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <sstream>
int main(){
    /*Leer imagen y ponerle filtro*/
    /*std::ofstream image;
    image.open("Apple.ppm");

    srand(time(0));
    if(image.is_open()){

        //inicializar imagen
        image <<"P3"<< std::endl;
        image <<"250 250"<< std::endl;
        image <<"255"<< std::endl;

        //llenar imagen mediante doble for
        for(int y=0; y < 250 ; y++ ){
            for(int x=0; x < 250 ; x++ ){
                image<< rand() % 255 << " " << rand() % 255 << " " << rand() % 255 <<std::endl;
            }
        }


    }*/
    //ESCRIBIR EN IMAGEN
    std::ifstream image;
    std::ofstream newImage;
    image.open("Apple.ppm");
    newImage.open("newImage.ppm");

    //Initialize
    std::string type = "", width = "", height = "", RGB = "";
    image >> type;
    image >> width;
    image >> height;
    image >> RGB;
    std::cout<<type<<" "<<width<<" "<<height<<" "<<RGB<<std::endl;
    
    newImage << type <<std::endl;
    newImage << width<<" "<<height<<std::endl;
    newImage << RGB <<std::endl;

    //Aplicamos filtro
    std::string red="", green ="" , blue="";
    int r=0,g=0,b=0;
    while(!image.eof()){
        image >> red;
        image >> green;
        image >> blue;

        std::stringstream redstream(red);
        std::stringstream greenstream(green);
        std::stringstream bluestream(blue);
        redstream >> r;
        greenstream >> g;
        bluestream >> b;

        if(b+50 >= 255){
            b=255;
        }else{
            b+=50;
        }
        newImage <<r <<" "<<g<<" "<<b<<std::endl;

    }

    image.close();
    newImage.close();
    return 0;
}


