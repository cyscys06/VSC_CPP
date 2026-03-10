#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int WIDTH = 1280;
const int HEIGHT = 720;

int main() {
    ifstream original("C:/Users/user/Desktop/VSC_CPP/PRISMLab/week1/PeopleOnStreet_1280x720_30_Original.yuv", ios::binary); 
    ofstream odd("C:/Users/user/Desktop/VSC_CPP/PRISMLab/week1/PeopleOnStreet_1280x720_15_Odd_frames.yuv", ios::binary); 

    int frameSize = WIDTH * HEIGHT * 3/2; 
    unsigned char* frame = new unsigned char[frameSize];
    
    for (int i = 0; i < 30; i++) {
        char* charCastFrame = (char*)frame;

        original.read(charCastFrame, frameSize); 
        
        if (i % 2 == 0) { 
            odd.write(charCastFrame, frameSize); 
        } 
    }
    
    original.close();
    odd.close();

    return 0;
}