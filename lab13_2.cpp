#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool B[][M]){
    cout << "------------------------------------------------------------------------\n";
    for(int j = 0 ; j < N ; j++){
        cout << "|";
        for(int i = 0 ; i < M ; i++){
            if(B[j][i] == 0){
                cout << " ";
            } else{
                cout << "*";
            }
        }
        cout << "|\n";
    }
    cout << "------------------------------------------------------------------------\n";

}

void updateImage(bool B[][M],int s,int x, int y){
    for(int j = 0; j < N ; j++){
        for(int i = 0 ; i < M ;i++){
            if(sqrt(pow(j-x, 2.0) + pow(i-y, 2.0)) <= s - 1){
                B[j][i] = 1 ;
            }
        }
    }
}

