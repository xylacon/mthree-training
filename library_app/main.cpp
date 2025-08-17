#include "Menu.h"

#include "exceptions/DataImportException.h"

#include <iostream>

int main() {
	try {
		// (<user_data_file>, <media_inventory_data_file>, <transaction_data_file>)
		Menu menu("data/users.csv", "data/items.csv", "data/transactions.csv");
		menu.run();
	} catch (const DataImportException& ex) {
		std::cerr
			<< "Critical error: " << ex.what()
			<< "\nApplication now closing.\n";
		return 1;
	}
	
	return 0;
}