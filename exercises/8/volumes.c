#include <stdio.h>
#include <math.h>

//struct definitions
typedef struct
{
  float radius;
} sphere;

typedef struct
{
  float side_x;
  float side_y;
  float side_z;
} cuboid;

typedef struct
{
  float height;
  float radius;
} cylinder;


//function prototypes
float volume_sphere(sphere);
float volume_cuboid(cuboid);
float volume_cylinder(cylinder);


//main program
int main()
{
  sphere a;
  cuboid b;
  cylinder c;

  a.radius = 10.2;

  b.side_x = 2.3;
  b.side_y = 7.3;
  b.side_z = 7.7;

  c.radius = 3.4;
  c.height = 5.6;

  float sp_vol = volume_sphere(a);
  printf("sphere volume: %f\n" , sp_vol);

  float cb_vol = volume_cuboid(b);
  printf("cuboid volume: %f\n" , cb_vol);

  float cy_vol = volume_cylinder(c);
  printf("cylinder volume: %f\n" , cy_vol);

  return 0;

}

//function implementations

float volume_sphere(sphere the_sphere)
{
  return 4/3 *M_PI * pow(the_sphere.radius,3);
}

float volume_cuboid(cuboid the_cuboid)
{
  return the_cuboid.side_x *the_cuboid.side_y *the_cuboid.side_z;
}

float volume_cylinder(cylinder the_cylinder)
{
  return M_PI * pow(the_cylinder.radius,2) * the_cylinder.height;
}
