# Word_Searcher_Using_BST

**Word Search in 2D Array using Binary Search Tree**

**Approach:**
This C++ program employs a tree structure to search for words in a dynamically defined 2D array. The `Tree` class is designed to organize the array into a tree, making it easier to search in various directions (horizontal, vertical, diagonal). The program reads words from a file (`words.txt`) and searches for them in the array, outputting results to `output.txt`.

**Intuition:**
1. **Tree Construction:**
   - The `read_insert` method constructs a tree from the given 2D array, where each node represents a character. Horizontal and vertical connections are established for efficient traversal.
  
2. **Word Search:**
   - Various search methods (`search_hor`, `search_ver`, etc.) navigate the tree to find words in different directions (horizontal, vertical, diagonal).
   - Diagonal searches are conducted in both forward and backward directions.
  
3. **Output:**
   - The program outputs the found words along with their coordinates in the `output.txt` file.
   - The `main` function reads the array, initializes the tree, reads words from `words.txt`, and performs the searches.

**Usage:**
1. **Input Array:**
   - Modify the `array` variable in the `main` function to use a different 2D array for searching.

2. **Word List:**
   - List the words to be searched in the `words.txt` file, with each word on a new line.

3. **Output:**
   - Run the program and check `output.txt` for the word search results.

**Note:**
   - Ensure the input array and word list are appropriately formatted for accurate results.

**Execution:**
   - Compile and run the program. On execution completion, view `output.txt` for the search results.

**Example:**
   - The provided example searches for words in a crossword-like array, demonstrating the program's flexibility for different 2D structures.
