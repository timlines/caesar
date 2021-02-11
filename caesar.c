#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Check that there are only two arguments
    if (argc != 2) // for example ./caeser 1
    {
        printf("Usage: ./caesar key\n"); // Message
        return 1; //secrect error code.
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++) //check every character in argv[1]
    {
        int j = isdigit(argv[1][i]); //is it a digit?
        if (j == 0) // Check if it's not a digit
        {
            printf("Usage: ./caesar key\n"); // message
            return 1; // secrect error code
        }
    }

    // change the string to a integer
    int k = atoi(argv[1]);
    //printf("Key: %i\n", k);

    // Get a message from the user
    string plaintext = get_string("plaintext:  "); // About time you got it right. Now enter your message.

    printf("ciphertext: "); // Print the result as ciphertext...

    for (int i = 0, n = strlen(plaintext); i < n; i++) // iterate through every character of plaintext
    {
        if (isupper(plaintext[i])) //if it's uppercase rotate it only in upper case ASCII characters
        {
            int s = plaintext[i];
            int p = s - 65; //they start at 65
            int c = (p + k) % 26; // magic mod formula
            int d = c + 65; //change back by 65
            printf("%c", d);
        }
        else if (islower(plaintext[i])) //if it's a lowercase rotate it
        {
            int s = plaintext[i];
            int p = s - 97; // lowercase start at 97
            int c = (p + k) % 26; // magic
            int d = c + 97; //don't forget to change it back
            printf("%c", d);
        }
        else // if it's not upper or lowercase don't rotate it.
        {
            printf("%c", plaintext[i]);
        }

    }
    printf("\n"); //don't forget the new line!


    return 0; //secret code for everything worked, see with echo $?
}



/*

LOG

2 FEB 2021, 2:41 PM

Let's make a program called caesar that encrypts messages
using Caesar's cipher.

Specification:

My program must accept a single command-line arguemnt, a non
negative integer. let's call it k for teh sake of discussion.

If my program is executed without any command-line
arguments or with more than one command-line argument,
my program should print an error message of your choice.
with (print f and return from main a value of 1)

If any of the characters of the command-line argument is not a
decimal digit, your program should print the message
"Usage: ./caesar key" and return from main a value of 1.

Do not assume that k will be less than or equal to 26. Your
program should work for all non-negative integral values of k
less than 2^31-26. In other words, you don't need to worry if
your program eventually breaks if the user chooses a value for
k that's too big or almost too big to fit in an int.
(Recal taht an in can overflow) but even if k is great than
26 alphabetical characters in your program's input should
remain alphabetical characters in your program's output.
Z loops back to A.

Your program must output plaintext: (without a newline)
and then prompt the user for a string of plaintext
useing get_string.

The program msut ouput ciphertext: (without a newline)
followed by the plaintext's corresponding ciphertext, with
each alphabetical character in the plaintext "rotated"
by k positions, non-alphabetical characters should be
outputted unchanged.

Your program must preserve case: capitalized letters, though
rotated, must remian capitalized letters; lowercase letters
though rotated, must remain lowercase letters.

After outputting ciphertext, you should print a newline.
The program should then exit by returnign 0 from main.

c = (p + k) % 26

c = (25 +1) % 26

c = 0 = A

convert ASCII to alphabetical index

ship by formula

convert back to ASCII

LOG 10:39

argc mean the number of arguments.
 argv is the array.

Use echo $? to see the exit status.

LOG 11:57

I've got to admit I'm a little confunsed with the command line
arguments, it makes sense how they've exaplained it, but
agian it opens up the world of unkown. That main isn't
just void, it can accept arguments, and that those arguments
can expand into unknown regions, past the given arguments.
Well let's break it and see what happens.

Ok for starters the program must have a integar and it must be a non negative
integer.

LOG 3:53 PM

That took a little troubleshooting but I took it line by
line and got it working!


*/
