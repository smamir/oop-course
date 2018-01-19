#include <iostream>

using namespace std;

int main()
{
    int rows, star, space, num_star = 5;

    for (rows=1; rows <= 5; rows++)
    {
        for (space=1; space <= num_star; space++)
        {
            cout << " ";
        }
        for (star=1; star <= rows; star++)
        {
            cout << "* ";
        }
        cout << endl;
        num_star--;
    }
    return 0;
}
