//
//  main.cpp
//  22
//
//  Created by Kubitski Vlad on 18.10.15.
//  Copyright (c) 2015 Kubitski Vlad. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;
int otvet(char* str);
int main()
{
    char* ver = new char [40];
    ver = "min(min(200,30),max(54,max(67,34)))";
    cout<<"otvet= "<<otvet(ver);
}
int otvet(char* str)
{
    char min[4] = "min";
    int k = 0;
    int u = 0;
    int t = 0;
    int chis [20] = {0};
    char znach[20] = {0};
    bool a = true;
    for (int i = 0; i < strlen(str); i++)
    {
        while ((str[i] != '(') && (str[i] != ')') && (str[i] != ',') && (str[i] != '\0'))
        {
            if (isdigit(str[i]))
            {
                while ((str[i] != '(') && (str[i] != ')') && (str[i] != ',') && (str[i] != '\0'))
                {
                chis[k] = ((chis[k] * 10) + (str[i] - '0'));
                    i++;
                }
                k++;
                if (str[i] != ')')
                {
                    i++;
                }
            }
            else
            {
                u = 0;
                for (int q = i; i < (q + 3); i++)
                {
                    if (min[u] == str[i])
                    {
                        a = true;
                    }
                    else
                    {
                        a = false;
                    }
                    u++;
                }
                if (a == true)
                {
                    znach[t] = 'n';
                    t++;
                }
                else
                {
                    znach[t] = 'x';
                    t++;
                }
            }
            
        }
        if (str[i] == ')')
        {
            if (znach[t-1] == 'x')
            {
                if (chis[k-1] >= chis[k-2])
                {
                    chis[k-2] = chis[k-1];
                    k--;
                }
                else
                {
                    chis[k-2] = chis[k-2];
                    k--;
                }
                t--;
            }
            if (znach[t-1] == 'n')
            {
                if (chis[k-1] >= chis[k-2])
                {
                    chis[k-2] = chis[k-2];
                    k--;
                }
                else
                {
                    chis[k-2] = chis[k-1];
                    k--;
                }
                t--;
            }

        }
    }
    return chis[0];
}
