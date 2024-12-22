#include <bits/stdc++.h>
using namespace std;

class Cars{
  private:
  int xPosition;
  int yPosition;
  public:
    Cars() {}
    Cars(int x, int y) : xPosition(x), yPosition(y) {}

    int select_Car() {
        srand(time(0));
        int random_Car = rand() % 9 + 1;
        return random_Car;
    }
    void select_Direction(int random_direction) {
        srand(time(0));
        switch(random_direction) {
            case 1:
                move(1);
                xPosition += 1;
                break;
            case 2:
                move(2);
                xPosition -= 1;
                break;
            case 3:
                move(3);
                yPosition += 1;
                break;
            case 4:
                move(4);
                yPosition -= 1;
                break;
        }
    }
        int get_xPostion() {
        return xPosition;
        }
        int get_yPosition() {
        return yPosition;
        }
    void display() {
        cout<<"xPosition is: "<<xPosition <<endl;
        cout<<"yPosition is: "<<yPosition <<endl;
    }
    bool check_collision(Cars& etc) {
        return xPosition == etc.xPosition && yPosition == etc.yPosition;
    }
    
};

int main() {
    srand(time(0));
    Cars arr[10];
    for(int i=0; i<10; ++i) {
        int x = rand() % 10;
        int y = rand() % 10;
        arr[i] = Cars(x,y);
    }
    for(int i=0; i<100; ++i) {
        int caridx = rand() % 10;
        int dir = rand() % 4 + 1;
        arr[caridx].select_Direction(dir);
        for(int j=0; j<10; ++j) {
            arr[j].display();
        }
    bool check = false;
    for(int i=0; i<10; ++i) {
        for(int j=0; j<10; ++j) {
            if(arr[i].check_collision(arr[j])){
                cout<<"Collision Ocurred Between: " <<i <<" and "<<j <<endl;
                check = true;
            }
        }
    }
    if(!check) {
        cout<<"Collision Not Ocurred!" <<endl;
    }
    }
    return 0; 
}