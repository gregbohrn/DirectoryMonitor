// Project Includes
#include "ConsoleLogger.h"


// //////////////////////////////////////////////////////////////
// Public Methods
// //////////////////////////////////////////////////////////////
void ConsoleLogger::OnFileAdded(const std::string& filename)
{
    cout << "File added: " << filename << std::endl;
}

void ConsoleLogger::OnFileRemoved(const std::string& filename) 
{
    cout << "File removed: " << filename << std::endl;
}

