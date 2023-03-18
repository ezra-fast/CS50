
//pseudocode for selection sort:
    //for i from 0 to n-1
        //find smallest number between numbers[i] and numbers[n-1]
        //swap smallest number with numbers[i]

//The runtime for a program like this would be O(n(n + 1) / 2)
//Or more streamlined = O(n^2/2 + n/2)

//So, a selection sort algorithm would take ROUGHLY O(n^2) running time.

//Best case is Omega (n^2) still, because the program cannot benefit from the answer already being there,
//as it must scan every place multiple times to confirm.

//So the upper and lower bounds of this algorithm are both (n^2), meaning that it can be described with theta notation.

//BUBBLE SORT AND SELECTION SORT ARE DIFFERENT METHODS OF SORTING!!!!
    //Bubble sort scans adjacent pairs and moves the smaller/larger one to the correct place between the pair
    //Selection sort scans the entire list finding the smallest number and then moving it to the smallest place and so on and so on,
    //and in doing so must scan every item every time it loops through.

