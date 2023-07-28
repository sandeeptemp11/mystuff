#include <cmath>
bool isPrime(int n){
    if(n <= 1) return false;
    if(n == 2) return true; // edge case
    for(int i = 2; i <= (int)sqrt(n); i ++){
        if(n % i == 0) return false;
    }return true;
}
