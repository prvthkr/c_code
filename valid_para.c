// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>

bool valid_par(char *str) {
    int small_par = 0;
    int mid_par = 0;
    int big_par = 0;
    
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') {
            small_par++;
        } else if (str[i] == '{') {
            mid_par++;
        } else if (str[i] == '[') {
            big_par++;
        } else if(str[i] == ')') {
            if (small_par == 0) {
                return false;
            }
            small_par--;
        } else if(str[i] == '}') {
            if (mid_par == 0) {
                return false;
            }
            mid_par--;
        } else if(str[i] == ']') {
            if (big_par == 0) {
                return false;
            }
            big_par--;
        }
    }
    
    if (small_par == 0 && mid_par == 0 && big_par == 0) {
        return true;
    }
    
    return false;
}

int main() {
    // Write C code here
    if (valid_par("{}(")) {
        printf("true");    
    } else {
        printf("false");
    }

    return 0;
}
