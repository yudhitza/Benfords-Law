//******************************************************************************
// fake.cpp
//******************************************************************************
// Name: Francheska Orellana
//******************************************************************************
// Collaborators/outside sources used (IMPORTANT!):
// Evan Fink
// https://en.wikipedia.org/wiki/Benford's_law for stats & formula
// Reminder: you are to write your own code.
//******************************************************************************
// Comments: THE FAKE ONE IS r08.txt!!!!
// Also I decided to try putting in the ranges like we talked about and I did it so that if the numbers don't fall within benford's numbers +/- 7 then it is fake; I know the homeowrk asked to print the percentages out ... but since we talked about this I thought it would be acceptable...anyways just in case, I backslashed a line to print the precentages out -- if the if statements after that line are removed then it should print out everything... 
// However, this range is fixed to work on these files but I'm not so sure it would work on other files that have numbers that go beyond a range of 7. For instance, if you have the range of 3 and use it to find if r05 is fake, then it will say it is fake because the percentage for the leading  #1 goes beyond 30.1 (Benford's law) + 3 -- it is 34 ish... so is there ever really a perfect range?

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;


int main()
{
    int times;                              //Declaring how many times a number will be read
    string name;                            //Declaring string name to store the file name in
    cout << "Enter file name to open: " ;
    cin >> name;
    
    ifstream fileIn;                        //Declaring a file to open
    fileIn.open(name.c_str());              //Opening file with the string name
    
    
    string useless;                         //Creating a string to ignore the first line in the file
    getline(fileIn,useless);
    
    string number;                           //Declaring string for each number in the file
    
    int countArray[10]={0,0,0,0,0,0,0,0,0,0}; //Setting an array to all 0's
    while (fileIn.peek() != EOF)            //Going through entire file
    {
        fileIn >> number;                   //Reading a number
        int digit = number.at(0) - '0';    //Declaring an int by subtracting the first digit of the number char by the char 0 to get an actual number equavalent to what the char was
        for (int i = 0; i <=9; i++)        //Count loop for the array
        {
            if (digit == i)                //If the first digit of the number is qual to i then the array[i] will have 1 added to it
                countArray[i]++;
            
        }
        
         times++;                       //Keeps count of home many numbers there are in the file
    }
    
    for (int i = 1;i<= 9; i++)          // printing the percentages
        cout << i << ": " << setprecision(2) << fixed << (countArray[i]/(times*1.0))*100 << "%" << endl;
    

    
    bool fake = true;                   //Creating a bool func and making fake = true
    for (int i=1; i<=9; i++)
    {
        double p, q, actualPercent;     //Declaring P to represent the lower bound of Benfords law, Q to represnt the upper bound of Benfords law, and actualPrecent to represent the precentages in this particular file
        p= (log10(1.0+(1.0/i))*100-7);
        q= (log10(1.0+(1.0/i))*100+7);
        actualPercent = ((countArray[i]*1.0)/times)*100;
        
        
        if ((actualPercent <=q) && (actualPercent >=p)) //If the precentages for this file fall in between the bounds then the file is not fake
            fake = false;
        else                                    //If they do no then the file is still fake
            break;
    }
    
    if (fake)                               //If file is still fake then the file is fake
        cout << "This file is: FAKE" << endl;
    else                                    //Else file is nor longer fake so it is a real file
        cout << "This file is: THE REAL DEAL" << endl;

    
    fileIn.close();                     //Closing file
    
    system("pause");
    return 0;
}
