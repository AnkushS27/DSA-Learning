// This question comes in Amazon intern coding test held at 20/01/23

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

int minTrips(int *weights, int num_weights){
    int num_trips = 0;
    
    sort(weights, weights + num_weights);

    int i = 0;
    while (i < num_weights-1) {
        int count=1;
        for(int j=i+1; j<num_weights; j++){
            if (weights[i] == weights[j]) {
                count++;
            } 
        } 
        if(count==1){
            return -1;
        }
        int m, n;
        if(count%2==0 && count%3==0){
            n = count/3;
            num_trips += n;
            i += 3*n;
        } else if(count%3==0){
            n = count/3;
            num_trips += n;
            i += 3*n;
        } else if(count%2==0){
            if(count%3==1){
                n = count/3;
                m = 2;
                n--;
                num_trips += m + n;
                i += 2*m + 3*n;
            } else if(count%3==2){
                n = count/3;
                m = 1;
                num_trips += m + n;
                i += 2*m + 3*n;
            } else{
                n = count/2;
                num_trips += n;
                i += 2*n;
            }
        } 
        else{  
            n = count/3;
            m = 1;
            num_trips += m + n;
            i += 3*n + 2*m;
        }
    }

    return num_trips;
}

int main() {
    // Example weights
    int weights[] = {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4};
    int num_weights = sizeof(weights) / sizeof(weights[0]);
    
    cout<<minTrips(weights, num_weights);

    return 0;
}
