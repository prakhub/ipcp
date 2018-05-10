#include <stdio.h>

typedef struct {
    float x;
    float y;
    float z;
} Vector3D;

#define d 3


float scalarProduct (Vector3D v1, Vector3D v2){
    float result = 0;
    for (int i = 0; i < d; i++) {
        result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }
}
Vector3D vectorProduct (Vector3D v1, Vector3D v2){
    Vector3D result;
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;
    return result;
}

int main () {
    Vector3D v1, v2;
    v1.x = 1; v1.y = 2; v1.z = 3;
    v2.x = 1; v2.y = 0; v2.z = 3;
    printf("scalarProduct v1 * v2 = %f\n", scalarProduct(v1,v2));
    printf("crossproduct = %.2f,%.2f,%.2f \n", vectorProduct(v1,v2).x , vectorProduct(v1,v2).y , vectorProduct(v1,v2).z   );
    return 0;
}
