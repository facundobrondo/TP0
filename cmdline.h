#ifndef _CMDLINE_H_INCLUDED_
#define _CMDLINE_H_INCLUDED_

#include <iostream>
#include <string>

#define OPT_DEFAULT   0
#define OPT_SEEN      1
#define OPT_MANDATORY 2

struct option_t {
	int has_arg;
	const char *short_name;
	const char *long_name;
	const char *def_value;
	void (*parse)(std::string const &); 
	int flags;
};

class cmdline {
		option_t *option_table;
		cmdline();
		int do_long_opt(const char *, const char *);
		int do_short_opt(const char *, const char *);
		
	public:
		cmdline(option_t *);
		void parse(int, char * const []);
};

#endif
