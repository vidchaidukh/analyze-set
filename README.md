## **Solution description**

Looking at the given set of numbers, I noticed that the range of number generation should be about 5-10 times larger than the amount of numbers in the set, so there shouldn't be many repeating elements. Therefore, I decided to sort it with the quick sort algorithm.  
  
Sorting is of course necessary to find the median, and it also allows you to quickly find the minimum and maximum numbers. To find the longest ascending and descending sequences, I wrote a simple algorithm with temporarily arrays to store current sequences.  
  
At first, I implemented the solution in Python, but I didn't like how long it took to sort, so I decided to rewrite it in C++ and the time decreased by more than 5 times, to 7 seconds. The results are shown below.
## Python results
 Max is 49999978  
 Min is -49999996  
 Median is 25216  
 Ascending sequence:  
 [-48190694, -47725447, -43038241, -20190291, -17190728, -6172572, 8475960, 25205909, 48332507, 48676185]  
 Descending sequence:  
 [47689379, 42381213, 30043880, 12102356, -4774057, -5157723, -11217378, -23005285, -23016933, -39209115, -49148762]  
 • time of execution: 39.117s  

### Execution time with the time command on WSL2:
real    0m51.392s  
user    0m50.309s  
sys     0m0.886s  

 ---
## C++ results
 Max: 49999978  
 Min: -49999996  
 Median: 25216  
 Ascending sequence: -48190694 -47725447 -43038241 -20190291 -17190728 -6172572 8475960 25205909 48332507 48676185  
 Descending sequence: 47689379 42381213 30043880 12102356 -4774057 -5157723 -11217378 -23005285 -23016933 -39209115 -49148762  
 • time of execution: 7.1399s

### Execution time with the time command on WSL2:
real    0m4.881s  
user    0m0.002s  
sys     0m0.021s  