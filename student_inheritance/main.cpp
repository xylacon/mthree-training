#include "Result.h"

int main() {
	// Result student;
	// student.set_number(170672);
	// student.set_marks(78.5f, 89.75f);

	/*
		Since we set Result class inheritance
		to private, we can instead access private methods through a constructor.
	*/
	Result student(170672, 78.5f, 89.75f);
	student.calculate_result();

	return 0;
}