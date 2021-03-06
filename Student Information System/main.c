#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void check_password(int pass,char name[])
{
  int choice;
  float midterms[10][5];
  float finals[10][5];
  float average[10][5];
  char status[10][5];
  char lettergrade[10][5];
  char lettergrade2[10][5];
  float GPA[10][5];
  int weights[5] = {6,10,4,6,4};
  float WGPA[10];
  int i,j,id;
  float sum;

    for(i=0;i<10;i++)
        {
        sum = 0;
        for(j=0;j<5;j++)
        {
          midterms[i][j] = (rand()%90)+10;
          finals[i][j] = (rand()%90)+10;
          average[i][j] = ((midterms[i][j]*4)+(finals[i][j]*6))/10;
          if(average[i][j]<60)
          {
            status[i][j] = 'X';
          }
          else
          {
            status[i][j] = 'O';
          }
            if(average[i][j]<50)
            {
               GPA[i][j]=0;
               lettergrade[i][j]='F';
               lettergrade2[i][j]='F';
            }
            else if(50<=average[i][j] && average[i][j]<60)
            {
               GPA[i][j]=0.5;
               lettergrade[i][j]='F';
               lettergrade2[i][j]='D';
            }
            else if(60<=average[i][j] && average[i][j]<65)
            {
               GPA[i][j]=1.0;
               lettergrade[i][j]='D';
               lettergrade2[i][j]='D';
            }
            else if(65<=average[i][j] && average[i][j]<70)
            {
               GPA[i][j]=1.5;
               lettergrade[i][j]='D';
               lettergrade2[i][j]='C';
            }
            else if(70<=average[i][j] && average[i][j]<75)
            {
               GPA[i][j]=2.0;
               lettergrade[i][j]='C';
               lettergrade2[i][j]='C';
            }
            else if(75<=average[i][j] && average[i][j]<80)
            {
               GPA[i][j]=2.5;
               lettergrade[i][j]='C';
               lettergrade2[i][j]='B';
            }
            else if(80<=average[i][j] && average[i][j]<85)
            {
               GPA[i][j]=3.0;
               lettergrade[i][j]='B';
               lettergrade2[i][j]='B';
            }
            else if(85<=average[i][j] && average[i][j]<90)
            {
               GPA[i][j]=3.5;
               lettergrade[i][j]='B';
               lettergrade2[i][j]='A';
            }
            else
            {
               GPA[i][j]=4.0;
               lettergrade[i][j]='A';
               lettergrade2[i][j]='A';
            }
             sum = sum + GPA[i][j]*weights[j];
        }
        WGPA[i] = sum/30;
    }

    int work =1;

    while(work==1)
        {
        if (pass==123 && strcmp("Steffi",name)==0 )
        {
            id=0;
            printf("====================================\n");
            printf("1.Personal information\n");
            printf("2.Course overview\n");
            printf("3.General grade status\n");
            printf("4.General information status\n");
            printf("5.Exit\n");
            printf("\n>>Please, press the number for the\ninformation you want to receive.\n");
            printf("====================================\n");
            scanf("%d",&choice);

            if(choice ==1 )
            {
                printf("====================================\n");
                printf("Name         : Steffi\n");
                printf("Surname      : Kerner\n");
                printf("Number       : %d\n",id+1);
                printf("Nationality  : German\n");
                printf("Date of Birth: 10/10/2000\n");
                printf("====================================\n");
            }
            else if(choice ==2)
            {
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       MIDTERM  FINAL  STATUS\n");
                printf("Math         :  %.0f      %.0f       %c  \n",midterms[id][0],finals[id][0],status[id][0]);
                printf("C Programming:  %.0f      %.0f       %c  \n",midterms[id][1],finals[id][1],status[id][1]);
                printf("Physics      :  %.0f      %.0f       %c  \n",midterms[id][2],finals[id][2],status[id][2]);
                printf("L.Algebra    :  %.0f      %.0f       %c  \n",midterms[id][3],finals[id][3],status[id][3]);
                printf("Chemistry    :  %.0f      %.0f       %c  \n",midterms[id][4],finals[id][4],status[id][4]);
                printf("====================================\n");
            }
            else if(choice ==3)
            {
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       AVERAGE  GPA   LETTERG\n");
                printf("Math         :  %.0f      %.1f       %c%c  \n",average[id][0],GPA[id][0],lettergrade[id][0],lettergrade2[id][0]);
                printf("C Programming:  %.0f      %.1f       %c%c  \n",average[id][1],GPA[id][1],lettergrade[id][1],lettergrade2[id][1]);
                printf("Physics      :  %.0f      %.1f       %c%c  \n",average[id][2],GPA[id][2],lettergrade[id][2],lettergrade2[id][2]);
                printf("L.Algebra    :  %.0f      %.1f       %c%c  \n",average[id][3],GPA[id][3],lettergrade[id][3],lettergrade2[id][3]);
                printf("Chemistry    :  %.0f      %.1f       %c%c  \n",average[id][4],GPA[id][4],lettergrade[id][4],lettergrade2[id][4]);
                printf("Weighted GPA = %.2f \n",WGPA[id]);
                printf("====================================\n");

            }
            else if(choice ==4)
            {
                printf("========================================\n");
                printf("__General Information About System__\n\n");
                printf("This system contains various information\nof students in a class of 10 people.\n");
                printf("\n___Frequently Asked Questions___\n");
                printf("\nQ1 => How is grade point average taken?\nAnswer: 40 percent of midterm and 60\npercent of final are summed.\n");
                printf("\nQ2 => How do you calculate WGPA?\n");
                printf("Answer:Every lesson has it's own weight.\nHence, we multiply GPA with this\nweights and then divide them with total\nweight which is 30.\n");
                printf("\nQ3=> What does 'X' and 'O' mean in the\nCourse overview?\nAnswer: 'O' means you passed the\ncourse successfully, 'X' means you\nfailed the course unfortunately.\n");
                printf("========================================\n");
            } else
            {
                work=0;
            }
        }
          if (pass==345 && strcmp("Ricohard",name)==0 )
          {
            id=1;
            printf("====================================\n");
            printf("1.Personal information\n");
            printf("2.Course overview\n");
            printf("3.General grade status\n");
            printf("4.General information status\n");
            printf("5.Exit\n");
            printf("\n>>Please, press the number for the\ninformation you want to receive.\n");
            printf("====================================\n");
            scanf("%d",&choice);

            if(choice ==1 )
            {
                printf("====================================\n");
                printf("Name         : Ricohard\n");
                printf("Surname      : Grenville\n");
                printf("Number       : %d\n",id+1);
                printf("Nationality  : USA\n");
                printf("Date of Birth: 09/11/1999\n");
                printf("====================================\n");
            }
            else if(choice ==2)
            {
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       MIDTERM  FINAL  STATUS\n");
                printf("Math         :  %.0f      %.0f       %c  \n",midterms[id][0],finals[id][0],status[id][0]);
                printf("C Programming:  %.0f      %.0f       %c  \n",midterms[id][1],finals[id][1],status[id][1]);
                printf("Physics      :  %.0f      %.0f       %c  \n",midterms[id][2],finals[id][2],status[id][2]);
                printf("L.Algebra    :  %.0f      %.0f       %c  \n",midterms[id][3],finals[id][3],status[id][3]);
                printf("Chemistry    :  %.0f      %.0f       %c  \n",midterms[id][4],finals[id][4],status[id][4]);
                printf("====================================\n");
            }
            else if(choice ==3)
            {
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       AVERAGE  GPA   LETTERG\n");
                printf("Math         :  %.0f      %.1f       %c%c  \n",average[id][0],GPA[id][0],lettergrade[id][0],lettergrade2[id][0]);
                printf("C Programming:  %.0f      %.1f       %c%c  \n",average[id][1],GPA[id][1],lettergrade[id][1],lettergrade2[id][1]);
                printf("Physics      :  %.0f      %.1f       %c%c  \n",average[id][2],GPA[id][2],lettergrade[id][2],lettergrade2[id][2]);
                printf("L.Algebra    :  %.0f      %.1f       %c%c  \n",average[id][3],GPA[id][3],lettergrade[id][3],lettergrade2[id][3]);
                printf("Chemistry    :  %.0f      %.1f       %c%c  \n",average[id][4],GPA[id][4],lettergrade[id][4],lettergrade2[id][4]);
                printf("Weighted GPA = %.2f \n",WGPA[id]);
                printf("====================================\n");

            }
            else if(choice ==4)
            {
                printf("========================================\n");
                printf("__General Information About System__\n\n");
                printf("This system contains various information\nof students in a class of 10 people.\n");
                printf("\n___Frequently Asked Questions___\n");
                printf("\nQ1 => How is grade point average taken?\nAnswer: 40 percent of midterm and 60\npercent of final are summed.\n");
                printf("\nQ2 => How do you calculate WGPA?\n");
                printf("Answer:Every lesson has it's own weight.\nHence, we multiply GPA with this\nweights and then divide them with total\nweight which is 30.\n");
                printf("\nQ3=> What does 'X' and 'O' mean in the\nCourse overview?\nAnswer: 'O' means you passed the\ncourse successfully, 'X' means you\nfailed the course unfortunately.\n");
                printf("========================================\n");
            } else
            {
                work=0;
            }
        }
          if (pass==678 && strcmp("Anni",name)==0 )
          {
            id=2;
            printf("====================================\n");
            printf("1.Personal information\n");
            printf("2.Course overview\n");
            printf("3.General grade status\n");
            printf("4.General information status\n");
            printf("5.Exit\n");
            printf("\n>>Please, press the number for the\ninformation you want to receive.\n");
            printf("====================================\n");
            scanf("%d",&choice);

            if(choice ==1 )
            {
                printf("====================================\n");
                printf("Name         : Anni\n");
                printf("Surname      : Clinton\n");
                printf("Number       : %d\n",id+1);
                printf("Nationality  : USA\n");
                printf("Date of Birth: 17/05/2001\n");
                printf("====================================\n");
            }
            else if(choice ==2)
            {
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       MIDTERM  FINAL  STATUS\n");
                printf("Math         :  %.0f      %.0f       %c  \n",midterms[id][0],finals[id][0],status[id][0]);
                printf("C Programming:  %.0f      %.0f       %c  \n",midterms[id][1],finals[id][1],status[id][1]);
                printf("Physics      :  %.0f      %.0f       %c  \n",midterms[id][2],finals[id][2],status[id][2]);
                printf("L.Algebra    :  %.0f      %.0f       %c  \n",midterms[id][3],finals[id][3],status[id][3]);
                printf("Chemistry    :  %.0f      %.0f       %c  \n",midterms[id][4],finals[id][4],status[id][4]);
                printf("====================================\n");
            }
            else if(choice ==3)
            {
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       AVERAGE  GPA   LETTERG\n");
                printf("Math         :  %.0f      %.1f       %c%c  \n",average[id][0],GPA[id][0],lettergrade[id][0],lettergrade2[id][0]);
                printf("C Programming:  %.0f      %.1f       %c%c  \n",average[id][1],GPA[id][1],lettergrade[id][1],lettergrade2[id][1]);
                printf("Physics      :  %.0f      %.1f       %c%c  \n",average[id][2],GPA[id][2],lettergrade[id][2],lettergrade2[id][2]);
                printf("L.Algebra    :  %.0f      %.1f       %c%c  \n",average[id][3],GPA[id][3],lettergrade[id][3],lettergrade2[id][3]);
                printf("Chemistry    :  %.0f      %.1f       %c%c  \n",average[id][4],GPA[id][4],lettergrade[id][4],lettergrade2[id][4]);
                printf("Weighted GPA = %.2f \n",WGPA[id]);
                printf("====================================\n");

            }
            else if(choice ==4)
            {
                printf("========================================\n");
                printf("__General Information About System__\n\n");
                printf("This system contains various information\nof students in a class of 10 people.\n");
                printf("\n___Frequently Asked Questions___\n");
                printf("\nQ1 => How is grade point average taken?\nAnswer: 40 percent of midterm and 60\npercent of final are summed.\n");
                printf("\nQ2 => How do you calculate WGPA?\n");
                printf("Answer:Every lesson has it's own weight.\nHence, we multiply GPA with this\nweights and then divide them with total\nweight which is 30.\n");
                printf("\nQ3=> What does 'X' and 'O' mean in the\nCourse overview?\nAnswer: 'O' means you passed the\ncourse successfully, 'X' means you\nfailed the course unfortunately.\n");
                printf("========================================\n");
            } else
            {
                work=0;
            }
        }
          if (pass==911 && strcmp("Arnold",name)==0 )
          {
            id=3;
            printf("====================================\n");
            printf("1.Personal information\n");
            printf("2.Course overview\n");
            printf("3.General grade status\n");
            printf("4.General information status\n");
            printf("5.Exit\n");
            printf("\n>>Please, press the number for the\ninformation you want to receive.\n");
            printf("====================================\n");
            scanf("%d",&choice);

            if(choice ==1 )
            {
                printf("====================================\n");
                printf("Name         : Arnold\n");
                printf("Surname      : Grosse\n");
                printf("Number       : %d\n",id+1);
                printf("Nationality  : German\n");
                printf("Date of Birth: 30/08/1999\n");
                printf("====================================\n");
            }
            else if(choice ==2)
            {
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       MIDTERM  FINAL  STATUS\n");
                printf("Math         :  %.0f      %.0f       %c  \n",midterms[id][0],finals[id][0],status[id][0]);
                printf("C Programming:  %.0f      %.0f       %c  \n",midterms[id][1],finals[id][1],status[id][1]);
                printf("Physics      :  %.0f      %.0f       %c  \n",midterms[id][2],finals[id][2],status[id][2]);
                printf("L.Algebra    :  %.0f      %.0f       %c  \n",midterms[id][3],finals[id][3],status[id][3]);
                printf("Chemistry    :  %.0f      %.0f       %c  \n",midterms[id][4],finals[id][4],status[id][4]);
                printf("====================================\n");
            }
            else if(choice ==3)
            {
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       AVERAGE  GPA   LETTERG\n");
                printf("Math         :  %.0f      %.1f       %c%c  \n",average[id][0],GPA[id][0],lettergrade[id][0],lettergrade2[id][0]);
                printf("C Programming:  %.0f      %.1f       %c%c  \n",average[id][1],GPA[id][1],lettergrade[id][1],lettergrade2[id][1]);
                printf("Physics      :  %.0f      %.1f       %c%c  \n",average[id][2],GPA[id][2],lettergrade[id][2],lettergrade2[id][2]);
                printf("L.Algebra    :  %.0f      %.1f       %c%c  \n",average[id][3],GPA[id][3],lettergrade[id][3],lettergrade2[id][3]);
                printf("Chemistry    :  %.0f      %.1f       %c%c  \n",average[id][4],GPA[id][4],lettergrade[id][4],lettergrade2[id][4]);
                printf("Weighted GPA = %.2f \n",WGPA[id]);
                printf("====================================\n");

            }
            else if(choice ==4)
            {
                printf("========================================\n");
                printf("__General Information About System__\n\n");
                printf("This system contains various information\nof students in a class of 10 people.\n");
                printf("\n___Frequently Asked Questions___\n");
                printf("\nQ1 => How is grade point average taken?\nAnswer: 40 percent of midterm and 60\npercent of final are summed.\n");
                printf("\nQ2 => How do you calculate WGPA?\n");
                printf("Answer:Every lesson has it's own weight.\nHence, we multiply GPA with this\nweights and then divide them with total\nweight which is 30.\n");
                printf("\nQ3=> What does 'X' and 'O' mean in the\nCourse overview?\nAnswer: 'O' means you passed the\ncourse successfully, 'X' means you\nfailed the course unfortunately.\n");
                printf("========================================\n");
            } else
            {
                work=0;
            }
        }
          if (pass==132 && strcmp("Pharaildis",name)==0 )
          {
            id=4;
            printf("====================================\n");
            printf("1.Personal information\n");
            printf("2.Course overview\n");
            printf("3.General grade status\n");
            printf("4.General information status\n");
            printf("5.Exit\n");
            printf("\n>>Please, press the number for the\ninformation you want to receive.\n");
            printf("====================================\n");
            scanf("%d",&choice);

            if(choice ==1 )
            {
                printf("====================================\n");
                printf("Name         : Pharaildis\n");
                printf("Surname      : Cason\n");
                printf("Number       : %d\n",id+1);
                printf("Nationality  : Greek\n");
                printf("Date of Birth: 06/01/2001\n");
                printf("====================================\n");
            }
            else if(choice ==2)
            {
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       MIDTERM  FINAL  STATUS\n");
                printf("Math         :  %.0f      %.0f       %c  \n",midterms[id][0],finals[id][0],status[id][0]);
                printf("C Programming:  %.0f      %.0f       %c  \n",midterms[id][1],finals[id][1],status[id][1]);
                printf("Physics      :  %.0f      %.0f       %c  \n",midterms[id][2],finals[id][2],status[id][2]);
                printf("L.Algebra    :  %.0f      %.0f       %c  \n",midterms[id][3],finals[id][3],status[id][3]);
                printf("Chemistry    :  %.0f      %.0f       %c  \n",midterms[id][4],finals[id][4],status[id][4]);
                printf("====================================\n");
            }
            else if(choice ==3)
            {
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       AVERAGE  GPA   LETTERG\n");
                printf("Math         :  %.0f      %.1f       %c%c  \n",average[id][0],GPA[id][0],lettergrade[id][0],lettergrade2[id][0]);
                printf("C Programming:  %.0f      %.1f       %c%c  \n",average[id][1],GPA[id][1],lettergrade[id][1],lettergrade2[id][1]);
                printf("Physics      :  %.0f      %.1f       %c%c  \n",average[id][2],GPA[id][2],lettergrade[id][2],lettergrade2[id][2]);
                printf("L.Algebra    :  %.0f      %.1f       %c%c  \n",average[id][3],GPA[id][3],lettergrade[id][3],lettergrade2[id][3]);
                printf("Chemistry    :  %.0f      %.1f       %c%c  \n",average[id][4],GPA[id][4],lettergrade[id][4],lettergrade2[id][4]);
                printf("Weighted GPA = %.2f \n",WGPA[id]);
                printf("====================================\n");

            }
            else if(choice ==4)
            {
                printf("========================================\n");
                printf("__General Information About System__\n\n");
                printf("This system contains various information\nof students in a class of 10 people.\n");
                printf("\n___Frequently Asked Questions___\n");
                printf("\nQ1 => How is grade point average taken?\nAnswer: 40 percent of midterm and 60\npercent of final are summed.\n");
                printf("\nQ2 => How do you calculate WGPA?\n");
                printf("Answer:Every lesson has it's own weight.\nHence, we multiply GPA with this\nweights and then divide them with total\nweight which is 30.\n");
                printf("\nQ3=> What does 'X' and 'O' mean in the\nCourse overview?\nAnswer: 'O' means you passed the\ncourse successfully, 'X' means you\nfailed the course unfortunately.\n");
                printf("========================================\n");
            } else
            {
                work=0;
            }
        }
          if (pass==321 && strcmp("Lena",name)==0 )
          {
            id=5;
            printf("====================================\n");
            printf("1.Personal information\n");
            printf("2.Course overview\n");
            printf("3.General grade status\n");
            printf("4.General information status\n");
            printf("5.Exit\n");
            printf("\n>>Please, press the number for the\ninformation you want to receive.\n");
            printf("====================================\n");
            scanf("%d",&choice);

            if(choice ==1 )
            {
                printf("====================================\n");
                printf("Name         : Lena\n");
                printf("Surname      : Loris\n");
                printf("Number       : %d\n",id+1);
                printf("Nationality  : English\n");
                printf("Date of Birth: 02/02/2002\n");
                printf("====================================\n");
            }
            else if(choice ==2)
            {
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       MIDTERM  FINAL  STATUS\n");
                printf("Math         :  %.0f      %.0f       %c  \n",midterms[id][0],finals[id][0],status[id][0]);
                printf("C Programming:  %.0f      %.0f       %c  \n",midterms[id][1],finals[id][1],status[id][1]);
                printf("Physics      :  %.0f      %.0f       %c  \n",midterms[id][2],finals[id][2],status[id][2]);
                printf("L.Algebra    :  %.0f      %.0f       %c  \n",midterms[id][3],finals[id][3],status[id][3]);
                printf("Chemistry    :  %.0f      %.0f       %c  \n",midterms[id][4],finals[id][4],status[id][4]);
                printf("====================================\n");
            }
            else if(choice ==3)
            {
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       AVERAGE  GPA   LETTERG\n");
                printf("Math         :  %.0f      %.1f       %c%c  \n",average[id][0],GPA[id][0],lettergrade[id][0],lettergrade2[id][0]);
                printf("C Programming:  %.0f      %.1f       %c%c  \n",average[id][1],GPA[id][1],lettergrade[id][1],lettergrade2[id][1]);
                printf("Physics      :  %.0f      %.1f       %c%c  \n",average[id][2],GPA[id][2],lettergrade[id][2],lettergrade2[id][2]);
                printf("L.Algebra    :  %.0f      %.1f       %c%c  \n",average[id][3],GPA[id][3],lettergrade[id][3],lettergrade2[id][3]);
                printf("Chemistry    :  %.0f      %.1f       %c%c  \n",average[id][4],GPA[id][4],lettergrade[id][4],lettergrade2[id][4]);
                printf("Weighted GPA = %.2f \n",WGPA[id]);
                printf("====================================\n");

            }
            else if(choice ==4)
            {
                printf("========================================\n");
                printf("__General Information About System__\n\n");
                printf("This system contains various information\nof students in a class of 10 people.\n");
                printf("\n___Frequently Asked Questions___\n");
                printf("\nQ1 => How is grade point average taken?\nAnswer: 40 percent of midterm and 60\npercent of final are summed.\n");
                printf("\nQ2 => How do you calculate WGPA?\n");
                printf("Answer:Every lesson has it's own weight.\nHence, we multiply GPA with this\nweights and then divide them with total\nweight which is 30.\n");
                printf("\nQ3=> What does 'X' and 'O' mean in the\nCourse overview?\nAnswer: 'O' means you passed the\ncourse successfully, 'X' means you\nfailed the course unfortunately.\n");
                printf("========================================\n");
            } else
            {
                work=0;
            }
        }
          if (pass==654 && strcmp("Vera",name)==0 )
          {
            id=6;
            printf("====================================\n");
            printf("1.Personal information\n");
            printf("2.Course overview\n");
            printf("3.General grade status\n");
            printf("4.General information status\n");
            printf("5.Exit\n");
            printf("\n>>Please, press the number for the\ninformation you want to receive.\n");
            printf("====================================\n");
            scanf("%d",&choice);

            if(choice ==1 )
            {
                printf("====================================\n");
                printf("Name         : Vera\n");
                printf("Surname      : Getsby\n");
                printf("Number       : %d\n",id+1);
                printf("Nationality  : Russian\n");
                printf("Date of Birth: 07/03/2001\n");
                printf("====================================\n");
            }
            else if(choice ==2)
            {
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       MIDTERM  FINAL  STATUS\n");
                printf("Math         :  %.0f      %.0f       %c  \n",midterms[id][0],finals[id][0],status[id][0]);
                printf("C Programming:  %.0f      %.0f       %c  \n",midterms[id][1],finals[id][1],status[id][1]);
                printf("Physics      :  %.0f      %.0f       %c  \n",midterms[id][2],finals[id][2],status[id][2]);
                printf("L.Algebra    :  %.0f      %.0f       %c  \n",midterms[id][3],finals[id][3],status[id][3]);
                printf("Chemistry    :  %.0f      %.0f       %c  \n",midterms[id][4],finals[id][4],status[id][4]);
                printf("====================================\n");
            }
            else if(choice ==3)
            {
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       AVERAGE  GPA   LETTERG\n");
                printf("Math         :  %.0f      %.1f       %c%c  \n",average[id][0],GPA[id][0],lettergrade[id][0],lettergrade2[id][0]);
                printf("C Programming:  %.0f      %.1f       %c%c  \n",average[id][1],GPA[id][1],lettergrade[id][1],lettergrade2[id][1]);
                printf("Physics      :  %.0f      %.1f       %c%c  \n",average[id][2],GPA[id][2],lettergrade[id][2],lettergrade2[id][2]);
                printf("L.Algebra    :  %.0f      %.1f       %c%c  \n",average[id][3],GPA[id][3],lettergrade[id][3],lettergrade2[id][3]);
                printf("Chemistry    :  %.0f      %.1f       %c%c  \n",average[id][4],GPA[id][4],lettergrade[id][4],lettergrade2[id][4]);
                printf("Weighted GPA = %.2f \n",WGPA[id]);
                printf("====================================\n");

            }
            else if(choice ==4)
            {
                printf("========================================\n");
                printf("__General Information About System__\n\n");
                printf("This system contains various information\nof students in a class of 10 people.\n");
                printf("\n___Frequently Asked Questions___\n");
                printf("\nQ1 => How is grade point average taken?\nAnswer: 40 percent of midterm and 60\npercent of final are summed.\n");
                printf("\nQ2 => How do you calculate WGPA?\n");
                printf("Answer:Every lesson has it's own weight.\nHence, we multiply GPA with this\nweights and then divide them with total\nweight which is 30.\n");
                printf("\nQ3=> What does 'X' and 'O' mean in the\nCourse overview?\nAnswer: 'O' means you passed the\ncourse successfully, 'X' means you\nfailed the course unfortunately.\n");
                printf("========================================\n");
            } else
            {
                work=0;
            }
        }
          if (pass==987 && strcmp("Alana",name)==0 )
          {
            id=7;
            printf("====================================\n");
            printf("1.Personal information\n");
            printf("2.Course overview\n");
            printf("3.General grade status\n");
            printf("4.General information status\n");
            printf("5.Exit\n");
            printf("\n>>Please, press the number for the\ninformation you want to receive.\n");
            printf("====================================\n");
            scanf("%d",&choice);

            if(choice ==1 )
            {
                printf("====================================\n");
                printf("Name         : Alana\n");
                printf("Surname      : Kurz\n");
                printf("Number       : %d\n",id+1);
                printf("Nationality  : Swedish\n");
                printf("Date of Birth: 12/04/2000\n");
                printf("====================================\n");
            }
            else if(choice ==2){
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       MIDTERM  FINAL  STATUS\n");
                printf("Math         :  %.0f      %.0f       %c  \n",midterms[id][0],finals[id][0],status[id][0]);
                printf("C Programming:  %.0f      %.0f       %c  \n",midterms[id][1],finals[id][1],status[id][1]);
                printf("Physics      :  %.0f      %.0f       %c  \n",midterms[id][2],finals[id][2],status[id][2]);
                printf("L.Algebra    :  %.0f      %.0f       %c  \n",midterms[id][3],finals[id][3],status[id][3]);
                printf("Chemistry    :  %.0f      %.0f       %c  \n",midterms[id][4],finals[id][4],status[id][4]);
                printf("====================================\n");
            }
            else if(choice ==3)
            {
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       AVERAGE  GPA   LETTERG\n");
                printf("Math         :  %.0f      %.1f       %c%c  \n",average[id][0],GPA[id][0],lettergrade[id][0],lettergrade2[id][0]);
                printf("C Programming:  %.0f      %.1f       %c%c  \n",average[id][1],GPA[id][1],lettergrade[id][1],lettergrade2[id][1]);
                printf("Physics      :  %.0f      %.1f       %c%c  \n",average[id][2],GPA[id][2],lettergrade[id][2],lettergrade2[id][2]);
                printf("L.Algebra    :  %.0f      %.1f       %c%c  \n",average[id][3],GPA[id][3],lettergrade[id][3],lettergrade2[id][3]);
                printf("Chemistry    :  %.0f      %.1f       %c%c  \n",average[id][4],GPA[id][4],lettergrade[id][4],lettergrade2[id][4]);
                printf("Weighted GPA = %.2f \n",WGPA[id]);
                printf("====================================\n");

            }
            else if(choice ==4)
            {
                printf("========================================\n");
                printf("__General Information About System__\n\n");
                printf("This system contains various information\nof students in a class of 10 people.\n");
                printf("\n___Frequently Asked Questions___\n");
                printf("\nQ1 => How is grade point average taken?\nAnswer: 40 percent of midterm and 60\npercent of final are summed.\n");
                printf("\nQ2 => How do you calculate WGPA?\n");
                printf("Answer:Every lesson has it's own weight.\nHence, we multiply GPA with this\nweights and then divide them with total\nweight which is 30.\n");
                printf("\nQ3=> What does 'X' and 'O' mean in the\nCourse overview?\nAnswer: 'O' means you passed the\ncourse successfully, 'X' means you\nfailed the course unfortunately.\n");
                printf("========================================\n");
            } else
            {
                work=0;
            }
        }
          if (pass==623 && strcmp("Jasmine",name)==0 )
          {
            id=8;
            printf("====================================\n");
            printf("1.Personal information\n");
            printf("2.Course overview\n");
            printf("3.General grade status\n");
            printf("4.General information status\n");
            printf("5.Exit\n");
            printf("\n>>Please, press the number for the\ninformation you want to receive.\n");
            printf("====================================\n");
            scanf("%d",&choice);

            if(choice ==1 )
            {
                printf("====================================\n");
                printf("Name         : Jasmine\n");
                printf("Surname      : Stars\n");
                printf("Number       : %d\n",id+1);
                printf("Nationality  : Indian\n");
                printf("Date of Birth: 22/01/2001\n");
                printf("====================================\n");
            }
            else if(choice ==2)
            {
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       MIDTERM  FINAL  STATUS\n");
                printf("Math         :  %.0f      %.0f       %c  \n",midterms[id][0],finals[id][0],status[id][0]);
                printf("C Programming:  %.0f      %.0f       %c  \n",midterms[id][1],finals[id][1],status[id][1]);
                printf("Physics      :  %.0f      %.0f       %c  \n",midterms[id][2],finals[id][2],status[id][2]);
                printf("L.Algebra    :  %.0f      %.0f       %c  \n",midterms[id][3],finals[id][3],status[id][3]);
                printf("Chemistry    :  %.0f      %.0f       %c  \n",midterms[id][4],finals[id][4],status[id][4]);
                printf("====================================\n");
            }
            else if(choice ==3)
            {
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       AVERAGE  GPA   LETTERG\n");
                printf("Math         :  %.0f      %.1f       %c%c  \n",average[id][0],GPA[id][0],lettergrade[id][0],lettergrade2[id][0]);
                printf("C Programming:  %.0f      %.1f       %c%c  \n",average[id][1],GPA[id][1],lettergrade[id][1],lettergrade2[id][1]);
                printf("Physics      :  %.0f      %.1f       %c%c  \n",average[id][2],GPA[id][2],lettergrade[id][2],lettergrade2[id][2]);
                printf("L.Algebra    :  %.0f      %.1f       %c%c  \n",average[id][3],GPA[id][3],lettergrade[id][3],lettergrade2[id][3]);
                printf("Chemistry    :  %.0f      %.1f       %c%c  \n",average[id][4],GPA[id][4],lettergrade[id][4],lettergrade2[id][4]);
                printf("Weighted GPA = %.2f \n",WGPA[id]);
                printf("====================================\n");

            }
            else if(choice ==4)
            {
                printf("========================================\n");
                printf("__General Information About System__\n\n");
                printf("This system contains various information\nof students in a class of 10 people.\n");
                printf("\n___Frequently Asked Questions___\n");
                printf("\nQ1 => How is grade point average taken?\nAnswer: 40 percent of midterm and 60\npercent of final are summed.\n");
                printf("\nQ2 => How do you calculate WGPA?\n");
                printf("Answer:Every lesson has it's own weight.\nHence, we multiply GPA with this\nweights and then divide them with total\nweight which is 30.\n");
                printf("\nQ3=> What does 'X' and 'O' mean in the\nCourse overview?\nAnswer: 'O' means you passed the\ncourse successfully, 'X' means you\nfailed the course unfortunately.\n");
                printf("========================================\n");
            } else
            {
                work=0;
            }
        }
          if (pass==276 && strcmp("Necdet",name)==0 ){
            id=9;
            printf("====================================\n");
            printf("1.Personal information\n");
            printf("2.Course overview\n");
            printf("3.General grade status\n");
            printf("4.General information status\n");
            printf("5.Exit\n");
            printf("\n>>Please, press the number for the\ninformation you want to receive.\n");
            printf("====================================\n");
            scanf("%d",&choice);

            if(choice ==1 ){
                printf("====================================\n");
                printf("Name         : Necdet\n");
                printf("Surname      : Kara\n");
                printf("Number       : %d\n",id+1);
                printf("Nationality  : Turkish\n");
                printf("Date of Birth: 05/12/1999\n");
                printf("====================================\n");
            }
            else if(choice ==2){
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       MIDTERM  FINAL  STATUS\n");
                printf("Math         :  %.0f      %.0f       %c  \n",midterms[id][0],finals[id][0],status[id][0]);
                printf("C Programming:  %.0f      %.0f       %c  \n",midterms[id][1],finals[id][1],status[id][1]);
                printf("Physics      :  %.0f      %.0f       %c  \n",midterms[id][2],finals[id][2],status[id][2]);
                printf("L.Algebra    :  %.0f      %.0f       %c  \n",midterms[id][3],finals[id][3],status[id][3]);
                printf("Chemistry    :  %.0f      %.0f       %c  \n",midterms[id][4],finals[id][4],status[id][4]);
                printf("====================================\n");
            }
            else if(choice ==3){
                printf("====================================\n");
                printf("               GRADES               \n");
                printf("LESSONS       AVERAGE  GPA   LETTERG\n");
                printf("Math         :  %.0f      %.1f       %c%c  \n",average[id][0],GPA[id][0],lettergrade[id][0],lettergrade2[id][0]);
                printf("C Programming:  %.0f      %.1f       %c%c  \n",average[id][1],GPA[id][1],lettergrade[id][1],lettergrade2[id][1]);
                printf("Physics      :  %.0f      %.1f       %c%c  \n",average[id][2],GPA[id][2],lettergrade[id][2],lettergrade2[id][2]);
                printf("L.Algebra    :  %.0f      %.1f       %c%c  \n",average[id][3],GPA[id][3],lettergrade[id][3],lettergrade2[id][3]);
                printf("Chemistry    :  %.0f      %.1f       %c%c  \n",average[id][4],GPA[id][4],lettergrade[id][4],lettergrade2[id][4]);
                printf("Weighted GPA = %.2f \n",WGPA[id]);
                printf("====================================\n");

            }
            else if(choice ==4){
                printf("========================================\n");
                printf("__General Information About System__\n\n");
                printf("This system contains various information\nof students in a class of 10 people.\n");
                printf("\n___Frequently Asked Questions___\n");
                printf("\nQ1 => How is grade point average taken?\nAnswer: 40 percent of midterm and 60\npercent of final are summed.\n");
                printf("\nQ2 => How do you calculate WGPA?\n");
                printf("Answer:Every lesson has it's own weight.\nHence, we multiply GPA with this\nweights and then divide them with total\nweight which is 30.\n");
                printf("\nQ3=> What does 'X' and 'O' mean in the\nCourse overview?\nAnswer: 'O' means you passed the\ncourse successfully, 'X' means you\nfailed the course unfortunately.\n");
                printf("========================================\n");
            }
            else{
                work=0;
            }
        }
    }
};

int main(void)
{
  int pass;
   char name[15];
   printf("\n====================================\n");
   printf("\n___Welcome to School ID System___\n\n");
   printf("______NAMES_________PASSWORDS_______\n\n");
   printf(" =>  Steffi            123\n =>  Ricohard          345\n =>  Anni              678\n =>  Arnold            911\n =>  Pharaildis        132\n =>  Lena              321\n =>  Vera              654\n =>  Alana             987\n =>  Jasmine           623\n =>  Necdet            276\n");
   printf("====================================\n");
   printf("Please select and enter your name.\n");
   scanf("%s",name);
   printf("Please enter your password next to\nyour name.\n");
   scanf("%d",&pass);
  check_password(pass,name);
}
