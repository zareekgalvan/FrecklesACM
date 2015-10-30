//
//  main.cpp
//  Freckles
//
//  Created by Zareek Galvan on 10/28/15.
//  Copyright © 2015 Trisquel Labs. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <iomanip>
using namespace std;

double graph[100][100];
double arrX[100], arrY[100];
int parent[100];
int key[100];
bool mstSet[100];

int minKey(int key[], bool mstSet[], int n)
{
    double min = INT_MAX/4, min_index;
    
    for (int v = 0; v < n; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    
    return min_index;
}

double suma(int n)
{
    double x;
    for (int i = 1; i < n; i++)
    {
        x += graph[i][(int)parent[i]];
    }
    return x;
}

void primMST(int n)
{
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX/4, mstSet[i] = false;
    }
    
    key[0] = 0;
    parent[0] = -1;
    
    for (int count = 0; count < n-1; count++)
    {
        int u = minKey(key, mstSet, n);
        
        mstSet[u] = true;
        
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
            {
                parent[v]  = u, key[v] = graph[u][v];
            }
        }
    }
}

int main()
{
    int freckles;
    cin >> freckles;
    
    for (int i = 0; i < freckles; i++)
    {
        double x, y;
        cin >> x >> y;
        arrX[i] = x;
        arrY[i] = y;
        
    }
    for (int i = 0; i < freckles; i++)
    {
        for (int j = 0; j < freckles; j++)
        {
            double valx = arrX[j] - arrX[i];
            double valy = arrY[j] - arrY[i];
            double distance = hypot(valx, valy);
            graph[i][j] = distance;
            graph[j][i] = distance;
        }
    }
    
    primMST(freckles);
    
    cout << fixed << setprecision(2);
    cout << suma(freckles) << endl;
    
    return 0;
}