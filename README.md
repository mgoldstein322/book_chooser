# book_chooser
Decide which book to read with your reading buddy.

The rules are as follows:

1. Provide your list, and your buddy's list - 10 entries each.
2. The program will find duplicates between the lists and add them to a new list.
3. From the remaining partial lists, it will ask you to choose a number of books from each to add up to 10 books in the new list.
4. You and your buddy will individually order your lists and tell the program your ordering.
5. The program will assign points based on your ordering to determine which book you will read.
  - The points are determined by looking at the order:
      - Position 1 will receive 1 point, 2 will receive 2 points, etc
      - The program will then add up the points per book, sort the list in ascending order by book breaking ties arbitrarily, and display it in that sorted order.
