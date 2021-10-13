# book_chooser
Decide which book to read with your reading buddy.

The rules for two lists are as follows:

1. Provide your list, and your buddy's list - 10 entries each.
2. The program will find duplicates between the lists and add them to a new list.
3. From the remaining partial lists, it will ask you to choose a number of books from each to add up to 10 books in the new list.
4. You and your buddy will individually order your lists and tell the program your ordering.
5. The program will assign points based on your ordering to determine which book you will read.
  - The points are determined by looking at the order:
      - Position 1 will receive 1 point, 2 will receive 2 points, etc
      - The program will then add up the points per book, sort the list in ascending order by book breaking ties arbitrarily, and display it in that sorted order.


If you don't have a buddy, just give the program one list and what you think your priority is, and it will do the following:

1. Create acceptance bands based on priority (note that priorities CANNOT be duplicated).
  - For example, the highest priority will 1, so the acceptance band will be 50% of the MAX_INT range of numbers, the next priority level will receive half as much, then half for the next level, and so on. The final book will get whatever is left.
2. A random number MIN_INT to MAX_INT will be computed and compared to the acceptance bands, giving you your book.


I am making this program to help my girlfriend and myself choose what books we are going to read next. It is a work in progress :)
