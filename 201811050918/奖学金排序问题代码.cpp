#include <stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct Student {
    int id, x, y, z; 
} a[303];
int n;
bool cmp(Student a, Student b) {
    if (a.x+a.y+a.z != b.x+b.y+b.z) 
        return a.x+a.y+a.z > b.x+b.y+b.z;   
    if (a.x != b.x)     
        return a.x > b.x;   
    return a.id < b.id;
}
int main() {
	int i;
    cin >> n;
    for (i = 1; i <= n; i ++) {
        a[i].id = i;   
        cin >> a[i].x >> a[i].y >> a[i].z; 
    }
    sort(a+1, a+1+n, cmp);
    for ( i = 1; i <= 5; i ++)   
        cout << a[i].id << " " << a[i].x+a[i].y+a[i].z << endl;
    return 0;
}