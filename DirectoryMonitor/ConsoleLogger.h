#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

// System Includes
#include <iostream>

// Project Includes
#include "IObserver.h"


// //////////////////////////////////////////////////////////////
// Class Definition
// //////////////////////////////////////////////////////////////
class ConsoleLogger : public IObserver
{
public:
    void OnFileAdded(const std::string& filename) override;
    void OnFileRemoved(const std::string& filename) override;
};

#endif // CONSOLELOGGER_H
