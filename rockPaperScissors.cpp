#include <iostream>

using namespace std;

//A small game of rock paper scissors...


        //  0      1     2
enum resp {ROCK,PAPER,SCISSORS};

void disp_rules(){
    cout<< "\t\t\t\tWELCOME TO ROCK PAPER SCISSORS!\t\t\t\n";
    cout<< "Choose 'R' for Rock / 'P' for Paper / 'S' for Scissors\n";
    cout<< "Rock defeats Scissors\nScissors defeat Paper\nPaper defeats Rock\n";
}

bool valid_sel(char sel){
    switch(sel){
    case 'r':
    case 'p':
    case 's':
    case 'R':
    case 'P':
    case 'S':
        return true;
    default:
        cout<<"Invalid Selection. Please Try again!\n";
        return false;
    }
}

resp convert(char sel){
    if(valid_sel(sel)){
        switch(sel){
        case 'r':
        case 'R':
            return ROCK;

        case 's':
        case 'S':
            return SCISSORS;

        case 'p':
        case 'P':
            return PAPER;
        }
    }
}

resp win_obj(resp r1, resp r2){
    if((r1==ROCK && r2 == SCISSORS) || (r1 == SCISSORS && r2 == ROCK)){
        return ROCK;
    }
    else if((r1 == ROCK && r2 == PAPER) || (r1 == PAPER && r2 == ROCK)){
        return PAPER;
    }
    else{
        return SCISSORS;
    }
}

int game_result(resp r1, resp r2){
    int winner;
    if(r1 == r2){
        winner=0;
        cout<< "\t\t\t\tIT'S A TIE!\n";
    }
    else{
        resp winobj;
        winobj = win_obj(r1,r2);
        if(r1 == winobj){
            winner = 1;
        }
        if(r2 == winobj){
            winner = 2;
        }
        cout<<"\t\t\t\tPLAYER "<< winner << " WINS THE GAME!\n";
    }
    return winner;
}

void disp_res(int g,int w1,int w2){
    cout << "\t\t\t\t=======FINAL RESULTS=======\n";
    cout<< "THE GAME WAS PLAYED " << g << " TIMES.\n";
    cout << "PLAYER ONE WON " << w1 << " TIMES.\n";
    cout << "PLAYER TWO WON " << w2 << " TIMES.\n";
    if(w1>w2){
        cout << "PLAYER ONE WINS!\n";
    }
    else if(w2 > w1){
        cout << "PLAYER TWO WINS!\n";
    }
}

int main(){
    int r, g=0, w1=0, w2=0, win;
    char sel;
    disp_rules();
    do{
        resp r1,r2;
        cout<<"Player 1 Enter your Choice : ";
        cin >> sel;
        r1 = convert(sel);
        cout<<"Player 2 Enter your Choice : ";
        cin >> sel;
        r2 = convert(sel);
        win = game_result(r1,r2);
        if(win == 1){
            w1++;
        }
        if(win ==2){
            w2++;
        }
        cout << "Do you want to play the game again? ( 1 => YES || 0 => NO ) : ";
        cin >> r;
        g++;
    }while(r == 1||w1==w2);
    disp_res(g,w1,w2);
    return 0;
}
