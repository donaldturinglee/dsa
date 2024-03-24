#include "linked_list.h"
#include <string>

int main(int argc, char* argv[]) {
	
	LinkedList<std::string> list;
	list.add("American");
	list.print_list();

	list.add("Canada", 0);
	list.print_list();

	list.add("Russia");
	list.print_list();

	list.add("France");
	list.print_list();

	list.add("Germany", 2);
	list.print_list();

	list.add("Norway", 5);
	list.print_list();

	list.add("Netherlands", 0);
	list.print_list();

	list.remove_at(0);
	list.print_list();

	list.remove_at(2);
	list.print_list();

	list.remove_at(list.get_size() - 1);
	list.print_list();

	return 0;
}
