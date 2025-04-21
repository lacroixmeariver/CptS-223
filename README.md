Documentation: 
PA5 -  Improved REPL Inventory System 

This program uses a custom hashmap container (which also uses a custom array container as key/value storage management) to display information regarding a user input search query for an Amazon inventory. 
    - Supports find commands for:
        Categories
        - Each query produces a list of all items that belong to category string input 
        Individual products based on inventory ID
        - ID corresponds to a unique product ID

To run, type make in the terminal
    - To exit, type ":quit"
    - For more information/help, type ":help"
    - For individual queries, type "find <item id here>" 
    - For category queries, type "listInventory <item id here>"  
    NOTE: while the commands are case sensitive, the queries themselves are not. Users may omit capitalization for searching should they wish 

CSV file changes: 
I trimmed down some of the categories from the original CSV file, for the ease of processing.

In the updated version this program now supports searching by ascending and descending selling price values.
The default sorting in any category search is ascending, but user may specify a descending list 
- For ascending category queries with insertion sort, type "listInventory <item id here>"  
- For descending queries, type "listInventory <item id here> desc"  
- For ascending merge sort queries, type "listInventory <item id here> merge"  
- For descending merge sort queries, type "listInventory <item id here> merge desc"  

Insertion sort VS merge sort:
I implemented a simple loop that captures the execution time for both algorithms in ascending order and averages them out to provide an average 
execution time in seconds. Generally I noticed that the merge sorting algorithm was significantly faster than insertion sort. I believe this is 
due to the divide and conquer approach of the merging algorithm, as well as using recursion. My conclusion is that merge sort is a much more efficient 
algorithm given data sets of this size and possibly beyond, and the average time complexity is less than that of insertion sort. 