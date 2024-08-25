//This Header file Handles the user input errors

// function to validate the size of arrray given by user
int input_validation_size()
{
    int num;
    // logic behind input validation
    while (1)
    {
        int r = (scanf("%d", &num)); // return 1 or true if user enter integer
        if (r == 1 && num > 0 && num < 10)
            break;
        else
        {
            printf("Enter the valid number ");
            while (getchar() != '\n')
                ; // code to delete buffer
        }
    }
    return num;
}

int integer_validation()
{
    int num;
    while (1)
    {
        int r = (scanf("%d", &num));
        if (r == 1)
            break;
        else
        {
            printf("Enter valid number ");
            while (getchar() != '\n')
                ;
        }
    }
    return num;
}

int position_validation(int length)
{
    int num;
    while (1)
    {
        int r = (scanf("%d", &num));
        if (r == 1 && num >= 0 && num <= length)
            break;
        else
        {
            printf("Enter valid number");
            while (getchar() != '\n')
                ;
        }
    }
    return num;
}

int input_validation_choice()
{
    int num;
    // logic behind input validation
    while (1)
    {
        int r = (scanf("%d", &num)); // return 1 or true if user enter integer
        if (r == 1 && num > 0 && num < 5)
            break;
        else
        {
            printf("Enter the valid choice ");
            while (getchar() != '\n')
                ; // code to delete buffer
        }
    }
    return num;
}