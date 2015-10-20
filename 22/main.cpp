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
void assert(char str[100], int test)
{
	if (otvet(str) == test) cout << "OK" << endl;
	else cout << "FAIL" << endl;
}
int main()
{
   assert("90", 90);
	assert("max(4,min(3,5))", 4);
	assert("min(min(3,5),max(2,max(3,4)))", 3);
	assert("min(min(8,10),max(3,9))", 8);
	assert("max(1000,1011)", 1011);
	assert("max(10,10)", 10);
	return 0;
}
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
