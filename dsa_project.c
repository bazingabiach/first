#include<stdio.h>
#include<string.h>

//Declaring structure of voters...
struct voter
{
    int age;
    int vote;
    char name[20];
};

struct voter user[50];

int main()
{
    int x;
    printf("You can vote for :\n\n");
    printf("Welcome to the Electronic Voting Machine. This is BOOTH 1!!\n");
    printf("Enter the number of voters: ");
    scanf("%d",&x);
    printf("At present we have %d people present and hope for more!!\n\n",x);
    printf("Let's begin with the voting!\n\n");
    
    
    int people_present = x,i=0;
    char answer,ans;
    while(people_present)
    {
        //Adding new people...
        if(people_present==1)
        {
            printf("Are there any new people?\ny or n\n");
            scanf("%c", &answer);
            scanf("%c", &answer);
            if(answer=='y')
            {
                printf("Enter number of people to add - \n");
                int add_people;
                scanf("%d", &add_people);
                if((i+add_people)>50)
                {
                    printf("There are only %d more votes left. Would you like to add them?\n", (50-i));
                    scanf("%c", &ans);
                    scanf("%c", &ans);
                    if(ans=='y') people_present+=(50-i);
                }
                else people_present+=add_people;
            }
        }
        //Voter input...
            printf("Enter details of Voter #%d\n", (i+1));
            printf("Enter your name - \n");
            scanf("%s", user[i].name);
            printf("Enter your age - \n");
            scanf("%d", &user[i].age);
            int age=user[i].age;
            if(age<18)
            {
                printf("You are underage. Your vote is not eligible.\n\n\n");
                user[i].vote==0;
            }
            else
            {
                printf("1. BJP\n2. Congress\n3. AAP\n4. KJP\n");
                printf("Enter number to vote - \n");
                scanf("%d", &user[i].vote);
                while(user[i].vote>=5)
                {                    
                    printf("Enter a valid number !: ");
                    scanf("%d",&user[i].vote);   
                }
                printf("\n\n");
            }
            i++;
            people_present--;
    }
    //Vote allocation...
    int bjp=0;
    int aap=0;
    int cong=0;
    int kjp=0;
    for(int j=0;j<i;j++)
    {
        if(user[j].vote == 1)
        {
            bjp++;
        }
        else if(user[j].vote == 2)
        {
            cong++;
        }
        else if(user[j].vote == 3)
        {
            aap++;
        }
        else if(user[j].vote == 4)
        {
            kjp++;
        }
    }
    //Result of election... 
    if(bjp > cong && bjp> aap && bjp> kjp)
    {
        printf("Congratulations !! The winning party is BJP with %d votes",bjp);
    }
    else if(cong> bjp && cong> aap && cong> kjp)
    {
        printf("Congratulations !! The winning party is Congress with %d votes",cong);
    }
    else if(aap> cong && aap> bjp && aap> kjp)
    {
        printf("Congratulations !! The winning party is AAP with %d votes",aap);
    }
    else if(kjp> cong && kjp> aap && kjp> bjp)
    {
        printf("Congratulations !! The winning party is KJP with %d votes",kjp);
    }
    else{
        printf("It's a draw !!");
    }
}