//Alec Thomas
//Hackerrank.com Challenge 
//Week of Code 35 - Lucky Purchase
//Completed - 11/16/2017

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int restrictionChecks(int n, int length, char* bookName, int price)
{
    //n size restriction check
    if( (n < 1) || (n > pow(10,5)) )
    {printf("-1"); return -1;}
    
    //Book name length restriction check
    if((strlen(bookName)>10) || (strlen(bookName)<1))
    {printf("-1"); return -1;}
    
    //Book name only uses english letters check
    for(int i = 0; i<strlen(bookName); i++)
    {
        if( (!((bookName[i] > 64) && (bookName[i] < 91)) && !((bookName[i] > 96) && (bookName[i] < 123))) )
        {printf("-1"); return -1;}
    }
    
    
    //Book price range check
    if( (price < 1) || (price > pow(10,9)))
    {printf("-1"); return -1;}
    
    
    //Only missing price and name uniqueness test
    
    
    return 0;
}


int main() {
    int n; 
    int i;
    scanf("%i", &n);
    
    int bookValues[10]; //array of book prices
    char *ptrsToBooks[n]; //array to hold all the book names
 
    i = 0;
    for(int a0 = 0; a0 < n; a0++){
        char* name = (char *)malloc(512000 * sizeof(char)); //allocates space for all names
        int value; //price of books
        scanf("%s %i", name, &value); //scanning in book names and prices
        
        //Book name length restriction check,
        //Book name english characters check,
        //and Book price range check
        if(restrictionChecks(n,strlen(name),name,value) != 0)
        {return 0;}
        
        //adding books and prices to my arrays outside the loop
        ptrsToBooks[a0] = name;
        bookValues[i] = value;
        i++;
        
    }
    
    
    //Checking prices for 4's and 7's
    int fours = 0; //4 count variable
    int sevens = 0; //7 count variable
    int tempPrice = 0; //temp value for checking integers
    int satisfyingNumBooks = 0; //number of valid book prices found
    int winningBookValues[n]; //prices of valid books
    for(i = 0; i<n; i++)
    {
        fours = 0;
        sevens = 0;
        tempPrice = bookValues[i];
        
        //Checks for individual numbers in the int value
        while(tempPrice != 0)
        {
            if((tempPrice % 10) == 4)
            {fours++;}
            else if((tempPrice % 10) == 7)
            {sevens++;}
            
            tempPrice = tempPrice/10;
        }
        if((fours == sevens) && (fours > 0))
        {
            satisfyingNumBooks++;
            winningBookValues[i] = bookValues[i]; //adds a valid value to an array
        }
        
    }
    
    //Checking if any book prices were valid, 
    //and choosing the best deal
    if(satisfyingNumBooks == 0)
    {printf("-1"); return 0;}
    
    int bestDeal = 0; //best price
    if(satisfyingNumBooks > 1)
    {
        //Checking through valid prices to find lowest
        for(i = 0; i<n; i++)
        {
            if(winningBookValues[i] > winningBookValues[i-1])
            {
                bestDeal = winningBookValues[i];
            }
        }
    }
    
    
    
    //Comparing best deal to all prices and printing the corresponding book
    for(i = 0; i<n; i++)
    {
        if(bookValues[i] == bestDeal)
        {
           printf("%s", ptrsToBooks[i]);
        }
    }
    
    
    return 0;
}

