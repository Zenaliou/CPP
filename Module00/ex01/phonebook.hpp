#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <cctype>
# include <string>
# include <iostream>
# include <cctype>
# include <string>
# include <unistd.h>
# include <cstdlib>
# include <iomanip>
# include <cstdio>
# include "contact.hpp"

class Phonebook {
	public:
		Phonebook();
		~Phonebook();
		
		void	addContact();
		void	searchContact();
		void	displayContacts();
		void	displayContactDetails(int index);

	private:
		static const int	max = 8;
		Contact				contacts[8];
		int					currentIndex;
		int					totalContacts;
};

#endif