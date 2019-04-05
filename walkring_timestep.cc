// 
// walkring_timestep.cc
//
// Time stepping module for 1d random walk on a ring
//

#include "walkring_timestep.h"
#include <omp.h>
#include <random>

// Perform a single time step for the random walkers
//
// parameters:
//
//  walkerpositions: the positions of a number of walkers (note that
//                   the number of walker Z can be found from
//                   Z=walkerpositions.size())
//
//  N:               the number of possible positions. All positions
//                   in the walkerpositions array should remain
//                   between 0 and N-1
//
//  prob:            the probability to jump to the left. Also the
//                   probability to just right.  (the probability to
//                   stay on the same spot is thus 1-2p.)
//
// output:
//
//  the content of the walkerpositions arrays should have changed to
//  reflect the random movement of all walker (i.e., they will each
//  have been given a chance to move on position to the left or two
//  the right).
//
void walkring_timestep(rarray<int,1>& walkerpositions, int N, double prob)
{
    int seed = 13;
    // get the seed from the thread number
    static std::mt19937 engine1(23);
    static std::mt19937 engine2(25);
    static std::mt19937 engine3(63);
    static std::mt19937 engine4(18);
    static std::mt19937 engine5(93);
    static std::mt19937 engine6(467);
    static std::mt19937 engine7(134);
    static std::mt19937 engine8(743);
    static std::mt19937 engine9(37);
    static std::mt19937 engine10(84);
    static std::mt19937 engine11(179);
    static std::mt19937 engine12(274);
    static std::mt19937 engine13(953);
    static std::mt19937 engine14(184);
    static std::mt19937 engine15(184);
    static std::mt19937 engine16(285);
    static std::uniform_real_distribution<> uniform;
    int Z = walkerpositions.size(); 

    // move all walkers
    #pragma omp parallel for default(none) shared(walkerpositions, N, prob,Z) private(engine, uniform) 
    for (int i = 0; i < Z; i++) {
        /* initialize random seed: */
        // srand (time(NULL)*omp_get_thread_num());
        // double r = rand() % 1;
        //double r = uniform(engine); // draws a random number
        int thread_num = omp_get_thread_num()+1;
        if(thread_num == 1)
            double r = uniform(engine1); // draws a random number
        else if(thread_num == 2)
            double r = uniform(engine2); // draws a random number
        else if(thread_num == 3)
            double r = uniform(engine3); // draws a random number
        else if(thread_num == 4)
            double r = uniform(engine4); // draws a random number
        else if(thread_num == 5)
            double r = uniform(engine5); // draws a random number
        else if(thread_num == 6)
            double r = uniform(engine6); // draws a random number
        else if(thread_num == 7)
            double r = uniform(engine7); // draws a random number
        else if(thread_num == 8)
            double r = uniform(engine8); // draws a random number
        else if(thread_num == 9)
            double r = uniform(engine9); // draws a random number
        else if(thread_num == 10)
            double r = uniform(engine10); // draws a random number
        else if(thread_num == 11)
            double r = uniform(engine11); // draws a random number
        else if(thread_num == 12)
            double r = uniform(engine12); // draws a random number
        else if(thread_num == 13)
            double r = uniform(engine13); // draws a random number
        else if(thread_num == 14)
            double r = uniform(engine14); // draws a random number
        else if(thread_num == 15)
            double r = uniform(engine15); // draws a random number
        else 
            double r = uniform(engine16); // draws a random number

        if (r < prob) {
            // move to the right, respecting periodic boundaries
            walkerpositions[i]++;
            if (walkerpositions[i] == N)
                walkerpositions[i] = 0;
        } else if (r < 2*prob) {
            // move to the left, respecting periodic boundaries
            if (walkerpositions[i] == 0)
                walkerpositions[i] = N-1;
            else
                walkerpositions[i]--;
        } else {
            // walkerposition remains unchanged
        }
    }
}


