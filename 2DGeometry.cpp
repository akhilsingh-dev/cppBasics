#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;

float sq(float x){ return x*x;}

//A 2D cartesian point defined by two co-ordinates and a name... 
class cart{
    float x,y;
    char name;

public:
    cart();
    cart(float a1, float a2,char n);
    friend class polar;

    void disp(){
        cout << " Cart: ( " << x << " , " << y << " )" << endl;
    }
};

//a 2D polar point defined by radius r, angle theta and a name...
class polar{
    float r,theta;
    char name;

public:

    friend class cart;

    polar(float a1,float a2,char type,char n);
    polar();
    polar operator +(polar b);
    polar operator -(polar b);
    void disp();

    polar(const polar &a){
        r = a.r;
        theta = a.theta;
    }

    void to_cart(cart* A){
        A->x = r*cos(theta*3.142/180);
        A->y = r*sin(theta*3.142/180);
    }

};


//CARTESIAN METHODS...

cart::cart(){
    cout<<"Warning! Empty initialization of cartesian object!"<<endl;
}

cart::cart(float a1, float a2,char n){
    x = a1; y = a2; name = n;
}



//POLAR METHODS...


//ctor for polar, two floats denoting (x,y) in "c" type or (r,theta) in "p" type...
polar::polar(float a1,float a2,char type,char n){
    name = n;
    if(type == 'p'){
        r = a1;
        theta = a2;
    }
    else if(type == 'c'){
        r = sqrt(pow(a1,2)+pow(a2,2));
        if(a1 != 0)
            theta = atan(a2/a1)*180/3.142;
        else if(a2 > 0)
            theta = 90.0;
        else if(a2 < 0)
            theta = 270.0;
        else if(a2 == 0)
            theta = 0.0;
    }
    else{
        cout << "Define Point type!" << endl;
    }
}


polar::polar(){
    cout<<"Warning! Empty initialization of polar object!"<<endl;
}

//overloading a few operators...
polar polar::operator +(polar b){
    cart A,B;
    char n;
    this->to_cart(&A);
    b.to_cart(&B);
    cout << "Cartesian Converts:" << endl;
    A.disp();
    B.disp();
    cout << "\n\n" << endl;
    cout << "Enter name of point: ";
    cin >> n;
    polar c(A.x+B.x,A.y+B.y,'c',n);
    return c;
}

polar polar::operator -(polar b){
    cart A,B;
    char n;
    this->to_cart(&A);
    b.to_cart(&B);
    cout << "Enter name of point: ";
    cin >> n;
    polar c(A.x-B.x,A.y-B.y,'c',n);
    return c;
}

//displaying a polar object...
void polar::disp(){
    cout << "( " << r << " , " << theta << " )" <<endl;
}


int main(){
    //creating a few points in polar form via the cartesian type...
    polar a1(0,3,'c','A');
    polar a2(4,0,'c','B');


    polar a3;
    

    cart b1(5,5,'X');
    
    //using the overloaded operator...
    a3 = a1 + a2;

    //showing all three points...
    a1.disp();
    a2.disp();
    a3.disp();



    return 0;
}
