//********************************************************
// fracturing.c
// Author: Lorenzo Wyman
// UCF ID: 5464079
// Class: COP 3223, Professor Parra
// Date: 9/8/2024
// Purpose: This program prints the requests of the user (area, distance, heigfht, width, perimeter) using the coordinates or points provided by the user. 
// Input: User needs to input a set of coordinates or two points on the (X,Y) plane; Leaving a space or pressing 'enter' when entering a different number.
// Output: A simultaneous output of all of the user requests from the given coordinates/points.
// //********************************************************

#include <math.h>
#include <stdio.h>

// makes PI a variable that can be passed and used with the functions; just defines PI basically

#define PI 3.14159 

// Allows the points to be considered non-global.

typedef struct { 

  int x1;
  int x2;
  int y1;
  int y2;

} Coordinates;
    
// This piece (Coordinates* getCoordinates()) connects with the last and makes the coordinates static and not global.
// Later, the functions will be able to calculate using the recalled points without having the values changed.

  Coordinates* getCoordinates() { 

    static Coordinates coords; 

    return &coords;
}

//********************************************************
// void calculateDistance()
//
// Purpose:         Retreives user given coordinates, then stores and calculates the distance between the coordinates.
// Output:          Prints the distance between the two points as requested by the user.
// Precondition:    none.
// Postcondition:   none.
//********************************************************

// Static is a way to store value for distance without global; also to prevent my values from becoming negative, I have a set stattic value for it to start from (0.0).
// The equation to calculate the distance of the points uses pointers bcuz of no global variables

  void calculateDistance(){   

    Coordinates*coords = getCoordinates();
    static double distance = 0.0;    

    distance = sqrt(pow(coords->x2 - coords->x1, 2) + pow(coords->y2 - coords->y1, 2));    
      printf("\nThe distance between the two points is: %.3f\n", distance);

}

//********************************************************
// double getDistance()
//
// Purpose:         Helper function that retreives user given coordinates and returns the value of the distance so the perimeter and area function can funtion correctly.
// Output:          None.
// Precondition:    none.
// Postcondition:   none.
//********************************************************


  double getDistance(){ 

    Coordinates* coords = getCoordinates();

    return sqrt(pow(coords->x2 - coords->x1, 2) + pow(coords->y2 - coords->y1, 2));

}

//********************************************************
// double calculatePerimeter()
//
// Purpose:         Calculates the perimeter of the user's request using the distance from the previous function.
// Output:          Prints the perimeter of the city using the data from the user's input.
// Precondition:    none.
// Postcondition:   none.
//********************************************************

  double calculatePerimeter(){  

    double distance = getDistance(); 
    double perimeter = 2 * PI * distance; 

      printf("The perimeter of the city encompassed by your request is: %.3lf \n", perimeter);

}

//********************************************************
// double calculateArea()
//
// Purpose:         Uses distance function to calculate the area of the city.
// Output:          Prints the area of the city based on user's data.
// Precondition:    none.
// Postcondition:   none.
//********************************************************

  double calculateArea() {

    double distance = getDistance();
    double area = PI * pow(distance / 2, 2); 

      printf("The area of the city encompassed by your request is: %.3lf\n", area);

}

//********************************************************
// double calculateWidth()
//
// Purpose:         Uses getCoordinates() function to calculate the width of the city.
// Output:          Prints the width of the city based on user's data.
// Precondition:    none.
// Postcondition:   none.
//********************************************************

  double calculateWidth() {

    Coordinates* coords = getCoordinates();  

    double width = fabs(coords->x2 - coords->x1);  

      printf("The width of the city encompassed by your request is: %.3f\n", width); 

}

//********************************************************
// double calculateHeight()
//
// Purpose:         Uses the coordinates from the getCoordinates() function to calculate height of the user's request.
// Output:          Prints the height of the city based on user's data.
// Precondition:    none.
// Postcondition:   none.
//********************************************************

  double calculateHeight() {

    Coordinates* coords = getCoordinates();

    double height = fabs(coords->y2 - coords->y1); 

      printf("The height of the city encompassed by your request is: %.3f\n", height);

}

//********************************************************
// int main()
//
// Purpose:         The main part of the program that calls on data from the other functions, asks for user to input coordinates and prints the requests out at the end.
// Output:          Prints the coordnates and all of the requests made by the user.
// Precondition:    none.
// Postcondition:   none.
//********************************************************

// This is where you input the values for the typestruct earlier so that they can be used. they gotta go in main
// If I use a "," the program expects a second arg w/ char which is nowhere, so user needs to press space or enter when typing values so they will be seperate.

  int main() {    

    Coordinates* coords = getCoordinates();
     
      printf("Please enter the 'x' values of the coordinates: ");
      scanf("%d" "%d", &coords->x1, &coords->x2); 
      printf("Please enter the 'y' values of the coordinates: ");
      scanf("%d" "%d", &coords->y1, &coords->y2);
      
// Only here to print once because it started to print more than once when code was running.
// They work similar like a regular thing when referencing a variable normally

      printf("\nPoint #1 entered: x1 = %d, y1 = %d\n", coords->x1, coords->y1); 
      printf("Point #2 entered: x2 = %d, y2 = %d \n", coords->x2, coords->y2);

// These statements are here in the main function so that they can be called upon, and done so in the order they are one after the other. basically the output of everything

      calculateDistance();   
      calculatePerimeter();
      calculateArea();
      calculateWidth();
      calculateHeight();
        
  return (0); 

}