#include <iostream>
#include <iomanip>
#include <string.h>

const float RPR=7.5,BPR=50.0;

using namespace std;

class customer{
protected:
    int acn,np=0;                 //PREMIUM
    float total=0;          //BILL

public:
    void get_an(){                          //GET ACCOUNT NUMBER
        cout<<"Enter Account number: ";
        cin >> acn;
    }
    void get_prem(){                                    //GET NO. OF PREMIUM CHANNELS
        cout<<"Enter number of premium channels: ";
        cin >> np;
    }
    float bill_calc();                                  //BILL CALCULATION FUNCTION

};

class business : public customer{                       //CUSTOMER OF BUSINESS
private:
    int base=1;
    const float BPR=50.0,fee = 90.0;                    //BASE RATES

public:

    void get_base(){                                    //GET NO. OF BASE CONNECTIONS
        cout<<"How many base channels do you have? : ";
        cin>>base;
    }

    float bill_calc(){
        total += fee;
        if(base>10){
            base-=10;
            total += (base*5.0);
        }
        total += (np*BPR);
        return total;
    }
};

class residential : public customer{                    //CUSTOMER OF RESIDENTIAL
private:
    const float RPR=7.50;
    float fee = 25.0;                                   //BASE RATES
public:
    float bill_calc(){
        total+=fee;
        total+=(np*RPR);
        return total;
    }
};


int main(){
    char sel;
    float t=0.0;
    int n;


    do{
        cout<<"What type of customers? (R => Residential || B => Business) : ";
        cin>>sel;
        cout<< "How many customers ?: ";
        cin>>n;

        if(sel == 'R'||sel == 'r'){
            residential cust0[n];
            for(int i=0;i<n;i++){
            cust0[i].get_an();
            cust0[i].get_prem();
            t = cust0[i].bill_calc();
            cout<<"TOTAL AMOUNT PAYABLE: "<<t<<endl;
            }
        }

        else if(sel=='B'||sel=='b'){
            business cust[n];
            for(int i=0;i<n;i++){
            cust[i].get_an();
            cust[i].get_prem();
            cust[i].get_base();
            t = cust[i].bill_calc();
            cout<<"TOTAL AMOUNT PAYABLE: "<<t<<endl;
            }
        }

    }while()




    return 0;
}
