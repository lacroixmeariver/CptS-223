Documentation: 
PA4 -  REPL Inventory System 

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
I made no external changes to the CSV file provided. I chose to instead write a parseLine() function that iterates through every character in a line and uses commas 
as a deliminator only if they are not within a set of double quotes and adds the individual field to an array until the string reaches the end.  
