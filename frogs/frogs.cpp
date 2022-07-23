//algorythm for calculating population fluctuation, based on the formula given in
//"the curious incident of the dog in the night-time" pages 101-102
//Ericka Florio, created July 22 2022

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
    //mission control, where you set all the parameters
    printf("Starting program.\n");
    double num=0.4; //starting number, between 0 and 1
    double numn; //loop variable
    double lam=4; //coupling constant
    int top=100; //max number of steps

    //opening a print file for the results
    FILE *fi;
    fi=fopen("frogs4.dat","w");

    // le loup
    for(int count=0; count<top; count++)
    {
        numn=lam*(num)*(1-num); //mathy bit
        if(numn<0. || numn>1.){
            printf("N broke out of bounds at step %i. Terminating session.\n", count); //just in case...
            break;
        }

        fprintf(fi, "%le\n", numn);//print the result
        num=numn;//reset the loop
        numn=0.;//cause memory or something
    }

    printf("End program. Final number is %le.\n",num);//yeet
    fclose(fi);
}