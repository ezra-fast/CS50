//linear search can be thought of using the locker example.

//If there are n positions in an array, 0 will be at the beginning (left) and n - 1 will always be at the 'end' (far right)

//Pseudocode:

    //For each door from left to right:
        //If number is behind the door:
            //return true
    //Return false

//NEVER do [Else return false] because then after the first iteration of the loop it will return false. (Control path error?)

//at the end of the for loop return the value that is desired if what you are looking for has not returned its value.

//Better pseudocode: THIS IS LINEAR SEARCH (Takes O(n) amount of time) or (Takes omega(1) amount of time (best case))

    //for i from 0 to n-1
        //If number behind doors[i]
            //return true
    //return false

