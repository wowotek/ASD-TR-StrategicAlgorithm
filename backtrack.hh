#ifndef INCLUDE_BACKTRACK_HH
#define INCLUDE_BACKTRACK_HH

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <vector>

typedef std::vector<std::string> StringList;

std::string lowerCaseAlphabet = "abcdefghijklmnopqrstuvwxyz";
std::string upperCaseAlphabet = "ABCEDFGHIJKLMNOPQRSTUVWXYZ";

class NameGenerator{
    private:
        StringList dislikedKnownName;
        
        std::string _generateName(uint32_t);
    public:
        NameGenerator();
        std::string generateName(uint32_t);
        void printAllDislikedName();

};

// DEFINISI METHOD CLASS NAME GENERATOR
NameGenerator::NameGenerator(){
    srand(time(0));
}

std::string NameGenerator::_generateName(uint32_t length){
    std::string x = "";
    for(int i=0; i<length; i++){
        uint32_t randomNumber = 0;
        if(i == 0){
            for(int j=0; j<length*50; j++) randomNumber = rand() % upperCaseAlphabet.length();
            x += upperCaseAlphabet.at(randomNumber);
        } else {
            for(int j=0; j<length*50; j++) randomNumber = rand() % lowerCaseAlphabet.length();
            x += lowerCaseAlphabet.at(randomNumber);
        }
    }

    std::vector<std::string>::iterator iterator;
    for(iterator=dislikedKnownName.begin(); iterator<dislikedKnownName.end(); iterator++){
        if(x == *iterator){
            return _generateName(length);
        }
    }
    return x;
}

std::string NameGenerator::generateName(uint32_t length){
    std::string name = _generateName(length);
    std::cout << "Generated Name : " << name << std::endl;

    std::string input;
    std::cout << "Apakah anda Menyukai Namanya ? 'Y' untuk Ya 'N' untuk tidak : ";
    while(true){
        std::getline(std::cin, input);
        if(input == "Y" || input == "y"){
            return name;
        } else {
            std::cout << "Anda Tidak Suka Nama Ini. Dimengerti !" << std::endl << "Membuat Nama Lain..." << std::endl;
            dislikedKnownName.push_back(name);
            return generateName(length);
        }
    }
}

void NameGenerator::printAllDislikedName(){
    std::vector<std::string>::iterator iterator;
    int i = 0;
    std::cout << "Disliked Name :" << std::endl << "    ";
    for(iterator=dislikedKnownName.begin(); iterator<dislikedKnownName.end(); iterator++){
        std::cout << (*iterator) << " ";
        i++;
        if(i >= 10){
            std::cout << std::endl << "    ";
            i = 0;
        }
    }

    std::cout << std::endl;
}

#endif