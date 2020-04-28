// main.cpp : This file contain exercises from chapter 2, book M.Douson "Learn C++ throo programming of the games"
//

#include<iostream>
#include<string>

int main()
{
    //TASK3 -computer try to guess your number
       
    int usernum = 0;
    int comp_answer = 50;
    int first_half = 50;
    int second_half = 50;
    int temp_min = 0;
    int temp_max = 0;
    int trys = 0;
    int best_gues = 0;
    char answer = 'y';
    char prompt;
    bool status = true;
    bool one_more_time = true;

    
    std::cout << "\n*************************************************************************\n";
    std::wcout << "\t\t\t   ***GAME GUESS THE NUMBER***";
    std::cout << "\n*************************************************************************\n";

    std::wcout << "\nRULES: you enter your number (from 1 to 100), computer tries to guess it." << std::endl;
    
    do
    {
        //check correct value
        while (status)
        {
            std::cout << "\nEnter your number: ";
            std::cin >> usernum;
            std::cin.ignore(5, '\n');         

            if (std::cin.good())
            {
                if (usernum >= 1 && usernum <= 100)
                {
                    status = false;
                }
                else
                {
                    std::cout << "\nYou entered incorrect value(enter numbers from 1 to 100): ";
                }
            }
            else
            {    
                std::cout << "\nYou entered incorrect value(enter only numbers): ";
                std::cin.clear();
                std::cin.ignore(5, '\n');
                usernum = 0;
            }
        }

        std::cout << "\nIs your number: " << comp_answer;
        std::cin >> answer;
        trys++;

        if (answer == 'y')
        {
            std::cout << "\nI am a superman ... I guessed the number at the first attempt!";
        }
        else
        {
            std::cout << "\nIs your number bigger or smaller (+ or -)?: ";
            std::cin >> prompt;
            std::cin.ignore(5, '\n');

            while (true)
            {
                if (prompt == '+')
                {
                    temp_min = comp_answer;
                    comp_answer += (second_half = second_half / 2);

                    std::cout << "\nIs your number: " << comp_answer;
                    std::cin >> answer;
                    trys++;

                    if (answer == 'n')
                    {
                        std::cout << "\nIs your number bigger or smaller (+ or -)?: ";
                        std::cin >> prompt;
                        std::cin.ignore(5, '\n');

                        while (true)
                        {
                            if (prompt == '+')
                            {
                                if (second_half <= 1)
                                    second_half = 2;

                                temp_min = comp_answer;
                                comp_answer += (second_half = second_half / 2);

                                std::cout << "\nIs your number: " << comp_answer;
                                std::cin >> answer;
                                trys++;

                                if (answer == 'n')
                                {
                                    std::cout << "\nIs your number bigger or smaller (+ or -)?: ";
                                    std::cin >> prompt;
                                    std::cin.ignore(5, '\n');

                                    continue;
                                }
                                else
                                {
                                    std::cout << "\nGuessed!";
                                    break;
                                }
                            }
                            else if (prompt == '-')
                            {
                                temp_max = comp_answer;
                                comp_answer = temp_min;

                                if (second_half <= 1)
                                    second_half = 2;

                                comp_answer += (second_half = second_half / 2);

                                std::cout << "\nIs your number: " << comp_answer;
                                std::cin >> answer;
                                trys++;

                                if (answer == 'n')
                                {
                                    std::cout << "\nIs your number bigger or smaller (+ or -)?: ";
                                    std::cin >> prompt;
                                    std::cin.ignore(5, '\n');

                                    continue;
                                }
                                else
                                {
                                    std::cout << "\nGuessed!";
                                    break;
                                }
                            }
                            else
                            {
                                std::cout << "\nWARNING: unknown symbol.";
                                continue;
                            }
                        }
                    }

                    std::cout << "\nI knew that I would guess this number!" << std::endl;
                    break;
                }
                else if (prompt == '-')
                {
                    temp_max = comp_answer;
                    comp_answer -= (second_half = second_half / 2);

                    std::cout << "\nIs your number: " << comp_answer;
                    std::cin >> answer;
                    trys++;

                    if (answer == 'n')
                    {
                        std::cout << "\nIs your number bigger or smaller (+ or -)?: ";
                        std::cin >> prompt;
                        std::cin.ignore(5, '\n');

                        while (true)
                        {
                            if (prompt == '+')
                            {
                                if (second_half <= 1)
                                    second_half = 2;

                                temp_min = comp_answer;
                                comp_answer += (second_half = second_half / 2);

                                std::cout << "\nIs your number: " << comp_answer;
                                std::cin >> answer;
                                trys++;

                                if (answer == 'n')
                                {
                                    std::cout << "\nIs your number bigger or smaller (+ or -)?: ";
                                    std::cin >> prompt;
                                    std::cin.ignore(5, '\n');

                                    continue;
                                }
                                else
                                {
                                    std::cout << "\nGuessed!";
                                    break;
                                }

                            }
                            else if (prompt == '-')
                            {
                                temp_max = comp_answer;
                                temp_min = 1;

                                if (second_half <= 1)
                                    second_half = 2;

                                comp_answer -= (second_half = second_half / 2);

                                std::cout << "\nIs your number: " << comp_answer;
                                std::cin >> answer;
                                trys++;

                                if (answer == 'n')
                                {
                                    std::cout << "\nIs your number bigger or smaller (+ or -)?: ";
                                    std::cin >> prompt;
                                    std::cin.ignore(5, '\n');

                                    continue;
                                }
                                else
                                {
                                    std::cout << "\nGuessed!";
                                    break;
                                }
                            }
                            else
                            {
                                std::cout << "\nWARNING: unknown symbol." << std::endl;
                                continue;
                            }
                        }
                    }
                    std::cout << "\nI knew that I would guess this number!";
                    break;
                }
            }
        }

        best_gues = trys;

        if (best_gues > 0 && best_gues > trys)
            best_gues = trys;

        std::cout << "\n*************************************************************************\n";
        std::wcout << "\t\t\t   ***END OF GAME***";
        std::cout << "\n*************************************************************************\n";
        std::cout << "STATISTIC:\n";
        std::wcout << "\nNumber of attempts: " << trys << ";" << std::endl;
        
        if (best_gues > 0)
            std::cout << "Best attempt:\t    " << best_gues << ";" << std::endl;

        std::cout << std::endl;

        std::cout << "\nDo you want to play the game one more time?: ";
        std::cin >> answer;
        std::cin.ignore(5, '\n');

        if (answer == 'y' || answer == 'Y')
        {
            one_more_time = true;

            usernum = 0;
            comp_answer = 50;
            first_half = 50;
            second_half = 50;
            temp_min = 0;
            temp_max = 0;
            trys = 0;
            status = true;
        }
        else
            one_more_time = false;

    }while (one_more_time);

    std::cout << "\n*************************************************************************\n";
    std::wcout << "\t\t\t   ***SEE YOU LATER***";
    std::cout << "\n*************************************************************************\n";

    
    
    return 0;
}

