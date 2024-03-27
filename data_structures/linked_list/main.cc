#include "linked_list.h"
#include <string>

std::string to_upper_case(std::string str) {
	for(int i = 0; i < str.size(); ++i) {
		str[i] = std::toupper(str[i]);
	}
	return str;
}

int main(int argc, char* argv[]) {
	
	LinkedList<std::string> list;
//	list.add("American");
//	list.print_list();
//
//	list.add("Canada", 0);
//	list.print_list();
//
//	list.add("Russia");
//	list.print_list();
//
//	list.add("France");
//	list.print_list();
//
//	list.add("Germany", 2);
//	list.print_list();
//
//	list.add("Norway", 5);
//	list.print_list();
//
//	list.add("Netherlands", 0);
//	list.print_list();
//
//	list.remove_at(0);
//	list.print_list();
//
//	list.remove_at(2);
//	list.print_list();
//
//	list.remove_at(list.get_size() - 1);
//	list.print_list();

	list.add("America");	
	list.add("Canada");	
	list.add("Russia");	
	list.add("Franch");	
	
	list.print_list(list);
	std::cout << "\n";

	return 0;
}
