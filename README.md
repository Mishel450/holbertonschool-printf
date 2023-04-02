![](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcT_PnZm-qWM7dRUkn2qiveseccQzG6-SO8y0s8B7Ac1vQ&s)
## Printf

First group project, with the objective of creating the printf function from scratch, a linux c language function.

 The _printf function is our version of the standard printf function. It takes the argument format which is a string containing the characters to print. It uses a while loop to loop through each character in format and call the checker function if the character is a % or print the character directly if it is not.

### Flowchart
![](https://github.com/Mishel450/holbertonschool-printf/blob/master/Diagrama%20de%20PRINTF.png)

### How it worksl

In this code a structure called B8 is defined, which is used later in the checker function.
This structure has two members:

c: a pointer to a string representing a valid format character.
st: a pointer to a function that prints the corresponding argument.

Next, a function called checker is defined which is used to check the formatting character and then call the corresponding function to print the character or string to standard output. The checker function takes two arguments:

pf: a va_list containing the variable arguments passed to the _printf function.
C: the current format character.

The checker function uses an array of structures called D10 containing pairs of strings and pointers to functions. Each pair contains a string representing a valid format character and a function that prints the corresponding argument.

* printC:  
   function that prints a character.
* printS:  
   function that prints a character string.
* printM:  
   function that prints a percent sign.
* printInt:  
   function that prints an integer.

The checker function goes through the array of D10 structures and compares the current format character with each string in the array. If it finds a match, it calls the corresponding function to print the variable argument using va_arg. If it does not find a match, it prints the character directly.

### Authors
Mishel Tomas <https://github.com/Mishel450>

Victoria Coria <https://github.com/Vicky01396>
