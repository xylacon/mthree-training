#include "models/Patron.h"
#include "models/Admin.h"
#include "models/Book.h"

#include "service/UserService.h"
#include "service/MediaService.h"

#include <iostream>
#include <memory>

int main() {
	// UserService service("data/users.csv");
	// Patron p("patron", "username", "pass", "Name", "123-456-7890");
	// Admin a("admin", "username", "pass", "Name", 160000.00);

	// service.add(p);
	// service.add(a);

	// MediaService service("data/items.csv");
	// Book b1("book", "Title1", "Author1", "03/01/1998", "hard");
	// Book b2("book", "Title2", "Author2", "08/14/2025", "soft");

	// service.add(b1);
	// service.add(b2);

	/*
		Prompt to log in
		If patron
			1. See all available media
				<numbered list>
				To rent, enter item number
				To go back, enter 'b'
			2. Search
				1. By name
					<numbered list>
					To rent, enter item number
					To go back, enter 'b'
				2. By author
					<numbered list>
					To rent, enter item number
					To go back, enter 'b'
				3. By type
					<numbered list>
					To rent, enter item number
					To go back, enter 'b'
			3. Display rented media
			4. Renew media
				<numbered list>
				To renew, enter item number
				To go back, enter 'b'
			5. Return media
				<numbered list>
				To return, enter item number
				To go back, enter 'b'
			6. Log out
		Else if admin
			1. See all available media
				<numbered list>
			2. Search
				<numbered list>
			3. Add media
			4. Update media
			5. Delete media
			6. Display rented media
			7. Display transactions
			8. Log out
	*/
	
	return 0;
}