#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    // Checking for the correct number of args:
    if (argc != 4)
    {
        printf("Usage: ./fitness EXERCISE_TYPE BODY_AREA WORKOUT_LENGTH\n");
        printf("Possible Types: [Calisthenics, Cardio, Weights, Stretching]\n");
        printf("Possible Areas: [Upper, Lower, Core]\n");
        printf("Possible Lengths: [Short, Medium, Long]\n");
        return 1;
    }

    // Vetting Command Line Input: (In this order: Type, Area, Length)
    if (strcmp(argv[1], "Calisthenics") != 0 && strcmp(argv[1], "Cardio") != 0 && strcmp(argv[1], "Weights") != 0 && strcmp(argv[1], "Stretching") != 0)
    {
        printf("Not a Valid Type of Workout\n");
        return 1;
    }

    if (strcmp(argv[2], "Upper") != 0 && strcmp(argv[2], "Lower") != 0 && strcmp(argv[2], "Core") != 0)
    {
        printf("Not a Valid Area\n");
        return 1;
    }

    if (strcmp(argv[3], "Short") != 0 && strcmp(argv[3], "Medium") != 0 && strcmp(argv[3], "Long") != 0)
    {
        printf("Not a Valid Workout Length\n");
        return 1;
    }

    // Variablizing Command Line Input:
    char * type = argv[1];
    char * area = argv[2];
    char * length = argv[3];

    // Creating Variables for Future Use:

    // Exercises:
    char * e1 = NULL;
    char * e2 = NULL;
    char * e3 = NULL;
    char * e4 = NULL;

    // Sets:
    int s1;
    int s2;
    int s3;
    int s4;

    // Reps:
    int r1;
    int r2;
    int r3;
    int r4;

    // Seconds:
    int seconds1;
    int seconds2;
    int seconds3;
    int seconds4;

    // Cardio:
    int cardio1;
    int cardio2;
    int cardio3;
    int cardio4;

    // Core Cardio:
    int sprinting;
    int high_knees;

    // Running and Walking template variables:
    int running1;
    int walking1;

    // Booleans for template use:
    bool template = false;
    bool templatec = false;
    bool running = false;
    bool corecardio = false;
    bool stretching = false;
    bool weights = false;

    if (strcmp(type, "Calisthenics") == 0) // Format goes as follows: if (type) --> if (area) --> if (length): ------------------ This is Calisthenics
    {

        template = true;

        if (strcmp(area, "Upper") == 0)
        {
            e1 = "Pull-Ups";
            e2 = "Chin-Ups";
            e3 = "Tricep Dips (Bar)";
            e4 = "Push-Ups";

            if (strcmp(length, "Short") == 0)
            {
                s1 = 3;
                s2 = 3;
                s3 = 3;
                s4 = 3;

                r1 = 3;
                r2 = 3;
                r3 = 3;
                r4 = 15;
            }
            else if (strcmp(length, "Medium") == 0)
            {
                s1 = 3;
                s2 = 3;
                s3 = 3;
                s4 = 3;

                r1 = 5;
                r2 = 5;
                r3 = 5;
                r4 = 20;
            }
            else if (strcmp(length, "Long") == 0)
            {
                s1 = 5;
                s2 = 5;
                s3 = 5;
                s4 = 5;

                r1 = 8;
                r2 = 8;
                r3 = 8;
                r4 = 20;
            }
        }
        else if (strcmp(area, "Lower") == 0)
        {
            e1 = "Hanging Leg Raises";
            e2 = "Calf Raises";
            e3 = "Lunges (Bodyweight)";
            e4 = "Squats (Bodyweight)";

            if (strcmp(length, "Short") == 0)
            {
                s1 = 3;
                s2 = 3;
                s3 = 3;
                s4 = 3;

                r1 = 8;
                r2 = 20;
                r3 = 10;
                r4 = 10;
            }
            else if (strcmp(length, "Medium") == 0)
            {
                s1 = 4;
                s2 = 4;
                s3 = 4;
                s4 = 4;

                r1 = 10;
                r2 = 25;
                r3 = 15;
                r4 = 15;
            }
            else if (strcmp(length, "Long") == 0)
            {
                s1 = 5;
                s2 = 5;
                s3 = 5;
                s4 = 5;

                r1 = 15;
                r2 = 30;
                r3 = 20;
                r4 = 20;
            }
        }
        else if (strcmp(area, "Core") == 0)
        {
            e1 = "Crunches";
            e2 = "Lying Scissor Kicks";
            e3 = "Sit-Ups";
            e4 = "Push-Ups";

            if (strcmp(length, "Short") == 0)
            {
                s1 = 3;
                s2 = 3;
                s3 = 3;
                s4 = 3;

                r1 = 10;
                r2 = 12;
                r3 = 10;
                r4 = 12;
            }
            else if (strcmp(length, "Medium") == 0)
            {
                s1 = 4;
                s2 = 4;
                s3 = 4;
                s4 = 4;

                r1 = 15;
                r2 = 15;
                r3 = 15;
                r4 = 15;
            }
            else if (strcmp(length, "Long") == 0)
            {
                s1 = 5;
                s2 = 5;
                s3 = 5;
                s4 = 5;

                r1 = 20;
                r2 = 20;
                r3 = 20;
                r4 = 20;
            }
        }
    }
    else if (strcmp(type, "Cardio") == 0) // ------------------------------------------- This is Cardio
    {

        templatec = true;

        if (strcmp(area, "Upper") == 0)
        {
            templatec = true;

            e1 = "Jumping Jacks";
            e2 = "Medicine Ball Pushup Position (Hold)";
            e3 = "Plank (Hold)";
            e4 = "Boxing Bouts";

            if (strcmp(length, "Short") == 0)
            {
                s1 = 3;
                s2 = 3;
                s3 = 3;
                s4 = 3;

                cardio1 = 1;
                cardio2 = 1;
                cardio3 = 1;
                cardio4 = 1;
            }
            else if (strcmp(length, "Medium") == 0)
            {
                s1 = 3;
                s2 = 3;
                s3 = 3;
                s4 = 3;

                cardio1 = 2;
                cardio2 = 2;
                cardio3 = 2;
                cardio4 = 2;
            }
            else if (strcmp(length, "Long") == 0)
            {
                s1 = 3;
                s2 = 3;
                s3 = 3;
                s4 = 3;

                cardio1 = 3;
                cardio2 = 3;
                cardio3 = 3;
                cardio4 = 3;
            }
        }
        else if (strcmp(area, "Lower") == 0)
        {
            templatec = false;
            running = true;

            e1 = "Running";
            e2 = "Walking";

            if (strcmp(length, "Short") == 0)
            {
                running1 = 10;
                walking1 = 10;
            }
            else if (strcmp(length, "Medium") == 0)
            {
                running1 = 20;
                walking1 = 10;
            }
            else if (strcmp(length, "Long") == 0)
            {
                running1 = 30;
                walking1 = 10;
            }
        }
        else if (strcmp(area, "Core") == 0)
        {
            templatec = false;
            corecardio = true;

            e1 = "Sprinting";
            e2 = "High Knees";
            e3 = "Tuck Jumps";
            e4 = "Mountain Climbers";

            if (strcmp(length, "Short") == 0)
            {
                s1 = 3;
                s2 = 3;
                s3 = 3;
                s4 = 3;

                sprinting = 30;
                high_knees = 1;
                r3 = 10;
                r4 = 20;
            }
            else if (strcmp(length, "Medium") == 0)
            {
                s1 = 3;
                s2 = 3;
                s3 = 3;
                s4 = 3;

                sprinting = 40;
                high_knees = 2;
                r3 = 20;
                r4 = 25;
            }
            else if (strcmp(length, "Long") == 0)
            {
                s1 = 3;
                s2 = 3;
                s3 = 3;
                s4 = 3;

                sprinting = 50;
                high_knees = 3;
                r3 = 25;
                r4 = 30;
            }
        }
    }
    else if (strcmp(type, "Weights") == 0) // -------------------------------------------- This is Weights
    {

        template = true;
        weights = true;

        if (strcmp(area, "Upper") == 0)
        {
            e1 = "Tricep Row on Bench";
            e2 = "Skull Crushers";
            e3 = "Bench Press";
            e4 = "Dumbell Curl with Twist";

            if (strcmp(length, "Short") == 0)
            {
                s1 = 3;
                s2 = 3;
                s3 = 3;
                s4 = 3;

                r1 = 5;
                r2 = 5;
                r3 = 5;
                r4 = 10;
            }
            else if (strcmp(length, "Medium") == 0)
            {
                s1 = 4;
                s2 = 4;
                s3 = 4;
                s4 = 4;

                r1 = 8;
                r2 = 8;
                r3 = 8;
                r4 = 12;
            }
            else if (strcmp(length, "Long") == 0)
            {
                s1 = 5;
                s2 = 5;
                s3 = 5;
                s4 = 5;

                r1 = 10;
                r2 = 10;
                r3 = 10;
                r4 = 14;
            }
        }
        else if (strcmp(area, "Lower") == 0)
        {
            e1 = "Barbell Squat";
            e2 = "Deadlift";
            e3 = "Barbell Thrust";
            e4 = "Dumbell Lunge";

            if (strcmp(length, "Short") == 0)
            {
                s1 = 3;
                s2 = 3;
                s3 = 3;
                s4 = 3;

                r1 = 5;
                r2 = 3;
                r3 = 4;
                r4 = 10;
            }
            else if (strcmp(length, "Medium") == 0)
            {
                s1 = 4;
                s2 = 4;
                s3 = 4;
                s4 = 4;

                r1 = 5;
                r2 = 4;
                r3 = 6;
                r4 = 14;
            }
            else if (strcmp(length, "Long") == 0)
            {
                s1 = 5;
                s2 = 5;
                s3 = 5;
                s4 = 5;

                r1 = 5;
                r2 = 5;
                r3 = 10;
                r4 = 20;
            }
        }
        else if (strcmp(area, "Core") == 0)
        {
            e1 = "Seated Russian Twist (with Dumbell)";
            e2 = "Renegade Rows (with Dumbell)";
            e3 = "Kettle Bell Halo";
            e4 = "Lying Leg Drops (with Dumbell)";

            if (strcmp(length, "Short") == 0)
            {
                s1 = 3;
                s2 = 3;
                s3 = 3;
                s4 = 3;

                r1 = 6;
                r2 = 6;
                r3 = 6;
                r4 = 6;
            }
            else if (strcmp(length, "Medium") == 0)
            {
                s1 = 4;
                s2 = 4;
                s3 = 4;
                s4 = 4;

                r1 = 8;
                r2 = 8;
                r3 = 8;
                r4 = 8;
            }
            else if (strcmp(length, "Long") == 0)
            {
                s1 = 5;
                s2 = 5;
                s3 = 5;
                s4 = 5;

                r1 = 12;
                r2 = 12;
                r3 = 12;
                r4 = 14;
            }
        }
    }
    else if (strcmp(type, "Stretching") == 0) // ------------------------------------------------------ This is Stretching ----------------------------------------------
    {

        stretching = true;

        if (strcmp(area, "Upper") == 0)
        {
            e1 = "Overhead Tricep and Shoulder Stretch";
            e2 = "Cross Body Shoulder Stretch";
            e3 = "Arms Behind the Back Chest Stretch";
            e4 = "Wrist Extension Stretch";

            if (strcmp(length, "Short") == 0)
            {
                s1 = 3;
                s2 = 3;
                s3 = 3;
                s4 = 3;

                seconds1 = 25;
                seconds2 = 25;
                seconds3 = 25;
                seconds4 = 15;
            }
            else if (strcmp(length, "Medium") == 0)
            {
                s1 = 4;
                s2 = 4;
                s3 = 4;
                s4 = 4;

                seconds1 = 35;
                seconds2 = 35;
                seconds3 = 35;
                seconds4 = 20;
            }
            else if (strcmp(length, "Long") == 0)
            {
                s1 = 5;
                s2 = 5;
                s3 = 5;
                s4 = 5;

                seconds1 = 40;
                seconds2 = 40;
                seconds3 = 40;
                seconds4 = 25;
            }
        }
        else if (strcmp(area, "Lower") == 0)
        {
            e1 = "Cross-over Hamstring Stretch";
            e2 = "Standing Quad Stretch";
            e3 = "Downward Facing Dog";
            e4 = "Standing Straddle Stretch";

            if (strcmp(length, "Short") == 0)
            {
                s1 = 3;
                s2 = 3;
                s3 = 3;
                s4 = 3;

                seconds1 = 15;
                seconds2 = 10;
                seconds3 = 20;
                seconds4 = 15;
            }
            else if (strcmp(length, "Medium") == 0)
            {
                s1 = 4;
                s2 = 4;
                s3 = 4;
                s4 = 4;

                seconds1 = 20;
                seconds2 = 15;
                seconds3 = 25;
                seconds4 = 10;
            }
            else if (strcmp(length, "Long") == 0)
            {
                s1 = 5;
                s2 = 5;
                s3 = 5;
                s4 = 5;

                seconds1 = 25;
                seconds2 = 20;
                seconds3 = 30;
                seconds4 = 15;
            }
        }
        else if (strcmp(area, "Core") == 0)
        {
            e1 = "Cat Cow Stretch";
            e2 = "Cobra Pose";
            e3 = "Leg Cross-over Stretch";
            e4 = "Spinal Rotation (on Chair)";

            if (strcmp(length, "Short") == 0)
            {
                s1 = 3;
                s2 = 3;
                s3 = 3;
                s4 = 3;

                seconds1 = 10;
                seconds2 = 12;
                seconds3 = 10;
                seconds4 = 10;
            }
            else if (strcmp(length, "Medium") == 0)
            {
                s1 = 4;
                s2 = 4;
                s3 = 4;
                s4 = 4;

                seconds1 = 12;
                seconds2 = 15;
                seconds3 = 15;
                seconds4 = 15;
            }
            else if (strcmp(length, "Long") == 0)
            {
                s1 = 5;
                s2 = 5;
                s3 = 5;
                s4 = 5;

                seconds1 = 15;
                seconds2 = 20;
                seconds3 = 20;
                seconds4 = 20;
            }
        }
    }

    // Below are the templates for each possible scenario: ------------------------------------- This is the dividing line between the sections-------------------------------

    if (strcmp(area, "Core") == 0)
    {
        area = "Core";
    }
    else if (strcmp(area, "Upper") == 0)
    {
        area = "Upper Body";
    }
    else if (strcmp(area, "Lower") == 0)
    {
        area = "Lower Body";
    }

        // Covering the disclaimer for weight safety:
        if (weights == true)
        {
            printf("\n");
            printf("When working out with weights, always remember to practice good form and to NOT overwork yourself!\n");
            printf("\n");
        }


    if (template == true)
    {
        printf("%s %s Workout: (Length: %s): \n", area, type, length);
        printf("\n");
        printf("If unsure about technique and form, consult a reliable source BEFORE attempting the workout!\n");
        printf("\n");
        printf("And make sure to properly warm-up, so as to prevent unwanted injuries!\n");
        printf("\n");
        printf("%s -- %i sets of %i reps\n", e1, s1, r1);
        printf("%s -- %i sets of %i reps\n", e2, s2, r2);
        printf("%s -- %i sets of %i reps\n", e3, s3, r3);
        printf("%s -- %i sets of %i reps\n", e4, s4, r4);
        printf("\n");
        printf("Record your times if desired, so that you can improve them in the future!\n");
        return 0;
    }



    if (templatec == true)
    {
        printf("%s %s Workout: (Length: %s): \n", area, type, length);
        printf("\n");
        printf("If unsure about technique and form, consult a reliable source BEFORE attempting the workout!\n");
        printf("\n");
        printf("And make sure to properly warm-up, so as to prevent unwanted injuries!\n");
        printf("\n");
        printf("%s -- %i sets of %i minute(s)\n", e1, s1, cardio1);
        printf("%s -- %i sets of %i minute(s)\n", e2, s2, cardio2);
        printf("%s -- %i sets of %i minute(s)\n", e3, s3, cardio3);
        printf("%s -- %i sets of %i minute(s)\n", e4, s4, cardio4);
        printf("\n");
        printf("Record your times if desired, so that you can improve them in the future!\n");
        return 0;
    }

    if (running == true)
    {
        printf("%s %s Workout: (Length: %s): \n", area, type, length);
        printf("\n");
        printf("If unsure about technique and form, consult a reliable source BEFORE attempting the workout!\n");
        printf("\n");
        printf("And make sure to properly warm-up, so as to prevent unwanted injuries!\n");
        printf("\n");
        printf("%s -- %i minutes\n", e1, running1);
        printf("%s -- %i minutes\n", e2, walking1);
        printf("\n");
        printf("If you couldn't attain these times, that's okay! You can always improve upon them in the future!\n");
        return 0;
    }

    if (corecardio == true)
    {
        printf("%s %s Workout: (Length: %s): \n", area, type, length);
        printf("\n");
        printf("If unsure about technique and form, consult a reliable source BEFORE attempting the workout!\n");
        printf("\n");
        printf("And make sure to properly warm-up, so as to prevent unwanted injuries!\n");
        printf("\n");
        printf("%s -- %i sets of %i seconds\n", e1, s1, sprinting);
        printf("%s -- %i sets of %i minute(s)\n", e2, s2, high_knees);
        printf("%s -- %i sets of %i reps\n", e3, s3, r3);
        printf("%s -- %i sets of %i reps\n", e4, s4, r4);
        printf("\n");
        printf("Record your times if desired, so that you can improve them in the future!\n");
        return 0;
    }

    if (stretching == true)
    {
        printf("You Chose Stretching!\n");
        printf("\n");
        printf("Area: %s ------ Length: %s\n", area, length);
        printf("\n");
        printf("If you are unsure about the form or technique of any stretch, make use of any resource you can to help prevent injury!\n");
        printf("\n");
        printf("%s ------ %i sets of %i seconds \n", e1, s1, seconds1);
        printf("%s ------ %i sets of %i seconds \n", e2, s2, seconds2);
        printf("%s ------ %i sets of %i seconds \n", e3, s3, seconds3);
        printf("%s ------ %i sets of %i seconds \n", e4, s4, seconds4);
        printf("\n");
        return 0;
    }

}