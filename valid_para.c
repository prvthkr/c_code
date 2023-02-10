// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>

bool valid_par(char *str) {
    bool small_par = false;
    bool mid_par = false;
    bool big_par = false;
    
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(' || str[i] == ')') {
            small_par = !small_par;
        } else if (str[i] == '{' || str[i] == '}') {
            mid_par = !mid_par;
        } else if (str[i] == '[' || str[i] == '}') {
            big_par = !big_par;
        }
    }
    
    if (small_par == false && mid_par == false && big_par == false) {
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
