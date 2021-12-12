#include <iostream>
#include <string>
#include <random>
using namespace std;

typedef enum Gate {
    uninit,
    mainprice,
    looser
}Gate_t; 

/* Monty Hall simulation, with always picking the first gate, after which the moderator is forced to discard either gate 2 or 3 */
int main()
{


    Gate* offeredGate_p = NULL;
    int stays=0, changes=0; /* Counters for staying with the choice or switching choice */
    float RNG = 0; /* Generated random number between 0 and 1 */
    Gate_t GateOne=uninit, GateTwo=uninit, GateThree=uninit;

    for (int i=0; i<1000; i++)
    {
        GateOne=uninit;
        GateTwo=uninit;
        GateThree=uninit;
        
        RNG = float(rand())/RAND_MAX;

        if ((RNG>=0) && (RNG<=1))
        {
            if(RNG<0.33)
            {
                GateOne=mainprice;
                GateTwo=looser;
                GateThree=looser;
            }
            else if (RNG>0.66)
            {
                GateOne=looser;
                GateTwo=looser;
                GateThree=mainprice;
            }
            else
            {
                GateOne=looser;
                GateTwo=mainprice;
                GateThree=looser;
            }
        }
        else
        {
            cout << "RNG out of range!" << endl;
        }
    
        if ((GateOne!=uninit)&&(GateTwo!=uninit)&&(GateThree!=uninit))
        {
            /* Always pick gate 1 first, moderator discards the looser 2/3 */
            if (GateTwo == mainprice)
            {
                offeredGate_p = &GateTwo;
            }
            else if (GateThree == mainprice)
            {
                offeredGate_p = &GateThree;
            }
            else
            {
                /*GateOne is mainprice. Randomly offer gate 2 or 3 */
                if (float(rand()/RAND_MAX)<0,5) 
                {
                    offeredGate_p = &GateTwo;
                    }
                else
                {
                    offeredGate_p = &GateThree;
                }
            }

            /* Scenario 1: Hero stays with GateOne */
            if (GateOne == mainprice)
            {
                stays++;
            }

            /* Scenario 2: Hero changes to offered gate */
           if (*offeredGate_p == mainprice)
           {
               changes++;
           }    
        }
        else
        {
            cout << "Gate uninitialized" << endl;
        }
    }

cout << "Times, when Hero was right be staying with his initial choice gateOne (stays): " << stays << endl;
cout << "Times, when Hero was right be changing his initial choice and takes the offered gate (changes): " << changes << endl;   
}