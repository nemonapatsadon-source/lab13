#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double Num[],int Size,double Ans[]){
    int i = 0;
    double Asum = 0;
    
    while (i < Size)
    {
        Asum += Num[i];
        i++;
    }
    
    double Amean = Asum/Size;

    double Ssum = 0;
    i = 0;

    while(i < Size){
        Ssum += pow((Num[i]-Amean),2);
        i++;
    }

    double Sd = pow((Ssum/Size),0.5);

    double Gsum = 1;
    i = 0;

    while (i < Size)
    {
        Gsum *= Num[i];
        i++;
    }
    
    double Gmean = pow(Gsum, 1.0 / Size);

    double Hsum = 0;
    i=0;

    while (i < Size)
    {
        Hsum += (1/Num[i]);
        i++;
    }
    
    double Hmean = Size/Hsum;

    double Max = Num[0],Min = Num[0];
    for(i=0;i<Size;i++){
        if(Num[i]>Max){ Max = Num[i];}
        if(Num[i]<Min){ Min = Num[i];}
    }
    Ans[0] = Amean;
    Ans[1] = Sd;
    Ans[2] = Gmean;
    Ans[3] = Hmean;
    Ans[4] = Max;
    Ans[5] = Min;
}