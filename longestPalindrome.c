// A O(n^2) time and O(1) space program to find the longest palindromic substring
#include <stdio.h>
#include <string.h>
 
// A utility function to print a substring str[low..high]
void printSubStr(char* str, int low, int high)
{
    int i;
    for(  i = low; i <= high; ++i )
        printf("%c", str[i]);
}
 
int max(int a, int b) { return a > b ? a:b; }
// This function prints the longest palindrome substring (LPS)
// of str[]. It also returns the length of the longest palindrome
int longestPalSubstr(char *str)
{
    int maxLength = 1;  // The result (length of LPS)
 
    int start = 0;
    int len = strlen(str);
 
    int low, high;
    int i;
    // One by one consider every character as center point of
    // even and length palindromes
    for ( i = 0; i < len; ++i)
    {
        // Find the longest even length palindrome with center points
        low = i;
        high = i+1;
        while(low>=0 && high<len && (str[low]==str[high]))
        {
           //update the length before you change the index
           maxLength = max(maxLength, high - low + 1);
           low--;
           high++;
        }

 
        // Find the longest odd length palindrome with center
        // point as i
        low = i-1;
        high = i+1;
        while(low>=0 && high<len && (str[low]==str[high]))
        {
           maxLength = max(maxLength, high - low + 1);       
           low--;
           high++;
        }

    }
 
    printf("Longest palindrome substring is: ");
    printSubStr(str, start, start + maxLength - 1);
 
    return maxLength;
}
 
// Driver program to test above functions
int main()
{
    char str[] = "forgeeksskeegfor";
    printf("\nLength is: %d\n", longestPalSubstr( str ) );
    return 0;
}
