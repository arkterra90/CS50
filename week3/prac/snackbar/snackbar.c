// Practice using structs
// Practice writing a linear search function



#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Number of menu items
// Adjust this value (10) to number of items input below
#define NUM_ITEMS 11

// Menu itmes have item name and price
typedef struct
{
    string item;
    float price;
}
menu_item;

// Array of menu items
menu_item menu[NUM_ITEMS];

// Add items to menu
void add_items(void);


// Calculate total cost
float get_cost(string item);

int main(void)
{
    add_items();

    printf("\nWelcome to Beach Burger Shack!\n");
    printf("Choose from the following menu to order. Press enter when done.\n\n");

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("%s: $%.2f\n", menu[i].item, menu[i]. price);
    }
    printf("\n");

    float total = 0;
    while (true)
    {
        string item = get_string("Enter a food item: ");
        if (strlen(item) == 0)
        {
            printf("\n");
            break;
        }

        total += get_cost(item);
    }

    printf("Your total cost is: $%.2f\n", total);
}

// Add at least the first for items to the menu array
void add_items(void)
{

    menu[0].item = "Burger";
    menu[0].price = 9.5;

    menu[1].item = "Vegan Burger";
    menu[1].price = 11;

    menu[2].item = "Hot Dog";
    menu[2].price = 5;

    menu[3].item = "Cheese Dog";
    menu[3].price = 7;

    menu[4].item = "Fries";
    menu[4].price = 5;

    menu[5].item = "Cheese Fries";
    menu[5].price = 6;

    menu[6].item = "Burger";
    menu[6].price = 9.5;

    menu[7].item = "Cold Pressed Juice";
    menu[7].price = 7;

    menu[8].item = "Cold Brew";
    menu[8].price = 3;

    menu[9].item = "Water";
    menu[9].price = 2;

    menu[10].item = "Soda";
    menu[10].price = 2;

    return;
}

// Search through the menu array to find an item's cost
// strcmp to find item in array and then add to the cost var
// return total added to cost var through linear search of struct
float get_cost(string item)
{
    int cost;
    for (int i = 0; i < NUM_ITEMS; i++)
    {
         if (strcmp(menu[i].item, item) == 0)
            {
                cost = cost + menu[i].price;
            }
    }
    printf("%i cost func\n", cost);
    return cost;
}
