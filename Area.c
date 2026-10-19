#include "stdio.h"
#include "math.h"

int main(void)
{
	const double PI = 3.14;
	int r, s, s1, s2, s3;
	//Get values of radius and sides of circle and triangle respectively
	printf("Enter value of radius: ");
	scanf("%i", &r);
	printf("Enter value of any side of triangle: ");
	scanf("%i", &s1);
	printf("Enter value of another side of triangle except the one above: ");
	scanf("%i", &s2);
	printf("Enter value of the last side of triangle: ");
	scanf("%i", &s3);
	
	//Calculate the area of circle
	double areaOfCircle = PI * r * r;

	//Calculate the semiperimeter and hence the area of triangle
	s = (s1 + s2 + s3)/2;
	double areaOfTriangle = sqrt(s*(s-s1)*(s-s2)*(s-s3));

	//Display the area of circle and triangle respectively
	printf("The area of circle is %f while the area of the triangle is %f", areaOfCircle, areaOfTriangle);

	return 0;
}
