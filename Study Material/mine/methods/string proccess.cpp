void split(const string &s, const char* delim, vector<string> & v) {
	char * dup = strdup(s.c_str());
	char * token = strtok(dup, delim);
	while (token != NULL)
		v.push_back(string(token)), token = strtok(NULL, delim);
	free(dup);
}
/*	example
 vector<string> splited;
 split("{gd},{fd}", " {,}", splited);   splitted { "gd" , "fd" }
 */

bool replace(string& str, const string& from, const string& to) {
	auto start_pos = str.find(from);
	if (start_pos == string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}

string trim(const string& str, const string& whitespace = " \t") {
	const auto strBegin = str.find_first_not_of(whitespace);
	if (strBegin == string::npos)
		return ""; // no content

	const auto strEnd = str.find_last_not_of(whitespace);
	const auto strRange = strEnd - strBegin + 1;

	return str.substr(strBegin, strRange);
}


string reduce(const string& str,
                   const string& fill = " ",
                   const string& whitespace = " \t")
{
    // trim first
    auto result = trim(str, whitespace);

    // replace sub ranges
    auto beginSpace = result.find_first_of(whitespace);
    while (beginSpace != string::npos)
    {
        const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
        const auto range = endSpace - beginSpace;

        result.replace(beginSpace, range, fill);

        const auto newStart = beginSpace + fill.length();
        beginSpace = result.find_first_of(whitespace, newStart);
    }

    return result;
}


/*
 cin >> a;   // a = "            hello      world        "
 while (replace(a, "WUB", " "))
 ;
 cout << reduce(a);  a = "hello world"

 */
