#pragma once
#ifndef PERSONA_H
#define PERSONA_H

class Persona{
  private:
    string first_name,last_name,city;
    int id, zip;
  public:
      Persona(int id = 0, int zip = 0, string fname = "", string lname = "", string city = ""){
        this->id = id;
        this->zip = zip;
        this->first_name = fname;
        this->last_name = lname;
        this->city = city;
      }
      bool operator>(const Persona & p){
        return (this -> last_name  < p.last_name);
      }

      bool operator<(const Persona & p){
        return (this -> last_name  < p.last_name);
      }

      string getCity(){
        return city;
      }
      string getLastName(){
        return last_name;
      }
      string getFirstName(){
        return first_name;
      }
      
      friend ostream & operator <<(ostream &, const Persona &);

      bool operator>=(const Persona & p){
        return (this -> last_name  > p.last_name);
      }
       /*bool operator>(const Persona & p){
        return this->last_name.compare(p.last_name) > 0;
      }*/
      bool operator<=(const Persona & p){
        return (this -> last_name  < p.last_name);
      }

/*
Agrega las sobre cargas de operadores necesarias en la clase Persona.
*/
friend ostream & operator <<(ostream &, const Persona &);
};

ostream & operator <<(ostream & salida, const Persona & persona){
  salida << persona.id << " " << persona.zip<<" "<<persona.first_name<<" "<<persona.last_name<<" "<<persona.city;
  return salida;  
};

#endif