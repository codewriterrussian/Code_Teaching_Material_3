#include <stdio.h>

int main(void){
    double s1, s2, s3, s4, s5;
    double w1, w2, w3, w4, w5;
    
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &s1, &s2, &s3, &s4, &s5, &w1, &w2, &w3, &w4, &w5);

    double total = s1*w1 + s2*w2 + s3*w3 + s4*w4 + s5*w5;
    double weight = w1+w2+w3+w4+w5;
    double average = total / weight;
    printf("%.2f\n", average);
    return 0;
}
