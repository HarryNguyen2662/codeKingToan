
#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y, z;
};

// Point test_point[] = { { -1.0, 0.0 },
//                        { 0.0, 1.0 },
//                        { 1.0, 0.0 },
//                        { 0.0, -1.0 } }; 

Point test_point[] = { { -1.0, 0.0, 0.0},
                       { 0.0, 1.0, 0.0 },
                       { 1.0, 0.0, 0.0 },
                       { 0.0, -1.0, 0.0}, 
                        { 0.0, 0.0, 1.0},
                       { 0.0, 0.0, -1.0}};
 

long double lower_limit = 0.0001;
 
Point arr[1005];
long double distSum(Point p, int n)
{
    long double sum = 0;
    for (int i = 0; i < n; i++) {
        long double distx = (arr[i].x - p.x);
        long double disty = (arr[i].y - p.y);
        long double distz = (arr[i].z - p.z);
        sum += sqrt((distx * distx) + (disty * disty) + (distz*distz));
       // cout << p.x << " " << disty << endl;
    }
 
  
    return sum;
}
 

void geometricMedian(int n)
{
  
    Point current_point;

    current_point = {0, 0, 0};
 
    for (int i = 0; i < n; i++) {
        current_point.x += arr[i].x;
        current_point.y += arr[i].y;
        current_point.z += arr[i].z;
    }
 
 	//cout << current_point.x << endl;
    current_point.x /= n;
    current_point.y /= n;
    current_point.z /= n;


    long double minimum_distance =
       distSum(current_point, n);
 
    int k = 0;
    while (k < n) {
        for (int i = 0; i < n, i != k; i++) {
            Point newpoint;
            newpoint.x = arr[i].x;
            newpoint.y = arr[i].y;
            newpoint.z = arr[i].z;

            long double newd =
                   distSum(newpoint, n);
            if (newd < minimum_distance) {
                minimum_distance = newd;
                current_point.x = newpoint.x;
                current_point.y = newpoint.y;
                current_point.z = newpoint.z;

            }
        }
        k++;
    }
 

    long double test_distance = 10000;
    int flag = 0;
 
   
    while (test_distance > lower_limit) {
 
        flag = 0;
 
       
        for (int i = 0; i < 6; i++) {
 
   
            Point newpoint;
            newpoint.x = current_point.x
                 + (long double)test_distance * test_point[i].x;
            newpoint.y = current_point.y
                 + (long double)test_distance * test_point[i].y;
            newpoint.z = current_point.z
                 + (long double)test_distance * test_point[i].z;
 
  
            long double newd = distSum(newpoint, n);
 
            if (newd < minimum_distance) {
 
              
                minimum_distance = newd;
                current_point.x = newpoint.x;
                current_point.y = newpoint.y;
                current_point.z = newpoint.z;

                flag = 1;
                break;
            }
        }
 

        if (flag == 0)
            test_distance /= 2;
    }

    cout << fixed << setprecision(4) << current_point.x << " " << current_point.y << " " << current_point.z;
    
}
 
// Driver code
int main()
{
 	
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
 
    int n ;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i].x >> arr[i].y >> arr[i].z;
    geometricMedian(n);
 
    return 0;
}