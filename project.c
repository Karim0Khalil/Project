// #include <stdio.h>
// #include <windows.h>

// int main()
// {
//     int hour = 0, min = 0, sec = 55;
//     int counter_1 = 0;
//     int counter_2 = 0;
//     int bool = 1;
//     int x;
//     while (bool)
//     {
//         printf("Enter a number:");
//         scanf("%d", x);
//         if (x == 1)
//         {
//             while (1 && x==1)
//             {
//                 printf("\r%2d:%2d:%2d", hour, min, sec);
//                 sec++;
//                 counter_1++;
//                 Sleep(1000);
//                 if (sec == 60)
//                 {
//                     min++;
//                     sec = 0;
//                 }
//                 if (min == 59 && sec == 60)
//                 {
//                     hour++;
//                     min = 0;
//                     sec = 0;
//                 }
//                 printf("Enter a number:");
//                 scanf("%d", x);
//             }
//         }
//         else if(x==2){
//             while (1 && x==2)
//             {
//                 printf("\r%2d:%2d:%2d", hour, min, sec);
//                 sec++;
//                 counter_2++;
//                 Sleep(1000);
//                 if (sec == 60)
//                 {
//                     min++;
//                     sec = 0;
//                 }
//                 if (min == 59 && sec == 60)
//                 {
//                     hour++;
//                     min = 0;
//                     sec = 0;
//                 }
//                 printf("Enter a number:");
//                 scanf("%d", x);
//             }
//         }
//     }
//     return 0;
// }

// int main(){

//     int counter_1 = 0;
//     int counter_2 = 0;
//     int bool = 1;
//     int red = 1, yellow = 1;
//     int x;
//     int answer;
//     while(bool){
//         printf("Who's turn is it?");
//         scanf("%d",x);
//         if(x==1){
//             printf("Red's turn:");
//             answer = 0;
//             while(){

//             }
//         }
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <time.h>

// int main(){
//     int counter_1 = 0;
//     int counter_2 = 0;
//     int timer_1;
//     int timer_2;

//     int bool = 1;
//     int answer;
//     time_t currentTime,start,end;
//     while(bool){
//         printf("Enter a number:");
//         start = clock();
//         scanf("%d",answer);
//         end = clock();
//         time_t t = (start - end)/CLOCKS_PER_SEC;
//         printf("%s",ctime(&t));
//         bool = 0;
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <time.h>

// int main()
// {

//     int nothing;
//     printf("How much is nothing?");
//     scanf("%d",&nothing);
//     printf("\nAdd nothing to 1 gives us:%d",nothing +1);
//     int answer, bool = 1, counter_1 = 0, counter_2 = 0;
//     printf("Enter a number:");

//     int ticks = 0,ticks_temp,ticks_1,ticks_2;
//     while (bool<3)
//     {
//         answer = 1;
//         ticks = 0;
//         ticks_temp = 0;
//         if (answer == 1)
//         {
//             while (ticks == 0)
//             {
//                 ticks = clock();
//                 scanf("%d", &answer);
//                 ticks_1 = clock();
//                 counter_1+=(ticks_1 - ticks);
//             }
//             answer=2;
//         }
//         if (answer == 2)
//         {
//             while (bool<3)
//             {
//                 ticks_temp = clock();
//                 scanf("%d", &answer);
//                 ticks_2 = clock();
//                 counter_2+=(ticks_2 - ticks_temp);
//                 bool++;
//             }
//         }
//     }
//     printf("%f\t%f",(float)counter_1/CLOCKS_PER_SEC,(float)counter_2/CLOCKS_PER_SEC);
//     printf("%f\n", (float)ticks / CLOCKS_PER_SEC);
//     return 0;
// }

#include <stdio.h>
#include <time.h>

int main()
{
    int input = 1, function, overall, program, tillnow;
    clock_t start, endwhile, end, startfor, endfor;
    start = clock();
    while (input > 0)
    {
        printf("Please enter a number:");
        scanf("%d", &input);
        function = clock();
        overall += (function - tillnow);
    }
    endwhile = clock();
    int count = 0;
    for (int i = 0; i < 1000000000; i++)
    {
        if(i==1){
            startfor = clock();
            endfor = clock();
        }
        count++;
    }
    printf("%f\n",(double)(endfor-startfor)/CLOCKS_PER_SEC);
    printf("count:%d\n",count);
    end = clock();
    printf("Time for function:%f\n", (double)(endwhile - start) / CLOCKS_PER_SEC);
    printf("Time for whole programm:%f", (double)end / CLOCKS_PER_SEC);
}