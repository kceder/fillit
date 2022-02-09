# fillit
Project to arrange given tetris pieces in the smallest possible square. 🧩

Hive Helsinki project. Done in collaboration with pnoutere. 

The task was to make a program that can take in a text file containing tetrominos (tetris pieces) and sort them in the smallest possible sqaure.
In case of many different orders leading to same square size, the top-left most solution should be the answer.
The answer is then be displayed on standerd output. All the pieces are represented by different capital letter. First tetromino in the file is 'A',
second is 'B' and so on.

Invalid files should be handeled correctly and no memory leaks can occur. 🚮

Only allowed functions were: exit, open, close, write, read, malloc and free. 
Other used functions are self made.

Most of the puzzle solving is made with binary operators and bit shifts.

Examples of valid input file and the correct output:

![image](https://user-images.githubusercontent.com/98973785/153266393-b18f0653-fe2f-4527-a372-c29f7c70c0ac.png)
