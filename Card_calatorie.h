#ifndef CARD_CALATORIE_H
#define CARD_CALATORIE_H

class Card_calatorie {
private:
    int id;
    char tip;
public:
    virtual void validare_calatorie(int) = 0;
    virtual void incarcare(int) = 0;

    int get_id();
    char get_tip();

    Card_calatorie(int, char);
    virtual void set_moment_ultima_validare(int) {};
    virtual int get_sold() { return 0; };
    virtual int get_nr_calatorii() { return 0; };
    virtual void set_sold(int) {};
    virtual void set_nr_calatorii(int) {};
    virtual void afisare() = 0;

};

class Card_autobuz : public Card_calatorie
{
private:
    int sold;
    int moment_ultima_validare;
public:
    Card_autobuz(int, char, int, int);

    int get_sold();
    int get_moment_ultima_validare();
    void set_moment_ultima_validare(int);

    void set_sold(int);
    void incarcare(int);
    void afisare();
    void validare_calatorie(int);
};

class Card_metrou : public Card_calatorie
{
private:
    int nr_calatorii;
    int moment_ultima_validare;
public:
    Card_metrou(int, char, int, int);

    int get_nr_calatorii();
    int get_moment_ultima_validare();
    void set_moment_ultima_validare(int);

    void set_nr_calatorii(int);
    void incarcare(int);
    void afisare();
    void validare_calatorie(int);


};

#endif