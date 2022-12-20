
#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};
 

Point test_point[] = { { -1.0, 0.0 },
                       { 0.0, 1.0 },
                       { 1.0, 0.0 },
                       { 0.0, -1.0 } };
 

long double lower_limit = 0.000001;
 
Point arr[1005];
long double distSum(Point p, int n)
{
    long double sum = 0;
    for (int i = 0; i < n; i++) {
        long double distx = (arr[i].x - p.x);
        long double disty = (arr[i].y - p.y);
        sum += sqrt((distx * distx) + (disty * disty));
       // cout << p.x << " " << disty << endl;
    }
 
  
    return sum;
}
 

void geometricMedian(int n)
{
 
  
    Point current_point;
 
    for (int i = 0; i < n; i++) {
        current_point.x += arr[i].x;
        current_point.y += arr[i].y;
    }
 
 	//cout << current_point.x << endl;
    current_point.x /= n;
    current_point.y /= n;

    long double minimum_distance =
       distSum(current_point, n);
 
    int k = 0;
    while (k < n) {
        for (int i = 0; i < n, i != k; i++) {
            Point newpoint;
            newpoint.x = arr[i].x;
            newpoint.y = arr[i].y;
            long double newd =
                   distSum(newpoint, n);
            if (newd < minimum_distance) {
                minimum_distance = newd;
                current_point.x = newpoint.x;
                current_point.y = newpoint.y;
            }
        }
        k++;
    }
 

    long double test_distance = 1000000000;
    int flag = 0;
 
   
    while (test_distance > lower_limit) {
 
        flag = 0;
 
       
        for (int i = 0; i < 4; i++) {
 
   
            Point newpoint;
            newpoint.x = current_point.x
                 + (long double)test_distance * test_point[i].x;
            newpoint.y = current_point.y
                 + (long double)test_distance * test_point[i].y;
 
  
            long double newd = distSum(newpoint, n);
 
            if (newd < minimum_distance) {
 
              
                minimum_distance = newd;
                current_point.x = newpoint.x;
                current_point.y = newpoint.y;
                flag = 1;
                break;
            }
        }
 

        if (flag == 0)
            test_distance /= 2;
    }
 
    cout << fixed << setprecision(4) << minimum_distance;
    
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
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    int n ;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i].x >> arr[i].y;
    geometricMedian(n);
 
    return 0;
}