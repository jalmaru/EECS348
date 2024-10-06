#include <stdio.h>
#include <stdlib.h>

// ] constants for temp categories
#define FREEZING_TEMP 0.0
#define COLD_TEMP 10.0
#define COMFORTABLE_TEMP 25.0
#define HOT_TEMP 35.0

//Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (9.0/5.0) * celsius + 32;
}
//Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0/9.0) * (fahrenheit - 32);
}
//Celsius to Kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}
//Kelvin to Celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

//Fahrenheit to Kelvin
float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}
//Kelvin to Fahrenheit
float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

//weather advisory based on celsius temp
void categorize_temperature(float celsius) {
    if (celsius < FREEZING_TEMP) {
        printf("Freezing: Wear warm clothes!\n");
    } else if (celsius < COLD_TEMP) {
        printf("Cold: Wear a jacket!\n");
    } else if (celsius < COMFORTABLE_TEMP) {
        printf("Comfortable: Enjoy the weather!\n");
    } else if (celsius < HOT_TEMP) {
        printf("Hot: Stay hydrated!\n");
    } else {
        printf("Extreme Heat: Stay indoors!\n");
    }
}

int main() {
    float temperature;
    char scale_from, scale_to;
    int valid_input = 0;

    while (!valid_input) {
        printf("Enter the temperature value: ");
        if (scanf("%f", &temperature) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
        }

        printf("Choose the temperature scale of the input value (F, C, or K): ");
        if (scanf(" %c", &scale_from) != 1) {
            printf("Invalid input. Please enter F, C, or K.\n");
        }

        printf("Choose the conversion target (F, C, or K): ");
        if (scanf(" %c", &scale_to) != 1) {
            printf("Invalid input. Please enter F, C, or K.\n");
        }

        if (scale_from == scale_to) {
            printf("Invalid conversion choice. Please choose a different target scale.\n");
            continue;
        }

        valid_input = 1;
    }

    float converted_temperature;

    switch (scale_from) {
        case 'F':
            switch (scale_to) {
                case 'C':
                    converted_temperature = fahrenheit_to_celsius(temperature);
                    break;
                case 'K':
                    converted_temperature = fahrenheit_to_kelvin(temperature);
                    break;
            }
            break;
        case 'C':
            switch (scale_to) {
                case 'F':
                    converted_temperature = celsius_to_fahrenheit(temperature);
                    break;
                case 'K':
                    converted_temperature = celsius_to_kelvin(temperature);
                    break;
            }
            break;
        case 'K':
            switch (scale_to) {
                case 'F':
                    converted_temperature = kelvin_to_fahrenheit(temperature);
                    break;
                case 'C':
                    converted_temperature = kelvin_to_celsius(temperature);
                    break;
            }
            break;
    }

    printf("Converted temperature: %.2f %c\n", converted_temperature, scale_to);

    if (scale_to == 'K' && temperature < 0) {
        printf("Error: Invalid Kelvin value. Temperature cannot be negative.\n");
    } else {
        categorize_temperature(converted_temperature);
    }

    return 0;
}