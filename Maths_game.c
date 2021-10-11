/*assignment1 maths quiz,
synopsis:
    A menu that displays 4 options:
    1. asks the user how many questions they want to for this round
    2. starts the quiz
    3. tells the user how many questions they answered correct or incorrect for the round of questions
    4. exits the program
Author: Raphael Bien Cabangbang
Student number: C19464094
Compiler: Code::Blocks
OS: Windows 10
Date(started): 22/10/19 (17:01), edited: 29/10/19 (15:00), edited 04/11/19 (10:30), edited 4/11/19 (12:42),
               edited 04/11/19 (15:08), edited 05/11/19 (12:02), edited 08/11/19 (15:15), edited 10/11/19 (16:12)
 */



#include <stdio.h>

int main()
{
    int input;                          /*variable for the options*/
    int questions=0;                    /*(=0) defaults the questions requested to 5, when the user selects 2 in the menu*/
    int ans;                            /*variable that stores the user given answer*/
    int q_ans;                          /*variable that stores the generated question's answer*/
    int c_counter=0;                    /*counts the number of questions answered correctly*/
    int w_counter=0;                    /*counts the number of questions answered incorrectly*/
    int i;                              /*used in the for loop*/
    int array1[5]={42,52,5,23,76};      /*numbers for the questions*/
    int question_no =1;                 /*counter that keeps track of what question the user is on*/
    int array[5]={13,41,124,53,65};     /*numbers to be used for the generated questions*/




    do              /*displays the main menu after each option*/
    {


        printf("MAIN MENU \n\n");
        printf("1.  Enter the number of questions to be asked this round of the quiz. (Maximum of 5 questions allowed) \n");
        printf("2.  Start quiz. \n");
        printf("3.  Display the number of questions that were answered (i) correctly and (ii) incorrectly for this round \n");
        printf("4.  Exit program \n\n");
        printf("You entered: ");


        scanf("%d", &input);              /*chooses an option, (couldn't find a way to fix if the user inputs a character example: a)*/

        switch(input)                     /*determines what happens*/
        {

            case 1:                    /*declares the number of questions that will be asked?*/
            {
                question_no=1;       /*makes a new round which resets option3 condition*/

                printf("\n\nHow many questions for this round? (Maximum of 5 questions allowed) \n");

                scanf("%d", &questions);                /*user inputs the amount of questions*/


                if(questions>5 || questions<1)                /*tells the user if they entered a valid or invalid amount of questions*/
                {
                    printf("\n\nyou entered an invalid number of questions \n\n\n");
                }

                else
                {
                    printf("\n\nyou have requested %d questions \n\n\n", questions);
                }

                break;
            }

            case 2:                        /*Starts the quiz*/
            {
                question_no = 1;                 /*resets the question no. & resets option3 condition*/
                c_counter =0;                   /*resets the correct answer counter*/
                w_counter =0;                   /*resets the incorrect answer counter*/


                if(questions<=5 && questions>=1)        /*if given amount of questions (selected 1 from the menu)*/
                {

                    for(i=0;i<questions;i++)                 /*asks questions and loops around*/
                    {
                        printf("\n\nQ%d: %d + %d \n", question_no, array[i], array1[i]);        /*shows the question*/


                        ans= array[i] + array1[i];            /*the answer to the generated question*/
                        scanf("%d", &q_ans);          /*ask the user for their answer*/
                        question_no++;              /*increases the question number to the amount of questions requested*/


                        if(q_ans==ans)                          /*checks if the user's answer is the same as the generated questions answer*/
                        {
                            printf("Your answer=%d -Correct, The correct answer=%d \n\n", q_ans, ans);          /*tells the user he is correct*/
                            c_counter++;                /*counts correct answers*/
                        }
                        else
                        {
                            printf("Your answer=%d -Wrong, The correct answer=%d \n\n", q_ans, ans);        /*tells the user he is incorrect*/
                            w_counter++;                /*counts wrong answers*/
                        }
                    }
                }

                else if(questions==0)                   /*if not given an amount of questions, (user did not select 1 from the menu, defaults to 5)*/
                {
                    printf("\n\nyou have not requested any questions\n");   /*tells the user they have not requested questions*/
                    printf("defaults to 5 questions\n");                    /*tells the user it defaults the amount of questions to 5*/


                    for(i=0;i<5;i++)                       /*asks questions and loops around*/
                    {

                        printf("\n\nQ%d: %d + %d \n", question_no, array[i], array1[i]);  /*displays the question*/

                        ans= array[i] + array1[i];            /*the answer to the generated question*/
                        scanf("%d", &q_ans);                  /*ask the user for their answer*/
                        question_no++;                        /*increases the question number to the amount of questions requested*/


                        if(q_ans==ans)                              /* checks if the user's answer is the same as the generated questions answer*/
                        {
                            printf("Your answer = %d -Correct, The correct answer = %d \n\n", q_ans, ans);          /*tells the user he is correct*/
                            c_counter = c_counter+1;                /*counts correct answers*/
                        }
                        else
                        {
                            printf("Your answer=%d -Wrong, The correct answer=%d \n\n", q_ans, ans);        /*tells the user he is incorrect*/
                            w_counter = w_counter+1;                /*counts wrong answers*/
                        }
                    }
                }

                break;
            }

            case 3:                                                /*displays the number of correct and incorrect questions*/
            {
                if(question_no==1)                                /*condition is when the user hasn't done a quiz*/
                {
                    printf("\n\nYou have not answered any questions for this round\n\n\n");   /*tells the user that they have not done a quiz*/
                    break;
                }
                else
                {
                    printf("\n\n%d correct\n", c_counter);          /*displays the amount of correct questions*/
                    printf("%d incorrect\n\n\n", w_counter);        /*displays the amount of wrong question*/
                    break;
                }
            }

            case 4:                 /*exits the program*/
            {
                return 0;
                break;

            }
            default:                  /*error message when invalid input*/
            {
                printf("\n\ninvalid Option\n\n\n");
            }
        }
    }

    while(input!=4); /*makes sure the program doesn't close when pressing any key besides 4*/

    return 0;
}
