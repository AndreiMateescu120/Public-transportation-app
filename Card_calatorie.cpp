#include "Card_calatorie.h"
#include<iostream>

//functii Card_calatorie

int Card_calatorie::get_id() { return this->id; }

char Card_calatorie::get_tip() { return this->tip; }

Card_calatorie::Card_calatorie(int id, char tip) :id(id), tip(tip) {};


//functii Card_autobuz

Card_autobuz::Card_autobuz(int id, char tip, int sold, int moment_ultima_validare = 0) : Card_calatorie(id, tip), sold(sold), moment_ultima_validare(moment_ultima_validare) {};

int Card_autobuz::get_sold() { return sold; }

int Card_autobuz::get_moment_ultima_validare() { return moment_ultima_validare; }

void Card_autobuz::set_moment_ultima_validare(int moment_ultima_validare) { this->moment_ultima_validare = moment_ultima_validare; }

void Card_autobuz::set_sold(int sold) { this->sold = sold; }

void Card_autobuz::validare_calatorie(int moment) {
    if ((moment - moment_ultima_validare) >= 90)
    {
        if (sold >= 3)
        {
            moment_ultima_validare = moment;
            sold = sold - 3;
        }
        else
            std::cout << "Sold insuficient\n";
    }
};

void Card_autobuz::incarcare(int a) {};

void Card_autobuz::afisare()
{
    std::cout << get_id() << " " << get_tip() << " " << sold << " " << moment_ultima_validare << "\n";
}

//functii Card_metrou

Card_metrou::Card_metrou(int id, char tip, int nr_calatorii, int moment_ultima_validare = 0) : Card_calatorie(id, tip), nr_calatorii(nr_calatorii), moment_ultima_validare(moment_ultima_validare) {};

int Card_metrou::get_nr_calatorii() { return nr_calatorii; }

int Card_metrou::get_moment_ultima_validare() { return moment_ultima_validare; }

void Card_metrou::validare_calatorie(int moment) {
    if ((moment - moment_ultima_validare) >= 90)
    {
        if (nr_calatorii >= 1)
        {
            moment_ultima_validare = moment;
            nr_calatorii = nr_calatorii - 1;
        }
        else
            std::cout << "Numar calatorii insuficient\n";
    }
}

void Card_metrou::incarcare(int a) {};

void Card_metrou::set_moment_ultima_validare(int moment_ultima_validare) { this->moment_ultima_validare = moment_ultima_validare; }

void Card_metrou::set_nr_calatorii(int nr_calatorii) { this->nr_calatorii = nr_calatorii; }

void Card_metrou::afisare()
{
    std::cout << get_id() << " " << get_tip() << " " << nr_calatorii << " " << moment_ultima_validare << "\n";
}