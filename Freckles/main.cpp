//
//  main.cpp
//  Freckles
//
//  Created by Zareek Galvan on 10/28/15.
//  Copyright © 2015 Trisquel Labs. All rights reserved.
//

#include <iostream>
#include <limits.h>
#include <math.h>
#include <iomanip>
using namespace std;

double f[100][100];
double arrX[100];
double arrY[100];
int p[100];
int key[100];
bool set[100];

double min(int n)
{
    double min = INT_MAX/4;
    double min_index;
    
    for (int v = 0; v < n; v++)
    {
        if (set[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    
    return min_index;
}

void printMST(int n)
{
    for (int i = 0; i < n; i++){
        if(p[i] == 0)
            cout << "A";
        else if(p[i] == 1)
            cout << "B";
        else if(p[i] == 2)
            cout << "C";
        else if(p[i] == 3)
            cout << "D";
        else if(p[i] == 4)
            cout << "E";
        else if(p[i] == 5)
            cout << "F";
        else if(p[i] == 6)
            cout << "G";
        else if(p[i] == 7)
            cout << "H";
        
        cout << " - ";
        
        if(i == 0)
            cout << "A";
        else if(i == 1)
            cout << "B";
        else if(i == 2)
            cout << "C";
        else if(i == 3)
            cout << "D";
        else if(i == 4)
            cout << "E";
        else if(i == 5)
            cout << "F";
        else if(i == 6)
            cout << "G";
        else if(i == 7)
            cout << "H";
        
        cout << " has weight " << f[i][p[i]] << endl;
        
    }
}

void inicializa(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int  j = 0; j < n; j++)
        {
            f[i][j] = INT_MAX/4;
        }
    }
    
    for (int i = 0; i < n; i++){
        key[i] = INT_MAX/4;
        set[i] = false;
        f[i][i] = 0;
        arrX[i] = 0;
        arrY[i] = 0;
    }
}

void Prim(int n)
{
    for (int count = 0; count < n; count++)
    {
        int j = min(n);
        
        set[j] = true;
        
        for (int v = 0; v < n; v++){
            
            if (f[j][v] && set[v] == false && f[j][v] <  key[v]){
                p[v]  = j;
                key[v] = f[j][v];
            }
        }
    }
    
    //printMST(n);
    //return f[0][p[0]];
}

int main()
{
    int freckles;
    cin >> freckles;
    
    inicializa(freckles);
    
    //Lee los datos y los pone en arreglos
    for (int i = 0; i < freckles; i++)
    {
        double x, y;
        cin >> x >> y;
        arrX[i] = x;
        arrY[i] = y;
        
    }
    
    //llena la matriz
    for (int i = 0; i < freckles; i++)
    {
        for (int j = i + 1; j < freckles; j++)
        {
            double valx = arrX[j] - arrX[i];
            double valy = arrY[j] - arrY[i];
            double distance = sqrt(valx*valx + valy*valy);
            f[i][j] = distance;
            f[j][i] = distance;
        }
    }
    cout << endl;
    for (int i = 0; i < freckles; i++)
    {
        for (int j = 0; j < freckles; j++)
        {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    Prim(freckles);
    int line = freckles/2;
    double acum;
    for (int i = 0; i < freckles; i++)
    {
        acum += f[line][i];
    }
    cout<<fixed<<setprecision(2);
    cout << acum << endl;
    
}