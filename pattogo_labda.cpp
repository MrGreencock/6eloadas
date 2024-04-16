#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

char frame = '#';
int fW = 90;
int fH = 30;
int labdaX = rand() % 25 + 2;
int labdaY = rand() % 15 + 2;
int labdaSebx = 1;
int labdaSeby = 1;


void rajz() {
    labdaX += labdaSebx;
    labdaY += labdaSeby;

    if(labdaX == 1 || labdaX == fW-1){
        labdaSebx = -labdaSebx;
    }
    if(labdaY == 1 || labdaY == fH-1){
        labdaSeby = -labdaSeby;
    }

    system("cls");

    for (int i = 0; i < fH; i++){
        if(i == 0 || i == fH-1){
            for (int j = 0; j < fW; j++){
                cout << frame;
            }
        }
        else{
            cout << frame;
            for (int j = 1; j < fW-1; j++){
                if(labdaX == j && labdaY == i){
                    cout << "O";
                }
                else{
                    cout << " ";
                }
            }
            cout << frame;
        }
        cout << endl;

    }

    Sleep(10);

}

int main() {
    while(true){
        rajz();
    }
    return 0;
}
