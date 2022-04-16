#include "Card_calatorie.h"
#include<iostream>

int main()
{
    Card_calatorie** card_calatorie;
    int n;
    int n_metrou = 0;
    int n_autobuz = 0;
    int x;
    int moment;
    int id;
    int id2;
    char tip;
    int valoare;

    std::cin >> n;
    card_calatorie = new Card_calatorie * [n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> tip;

        if (tip == 'a')
        {
            std::cin >> id;
            std::cin >> valoare;
            (*(card_calatorie + i)) = new Card_autobuz(id, tip, valoare, 0);
            n_autobuz++;
        }

        if (tip == 'm')
        {
            std::cin >> id;
            std::cin >> valoare;
            (*(card_calatorie + i)) = new Card_metrou(id, tip, valoare, 0);
            n_metrou++;
        }
    }

    while (1)
    {
        std::cin >> x;

        switch (x)
        {
        case 1:
            for (int i = 0; i < n; i++)
                (*(card_calatorie + i))->afisare();
            break;

        case 2:
            std::cin >> id;
            std::cin >> valoare;

            for (int i = 0; i < n; i++)
                if ((*(card_calatorie + i))->get_id() == id)
                {
                    if ((*(card_calatorie + i))->get_tip() == 'a')
                        (*(card_calatorie + i))->set_sold(valoare + (*(card_calatorie + i))->get_sold());
                    else
                        (*(card_calatorie + i))->set_nr_calatorii(valoare + (*(card_calatorie + i))->get_nr_calatorii());
                }

            break;

        case 3:
            std::cin >> id >> moment;
            for (int i = 0; i < n; i++)
            {
                if ((*(card_calatorie + i))->get_id() == id)
                {
                    (*(card_calatorie + i))->validare_calatorie(moment);
                }
            }
            break;

        case 4:
            std::cin >> id >> id2 >> valoare;

            for (int i = 0; i < n; i++)
            {
                if ((*(card_calatorie + i))->get_id() == id)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if ((*(card_calatorie + j))->get_id() == id2)
                        {
                            if ((*(card_calatorie + j))->get_tip() == (*(card_calatorie + i))->get_tip())
                            {
                                if ((*(card_calatorie + j))->get_tip() == 'a')
                                {
                                    if ((*(card_calatorie + i))->get_sold() >= valoare)
                                    {
                                        (*(card_calatorie + j))->set_sold((*(card_calatorie + j))->get_sold() + valoare);
                                        (*(card_calatorie + i))->set_sold((*(card_calatorie + i))->get_sold() - valoare);

                                    }
                                    else
                                        std::cout << "Transfer nereusit\n";
                                }
                                else
                                {
                                    if ((*(card_calatorie + i))->get_nr_calatorii() >= valoare)
                                    {
                                        (*(card_calatorie + j))->set_nr_calatorii((*(card_calatorie + j))->get_nr_calatorii() + valoare);
                                        (*(card_calatorie + i))->set_nr_calatorii((*(card_calatorie + i))->get_nr_calatorii() - valoare);
                                    }
                                    else
                                        std::cout << "Transfer nereusit\n";
                                }
                            }
                            else
                                std::cout << "Transfer nereusit\n";
                        }
                    }
                }

            }

            break;
        case 5:

            exit(1);

        }

    }

    return 0;
}





