// Implement a class structure.

#include <iostream>
#include <string>
using namespace std;

#define PI 3.14159

class Circle
// Various information about a circle for testing and training
{
    private:
        int radius;
        string name;
    public:
        Circle(int r, string name="circle")
        {
            // name = "circle";
            radius = r;
        }
        void set_name(string s)
        {
            name = s;
        }
        void set_radius(int r)
        {
            radius = r;
        }
        string get_name()
        {
            return name;
        }
        int get_radius()
        {
            return radius;
        }
        int get_diameter()
        {
            return radius * 2;
        }
        float get_circumference()
        {
            return PI * get_diameter();
        }
        float get_area()
        {
            return PI * radius * radius;
        }
};

int main(void)
// Implement circle, Bob, and output area and name
{
    Circle circle_1(5, "Bob");
    printf("%.2f | ", circle_1.get_area());
    printf("%s\n", circle_1.get_name());

    return 0;
}
