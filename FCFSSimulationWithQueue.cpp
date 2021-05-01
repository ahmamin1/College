//////////////////////// Ahmed Amin & Ahmed Abd El-Mo'ez ///////////////////////////////////
/////////////////////// FCFS Simulation With Queue /////////////////////////////////////////

#include <iostream>
#include<iomanip>
#include<queue>
#include <algorithm>
using namespace std;

class process{
public:
    int id;
    int brst ;
    int arv ;
    int wait ;
    int trn ;
    int comp;
    //FUNCTIONS
    void calcAvgWaiting(process p[],int n);
    void calcAvgTurn(process p[],int n);
};

void fcfs (process *arr,int n);
bool cmp (process &a , process &b);
#define size 10
////////////////// main ///////////////////////////
int main(){

    process p[size];


    int n;
    cout << "enter number of processes (MAX:10): ";
    cin >> n;


    //input
    for (int i= 0; i < n ; i++){
        p[i].id=i;
        p[i].brst = rand() % 10 + 1;
        p[i].arv = rand() % 10 + 1;
    }

    //We need to sort our objects depending on arrival time
    sort (p , p+n , cmp);

    // algorithm implementation
    fcfs (p,n);

    //calc Average

    //print
    cout << setw(10) <<"Processes" << setw(12) <<"Burst Time" <<setw(13) << "Arrival Time"
         <<setw(14)<< "Waiting Time" <<setw(18)<< "Turn-Around Time"<<setw(15) <<"Completion T." <<endl;
    for (int i = 0 ; i < n ; i++)
    {

        cout << setw(10)<< p[i].id << setw(12) << p[i].brst << setw(13)
             << p[i].arv << setw(14) << p[i].wait << setw(18)
             << p[i].trn  <<  setw(15) << p[i].comp <<endl ;
    }

    //Average
    p->calcAvgWaiting(p,n);
    p->calcAvgTurn(p,n);


    return 0;
}
/////////////////////////////////////////////////

bool cmp (process &a , process &b){      //for sorting depending on arrival time
    return  a.arv < b.arv;
}


void fcfs (process arr[],int n){
    queue<process*> Q;

    //push
    for (int i = 0 ; i< n ; i++ ){
    Q.push(&arr[i]);
    }

    process *prv ; // to save previous object
    bool first = true;

    while(!Q.empty()){
    process *x = Q.front();
    Q.pop();


        if (first){
        x->wait = 0;      //wait time is zero for first process
        first = false;
        }
        else {
        x->wait = max(0,prv->comp - x->arv);
        }

        x->comp=x->brst + x->arv + x->wait;
        x->trn = x->comp - x->arv;
        prv = x; // to calc waiting based on previous completion time
    }
}

void process::calcAvgWaiting(process p[],int n){
    int sum =0;
    for (int i= 0 ; i < n; i++){
        sum += p[i].wait;
    }
    cout <<":: average of waiting time is: " << (float)sum / (float)n << endl;

}
void process::calcAvgTurn(process p[],int n){
    int sum =0;
    for (int i= 0 ; i < n; i++){
        sum += p[i].trn;
    }
    cout <<":: average of Turn around time is: " << (float)sum / (float)n;

}
