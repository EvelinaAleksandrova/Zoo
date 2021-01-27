#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int toLower(int c) {
    return std::tolower(c);
}
// The number of animals is determined by the user
// The user should be able to specify the type of animal for the current position
// The user should be able to manually feed or pet all of the animals
// When "Exit" is typed the program should quit

class Animal {
protected:
    int energy = 0;
public:
    Animal() {

    }

    virtual void currentEnergy() {
        cout << "Animal energy:" << endl;
    }

    virtual void sound() {
        cout << "Animal sound" << endl;
    }

    virtual void eat() {
        cout << "Animal eating:" << endl;
    }

    virtual void petAnimal() {
        cout << "Petting animal:" << endl;
    }

    ~Animal() {

    }
};

class Panther : public Animal {
public:
    Panther() {
        energy = 95;
    }

    virtual void currentEnergy() {
        cout << "Panther current energy of Panther: " << energy << endl;
    }

    virtual void sound() {
        cout << "    Panther" << endl;
        cout << "RoaaR" << endl;
    }

    virtual void eat() {
        energy = energy + 28;
        if (energy >= 100) {
            energy = 100;
        }
        cout << "Panther energy after eat: " << energy << endl;
    }

    virtual void petAnimal() override {
        if (energy <= 14) {
            cout << "Panther doesn't have energy to be pet.You should give her food" << endl;
        } else {
            energy = energy - 14;
            cout << "Panther energy after pet: " << energy << endl;
        }
    }

    ~Panther() {

    }
};


class Wolf : public Animal {
public:
    Wolf() {
        energy = 87;
    }

    virtual void currentEnergy() {
        cout << "Wolf current energy of Wolf: " << energy << endl;
    }

    virtual void sound() {
        cout << "Wolf" << endl;
        cout << "AYYYYyy" << endl;
    }

    virtual void eat() {
        energy += 27;
        if(energy >= 100){
            energy = 100;
        }
        cout << "Wolf energy after eat: " << energy << endl;
    }

    virtual void petAnimal() override {
        if (energy <= 14) {
            cout << "Wolf doesn't have energy to be pet.You should give him food" << endl;
        } else {
            energy -= 14;
            cout << "Wolf energy after pet: " << energy << endl;
        }
    }

    ~Wolf() {

    }
};

class Tiger : public Animal {
public:
    Tiger() {
        energy = 69;
    }

    virtual void currentEnergy() {
        cout << "Tiger current energy of Tiger: " << energy << endl;
    }

    virtual void sound() {
        cout << "Tiger" << endl;
        cout << "RRRrrrR" << endl;
    }

    virtual void eat() {
        energy += 28;
        if(energy >= 100){
            energy = 100;
        }
        cout << "Tiger energy after eat: " << energy << endl;
    }

    virtual void petAnimal() override {
        if (energy <= 22) {
            cout << "Tiger doesn't have energy to be pet.You should give him food" << endl;
        } else {
            energy -= 22;
            cout << "Tiger energy after pet: " << energy << endl;
        }
    }

    ~Tiger() {

    }
};

class Snake : public Animal {
public:
    Snake() {
        energy = 100;
    }

    virtual void currentEnergy() {
        cout << "Snake current energy of Snake: " << energy << endl;
    }

    virtual void sound() {
        cout << "     Snake" << endl;
        cout << "SsssSS" << endl;
    }

    virtual void eat() {
        energy += 24;
        if(energy >= 100){
            energy = 100;
        }
        cout << "Snake energy after eat: " << energy << endl;
    }

    virtual void petAnimal() override {
        if (energy <= 18) {
            cout << "Snake doesn't have energy to be pet.You should give her food" << endl;
        } else {
            energy -= 18;
            cout << "Snake energy after pet: " << energy << endl;
        }
    }

    ~Snake() {

    }
};

class Bear : public Animal {
public:
    Bear() {
        energy = 100;
    }

    virtual void currentEnergy() {
        cout << "Bear current energy: " << energy << endl;
    }

    virtual void sound() {
        cout << "Bear" << endl;
        cout << "Gggrrg" << endl;
    }

    virtual void eat() {
        energy += 17;
        if(energy >= 100){
            energy = 100;
        }
        cout << "Bear energy after eat: " << energy << endl;
    }

    virtual void petAnimal() override {
        if (energy <= 34) {
            cout << "Bear doesn't have energy to be pet.You should give her food" << endl;
        } else {
            energy -= 34;
            cout << "Bear energy after pet: " << energy << endl;
        }
    }

    ~Bear() {

    }
};

int main() {
    string nameOfAnimal;

    cout << "Enter number of animal: " << endl;
    int size = 0;
    cin >> size;

    Animal **ptrAnimal = new Animal *[size];

    int i = 0;
    do {
        cout << "Choose name of Animal (Panther, Wolf, Tiger, Snake, Bear )"
                ", then enter exit " << endl;

        cin >> nameOfAnimal;

        std::transform(nameOfAnimal.begin(),
                       nameOfAnimal.end(),
                       nameOfAnimal.begin(), toLower);

        if (nameOfAnimal == "panther") {
            Animal *pantera = new Panther();
            ptrAnimal[i] = pantera;
        }
        if (nameOfAnimal == "wolf") {
            Animal *wolf = new Wolf();
            ptrAnimal[i] = wolf;
        }
        if (nameOfAnimal == "tiger") {
            Animal *tiger = new Tiger();
            ptrAnimal[i] = tiger;
        }
        if (nameOfAnimal == "snake") {
            Animal *snake = new Snake();
            ptrAnimal[i] = snake;
        }
        if (nameOfAnimal == "bear") {
            Animal *bear = new Bear();
            ptrAnimal[i] = bear;
        }
        i++;
    } while (nameOfAnimal != "exit");

    string decision = " ";
    do {
        cout << "That's the current energy for animals" << endl;
        for (int i = 0; i < size; i++) {
            ptrAnimal[i]->currentEnergy();
        }
        cout << "------------------------------------------" << endl;
        cout << "Do you want to Feed animals or Pet them or hear their Sound?" << endl;
        cin >> decision;

        if (decision == "Feed") {
            for (int i = 0; i < size; i++) {
                ptrAnimal[i]->eat();
            }
            cout << "------------------------------------------" << endl;
        }
        if (decision == "Pet") {
            for (int i = 0; i < size; i++) {
                ptrAnimal[i]->petAnimal();
            }
            cout << "------------------------------------------" << endl;
        }
        if (decision == "Sound") {
            for (int i = 0; i < size; i++) {
                ptrAnimal[i]->sound();
            }
            cout << "------------------------------------------" << endl;
        }
    } while (decision != "EXIT");
    return 0;
}