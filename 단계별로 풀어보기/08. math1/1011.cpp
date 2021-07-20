#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int x, y;
        cin >> x >> y;

        double d = (y - x);

        int speed = floor(sqrt(d));
        int count = 2 * speed - 1;

        d -= speed * speed;
        // cout << "d: " << d << endl << "speed: " << speed << endl << "count: " << count << endl;

        if (d > 0) count += ceil(d / speed);
        cout << count << endl;
    }
    return 0;
}