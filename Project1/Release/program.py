import re
import string

#creates function for a multiplication table
def MultiplicationTable(v):
    #sets an index to one
    i = 1
    #iterate while the index is less than or equal to ten
    while i <= 10:
        #print the users num * index = total
        print(v, " * ", i, " = ", v * i)
        #increment index by one
        i += 1
        #return 0 to keep the while loop in main operating correctly and not prematurely terminating
    return 0;

#creates function for doubling a number
def DoubleValue(v):
    #returns the result of user entered number times two
    return v * 2;