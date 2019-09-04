# Linked List Project

A C++ creation of the doubly linked list data structure in C++ using my JDString data structure (https://github.com/JosiahDerricott/stringclassrecreation) previously created.

Hosted here: https://repl.it/repls/BulkyMiniIntelligence

## Project Goals

- [x] Create a fully functional doubly linked list in C++
- [x] Allow for proper insertion and deletion of nodes
- [x] Allow insertion and deletion to work under all list conditions (empty list, one node list, multi-node list)
- [x] Prevent memory leaks on full list deletion

## Project Struggles

- Managing the different types of insertion
  - Inserting into a doubly linked list, although not complicated, was very tidius. I found that my solutions at the start were working, but clunky and needed refactoring.
  - After some time, I found a way to implement an insertion algorithm that not only accomplished the task, but looked clean and concise.
- Searching the linked list
  - Since I was not utilizing iterators, I had to come up with a unique solution to the searching problem.
  - I found that creating an 'iterator' pointer that could iterate through each node and provide the node data was by far the best solution.
## Output

The way I went about testing my linked list was to create four objects of my list, insert into the first two text from a book, and into the second two modified versions of the first two. After this, I went about testing my copy constructor by implicitly creating a copy of my list through the changer function. All output will reflect this. The data is then organized alphabetically and outputted into two different output files for review.

## Conclusion

This project really helped me to understand the core concept of what a linked list does and how it's structured in the C/C++ language. It also has helped me to understand how pointers can be used to traverse data rather than just retrieve it.