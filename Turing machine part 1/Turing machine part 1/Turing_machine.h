#ifndef TURING_MACHINE_H
#define TURING_MACHINE_H

#include <string>
#include <fstream>
#include <vector>

class Turing_machine {
private:
    int current_Square = 0;
    std::vector<int> tape{};
    std::vector<std::vector<std::string>> state{};
    int current_State = 1;

public:
    //constructors:
    Turing_machine(std::string tape_file, std::string state_file);
    //functions:
    void move_left();
    void move_right();
    bool read_square();

    void make_mark();

    void remove_mark();

    std::string get_tape();

    long get_current_square();

    void read_tape_file(std::ifstream& file);

    void read_state_file(std::ifstream& file);

    void update();

    void run();
};
#endif