#include "models/Patron.h"

#include "service/PatronService.h"

#include <iostream>

int main() {
	PatronService ps("data/patrons.csv");

	Patron p("Mobey Dick");

	ps.add_patron(p);

	ps.save_patrons("data/saved_patrons.csv");

	return 0;
}