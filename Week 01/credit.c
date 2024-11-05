#include <stdio.h>
#include <cs50.h>
#include <string.h>

// LUHR's Algorithm Implementation - Kaung Myat Kyaw
int main(void)
{
    long long int card_number = 0;
    int sum = 0;
    char card_number_str[50];
    int is_second_digit = 0;

    do{
        card_number = get_long_long("Visa: ");
    } while(card_number < 0);

    sprintf(card_number_str, "%lld", card_number);
    int length = strlen(card_number_str);

    while (card_number > 0){
        int digit = card_number % 10;
        card_number /= 10;

        if (is_second_digit)
        {
            digit *= 2;
            if (digit > 9)
            {
                sum += digit/10 + digit%10;
            }
            else
            {
                sum += digit;
            }
        }
        else {
            sum += digit;
        }

        is_second_digit = !is_second_digit;

    }


    if (sum % 10 == 0 && length >= 13)
    {
        if ((card_number_str[0] == '3') && (card_number_str[1] == '4' || card_number_str[1] == '7') && length == 15)
        {
            printf("AMEX\n");
        }
        else if (card_number_str[0] == '4' && length != 15)
        {
            printf("VISA\n");
        }
        else if ((card_number_str[0] == '5' && card_number_str[1] >= '1' && card_number_str[1] <= '5') ||
        (card_number_str[0] == '2' && card_number_str[1] == '2' && card_number_str[2] >= '1' && card_number_str[2] <= '7'))
        {
            printf("MASTERCARD\n");
        }
        else {
            printf("INVALID\n");
        }

    } else {
        printf("INVALID\n");
    }
}

