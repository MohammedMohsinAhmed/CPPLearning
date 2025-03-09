#include <string>

// NEVER put using or using namespace in header files
// Header files are designed to be copy pasted into others code, others dont want to use your names necessarily
// using std::string;

class listInit {
private:
	std::string privStr;
public:
	listInit(std::string str);
};