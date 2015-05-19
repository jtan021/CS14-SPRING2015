No, my selection sort is NOT stable. For example, if it is sorting list A = {4a, 2, 5, 4b, 1}. (4a = 4b).
It will find the smallest value '1' and swap it with the value at the front of the list '4a'. 
This will move the first '4a' to the back of the list and thus behind the 2nd '4b'.
Therefore, although the original 4a is equivalent to 4b and originally came first, the selection sort has moved it behind the 4b due to it swapping rather than inserting/deleting. 
It can be seen in my main function, however if I were to use the above list A as an example....
A = {4a, 2, 5, 4b, 1}.
PRE: 4a, 2, 5, 4b, 1
selectionsort(A)....
FIRST PASS: 1, 2, 5, 4b, 4a
SECOND PASS: 1, 2, 5, 4b, 4a
THIRD PASS: 1, 2, 4b, 5, 4a
FOURTH PASS: 1, 2, 4b, 4a, 5

