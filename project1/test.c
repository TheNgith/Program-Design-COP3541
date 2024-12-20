//Name: Thinh Nguyen - UID: 38848480
//Description: Program that calculates total service charge base on number of hours and days

#include <stdio.h>

int main() {
    int equip, input_day, input_hours, hr_block_rate, day_rate, week_rate;
    int total_price = 0;

    //Request and validate inputs
    printf("Please select from four equipment: 1, 2, 3, and 4");
    
    printf("\nEnter equipment selection: ");
    scanf("%d", &equip);
    if (equip < 1 || equip > 4) {
        printf("Invalid selection. Select from 1 to 4.");
        return 0;
    };

    printf("Enter days: ");
    scanf("%d", &input_day);

    printf("Enter hours: ");
    scanf("%d", &input_hours);
    if (input_hours < 0 || input_hours >= 24) {
        printf("Invalid hours.");
        return 0;
    };

    //Define the rate of service base on selected equipment
    if (equip == 1) {
        hr_block_rate = 7;
        day_rate = 10;
        week_rate = 40;
    };

    if (equip == 2) {
        hr_block_rate = 27;
        day_rate = 39;
        week_rate = 156;
    };

    if (equip == 3) {
        hr_block_rate = 61;
        day_rate = 87;
        week_rate = 348;
    };

    if (equip == 4) {
        hr_block_rate = 59;
        day_rate = 84;
        week_rate = 336;
    };

    //Convert hours to blocks of 4 hours
    int hour_blocks = input_hours / 4;
    int hour_exceed = input_hours % 4;
    if (hour_exceed > 0) {
        hour_blocks = hour_blocks + 1; //if less than 4 hours, take them as a block of 4 hours
    };

    //Convert hours to day if the price exceed the cap
    int day = input_day;
    if (hour_blocks * hr_block_rate > day_rate) {
        day = day + 1;
        hour_blocks = 0;
    };

    //Calculate number of weeks
    int week = day / 7;
    day = day % 7;

    //Convert days to week if the price exceed the cap
    if (day * day_rate > week_rate) {
        week = week + 1;
        hour_blocks = 0;
        day = 0;
    };
    
    //Compute total price
    total_price = hour_blocks*hr_block_rate + day*day_rate + week*week_rate;
    printf("Charge($): %d", total_price);
    return 0;
}
