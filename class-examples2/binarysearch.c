
//binary search looks for the target value by comparing it to the middle value and going from there.
//(kind of like 'divide and conquer')

//pseudocode: THIS IS BINARY SEARCH (could take O(logn) or omega(1))

//if no doors
    //return false

    //else if number behind doors[middle]
        //return true
    //else if number > doors[middle]
        //search doors[middle + 1] through doors[n - 1]
    //else if number < doors[middle]
        //search doors[0] through doors[middle - 1]


//when figuring out which algorithm method to use, always consider the longest possible runtime.