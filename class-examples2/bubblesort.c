
//pseudocode for bubble sort:
    //repeat n-1 times
        //for i from 0 to n-2
            //if numbers[i] and numbers[i+1] out of order
                //Swap them
        //if (no swaps)
            //Quit program (return 1)

//The upper bound of this kind of algorithm is (n^2 - 2n + 1) or O(n^2) for simplicities sake

//The lower bound of this kind of algorithm is (n), or O(n). (Look at lines 7 and 8)

//Bubble sort has a better lower bound than selection sort, so it is a good idea to use BS instead of SS to benefit from lucky
//data sets in the long run.

