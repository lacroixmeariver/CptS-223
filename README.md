### Performance comparison
- In all of the testing the algorithm that consistently outperformed the others was the quick sort algorithm. My heap and shell sort 
had similar performance values, but it was insertion sort that seemed to have the highest duration time among all the trials. 
### My interpretation 
- I believe that quick sort outperformed the other algorithms because it was the only one that 
had a recursive component. Because of that recursion, it was able to divide and conquer large sets of data more effectively, and results were achieved
significantly faster than the other 3 algorithms. 
### Shell sort variations 
- I played around with a couple of variations of shell sort, but ultimately I went with a sort of 
modified Shell method, where the gap is the size of the array divided by an interval, and then gets 
reduced by a division of that interval. From what I observed, the sweet spot for this method seems to be 
between 3 and 5. 