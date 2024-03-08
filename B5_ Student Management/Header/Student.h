#ifndef STUDENT.H
#define STUDENT.H

#include <iostream>
#include <stdint.h>
#include <string>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <list>
using namespace std;

typedef enum Gender {
    Male,
    Female
} Gender;

typedef enum Rank {
    Excellent,
    Good,
    Average,
    BelowAverage,
    Weak
} Rank;

class Person {
private:
    string name;
    short int age;
    Gender gender;
    short int ID;
public:
    Person() {
        this->name = "";
        this->age = 0;
        this->gender = Male;
        this->ID = 0;
    }

    ~Person() {}

    void setName(string _name) {
        name = _name;
    }
    string getName() {
        return name;
    }

    void setAge(short int _age) {
        age = _age;
    }
    short int getAge() {
        return age;
    }

    void setGender(Gender _gender) {
        gender = _gender;
    }
    Gender getGender() {
        return gender;
    }

    void setID(short int _ID) {
        ID = _ID;
    }
    short int getID() {
        return ID;
    }

};

class Student : public Person {
private:
    float Math_score;
    float Physic_score;
    float Chemical_score;
    float Average_score;
    Rank rank;

public:
    Student(float _Math_score, float _Physic_score, float _Chemical_score, float _Average_score, Rank _rank) : Person() {
        this->Math_score = 0;
        this->Physic_score = 0;
        this->Chemical_score = Male;
        this->Average_score = 0;
        this->rank = Excellent;
    }

    ~Student() {}

    void setData();
    void getData();

    void setMath(float _Math_score) {
        Math_score = _Math_score;
    }
    float getMath() {
        return Math_score;
    }

    void setPhysic(float _Physic_score) {
        Physic_score = _Physic_score;
    }
    float getPhysic() {
        return Physic_score;
    }

    void setChemical(float _Chemical_score) {
        Math_score = _Chemical_score;
    }
    float getChemical() {
        return Chemical_score;
    }

    float getAverScore() {
        return (Math_score + Physic_score + Chemical_score) / 3;
    }

    Rank getRank(); 
};

#endif
