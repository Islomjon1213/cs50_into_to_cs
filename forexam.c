#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int count = 0;

bool check_loops(char* words);
int main()
{
    char words[1000];
    printf("Enter any string value: ");
    fgets(words, 1000, stdin);
    if (check_loops(words) == true)
    {
        printf("Found\n");
    }
    else 
    {
        printf("Not Found\n");
    }

    printf("\n%i\n", count);
}


bool check_loops(char* words)
{
    int len = strlen(words);
    
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            count = count+1;
            if (tolower(words[i]) == tolower(words[j]))
            {
                return true;
            }
        }
    }
    return false;
}





// #include <cs50.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <ctype.h>


// bool validate_key(string key);



// int main(int argc, string argv[])
// {
//     if (argc == 2)
//     {
//         if (validate_key(argv[1]))
//         {
//             string texts = get_string("plaintext: ");
//             int p[26] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
//             int cipher[26];

//         }
//             return 0;
//     }



//     printf("Usage: ./substitution key\n");
//     return 1;
// }


// bool validate_key(string key)
// {
//     int len = strlen(key);
//     if (len == 26)
//     {
//         for (int i = 0; i < len; i++)
//         {
//             if (isdigit(key[i]))
//             {
//                 return false;
//             }
//         }
//         for (int i = 0; i < len - 1; i++)
//         {
//             for (int j = i + 1; j < len; j++)
//             {
//                 if (tolower(key[i]) == tolower(key[j]))
//                 {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }


// int length = strlen(gaps);
        // for (int i = 0; i < length; i++)
        // {
        //     //char words = toupper(gaps[i]);
        //     int index = toupper(gaps[i]) - 65;
        //     printf("%c", gaps[i]);
        // }