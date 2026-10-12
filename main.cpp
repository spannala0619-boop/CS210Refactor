#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----
    std::cout << std::endl << "== Uno player turn order ==" << std::endl;
    std::unique_ptr<List<Player>> players = makeList<Player>();
    players->addFront(new Player(1, "Srivar"));
    players->addFront(new Player(2, "Akil"));
    players->addFront(new Player(3, "Vasu"));
    players->addFront(new Player(4, "Nik"));

    std::cout << "Starting order:" <<std::endl;
    players->print();

    players->addAnywhere(2, new Player(5, "Emily"));

    std::cout << "After adding Emily:" << std::endl;
    players->print();
    players->deleteAnywhere(1);

    std::cout << "After removing a player:" << std::endl;
    players->print();

    players->reverse();

    std::cout << "After reversing direction:" << std::endl;
    players->print();

    std::unique_ptr<List<Player>> extraPlayers = makeList<Player>();
    extraPlayers->addFront(new Player(6, "Alicia"));
    extraPlayers->addFront(new Player(7, "Roshan"));

    players->concat(extraPlayers.get());

    std::cout << "After adding extra players:" << std::endl;
    players->print();


    return 0;
}
