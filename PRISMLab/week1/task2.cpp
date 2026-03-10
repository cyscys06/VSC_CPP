#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int WIDTH = 1280;
const int HEIGHT = 720;

int main() {
    ifstream original("C:/Users/user/Desktop/VSC_CPP/PRISMLab/week1/PeopleOnStreet_1280x720_30_Original.yuv", ios::binary);
    ofstream Yframe("C:/Users/user/Desktop/VSC_CPP/PRISMLab/week1/PeopleOnStreet_1280x720_30_Yframes.yuv", ios::binary); 

    int frameSize = WIDTH * HEIGHT;
    unsigned char* frame = new unsigned char[frameSize];

    for (int i = 0; i < 30; i++) {
        char* charCastFrame = (char*)frame;
        
        original.read(charCastFrame, frameSize); 
        Yframe.write(charCastFrame, frameSize);

        original.read(charCastFrame, frameSize/2);
    }
    
    original.close();
    Yframe.close();

    return 0;
}