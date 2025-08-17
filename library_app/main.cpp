/*
	Created by Richard Denton
	
	This is a library management system. Management areas include:
	- users (patron, admin)
	- media (book, ebook, audio, video)
	- transactions

	Folder structure
	- /include contains all header files
	- /src contains all implementation files
	- Models, services, and DAOs are contained in their respective folders

	App structure
	- Models implement user-/media-/transaction-specific logic
	- DAOs directly read/write data to/from their respective files
	- Services (should) implement business logic and bridge the gap
	  between the app and the DAOs
	  - Comments in Menu.cpp explain why services aren't currently
	    doing much heavy lifting
	- Menu.cpp contains most of the app logic, and its description can
	  be found there.
	- Data is located in /data. You may provide your own data as long
	  as it is in the same format as the provided files. Simply add
	  your file and change the corresponding name down below in main().
*/

#include "Menu.h"

#include "exceptions/DataImportException.h"

#include <iostream>

int main() {
		const std::string userDataFilename = "data/users.csv";
		const std::string mediaDataFilename = "data/items.csv";
		const std::string transactionDataFilename = "data/transactions.csv";

	try {
		// (<user_data_file>, <media_inventory_data_file>, <transaction_data_file>)
		Menu menu(userDataFilename, mediaDataFilename, transactionDataFilename);
		menu.run();
	} catch (const DataImportException& ex) {
		std::cerr
			<< "Critical error: " << ex.what()
			<< "\nApplication now closing.\n";
		return 1;
	}
	
	return 0;
}